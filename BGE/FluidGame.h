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
		bool Initialise();
		void Update(float timeDelta);
	};
}

