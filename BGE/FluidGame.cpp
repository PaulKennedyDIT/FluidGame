#include "FluidGame.h"
#include "Content.h"
#include "VectorDrawer.h"
#include "LazerBeam.h"
#include<string>

using namespace BGE;

FluidGame::FluidGame(void)
{
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
	std::shared_ptr<GameComponent> ground = make_shared<Ground>();
	Attach(ground);	

	riftEnabled = false;
	fullscreen = false;
	width = 1600;
	height = 700;

	Game::Initialise();

	camera->GetController()->position = glm::vec3(0, 4, 20);
	return true;
}

void FluidGame::Update(float timeDelta)
{
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

double FluidGame::WPoly6(double h)
{
	return 315.0f/(64.0f * glm::pi<float>() * pow(h,9));
}

double FluidGame::WSpiky(double h)
{
	return 15.0f/(2 * glm::pi<double>() * pow(h,6));
}

double FluidGame::WVisocity(double h)
{
	return 15.0f/(2 * glm::pi<double>() * pow(h,3));
}

double FluidGame::LapSquaredW(double h)
{
	return 45.0f/(glm::pi<double>() * pow(h,6));
}
