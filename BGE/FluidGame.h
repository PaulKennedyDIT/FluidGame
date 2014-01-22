#pragma once
#include "Game.h"
#include "GameComponent.h"

using namespace std;

namespace BGE
{
	class FluidGame :
		public Game
	{
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

