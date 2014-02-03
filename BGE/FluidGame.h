#pragma once
#include "Game.h"
#include "GameComponent.h"
#include "PhysicsFactory.h"

using namespace std;

namespace BGE
{
	class FluidGame :
		public Game
	{

		private:
		btBroadphaseInterface* broadphase;
 
		// Set up the collision configuration and dispatcher
		btDefaultCollisionConfiguration * collisionConfiguration;
		btCollisionDispatcher * dispatcher;
 
		// The actual physics solver
		btSequentialImpulseConstraintSolver * solver;

	public:
		FluidGame(void);
		~FluidGame(void);

		float elapsed;
		float fluidDensity;
		float containerVolume;
		float mass;

		int numberOfParticles;

		glm::vec3 gravity;
		glm::vec3 container;
		
		
		std::shared_ptr<PhysicsFactory> physicsFactory;
		btDiscreteDynamicsWorld * dynamicsWorld;

		bool Initialise();
		void Update(float timeDelta);
		float calculateVolume(glm::vec3 container);
		float calculateMass(float fluidDensity,float containerVolume,int numberOfParticles);

		double WPoly6(double h);
		double WSpiky(double h);
		double WVisocity(double h);
		double LapSquaredW(double h);
	};
}

