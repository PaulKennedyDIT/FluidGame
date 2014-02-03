#include "FluidGame.h"
#include "Content.h"
#include "VectorDrawer.h"
#include "LazerBeam.h"
#include "Sphere.h"
#include<string>

using namespace BGE;

FluidGame::FluidGame(void)
{

	physicsFactory = NULL;
	dynamicsWorld = NULL;
	broadphase = NULL;
	dispatcher = NULL;
	solver = NULL;

	elapsed = 10000;
	gravity = glm::vec3(0,-9.8,0);
	container = glm::vec3(10,10,10);
	containerVolume = calculateVolume(container);
	numberOfParticles = 1000;
	fluidDensity = 1000.0f;
	mass = calculateMass(fluidDensity,containerVolume,numberOfParticles);
}


FluidGame::~FluidGame(void)
{
}

bool FluidGame::Initialise()
{
		// Set up the collision configuration and dispatcher
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);

    // Sets up the world.Adds the solver
	//Instansiates a dynamic world for the Bullet physixs engine. 
	//Sets the value for gravity. gravity
	btVector3 worldMin(-1000,-1000,-1000);
	btVector3 worldMax(1000,1000,1000);
	broadphase = new btAxisSweep3(worldMin,worldMax);
	solver = new btSequentialImpulseConstraintSolver();
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0,-9,0));

	// Physics Factory is defined. 
	//The Dynamic World setup for Bullet Physics is passed into the Physics Factory.
	physicsFactory = make_shared<PhysicsFactory>(dynamicsWorld);

	// Ground is initialised. 
	// Includes Ground Physics for Bullet as well as texture loading for the rendering.
	physicsFactory->CreateGroundPhysics();

	// Camera is instansiated as a kinematic object. 
	// Camera can manipulate a scene. 
	// Collisions do not effect the camera
	physicsFactory->CreateCameraPhysics();

	riftEnabled = false;
	fullscreen = false;
	width = 1600;
	height = 700;

	shared_ptr<PhysicsController> wallA = physicsFactory->CreateContainerWall(5, 10, 20, glm::vec3(10,4,0), glm::quat());
	shared_ptr<PhysicsController> wallB = physicsFactory->CreateContainerWall(5, 10, 20, glm::vec3(-10,4,0), glm::quat());
	shared_ptr<PhysicsController> wallC = physicsFactory->CreateContainerWall(20, 10, 5, glm::vec3(0,4,10), glm::quat());
	shared_ptr<PhysicsController> wallD = physicsFactory->CreateContainerWall(20, 10, 5, glm::vec3(0,4,-10), glm::quat());

	for (int m = 0; m < 10 ; m++)
	{
		for( int i = 0; i < 5; i++)
		{
			physicsFactory->CreateSphere(1.0f,glm::vec3(i,0,i),glm::quat());
		}
	}

	Game::Initialise();
	
	camera->GetController()->position = glm::vec3(0, 30, 20);
	return true;
}

void FluidGame::Update(float timeDelta)
{
	dynamicsWorld->stepSimulation(timeDelta,200);
	Game::Update(timeDelta);
}

float FluidGame::calculateVolume(glm::vec3 container)
{
	return container.x * container.y * container.z;
}

float FluidGame:: calculateMass(float fluidDensity,float containerVolume,int numberOfParticles)
{
	return (fluidDensity * containerVolume)/(numberOfParticles);
}