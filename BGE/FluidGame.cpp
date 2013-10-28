#include "FluidGame.h"
#include "Content.h"
#include "VectorDrawer.h"
#include "LazerBeam.h"

using namespace BGE;

FluidGame::FluidGame(void)
{
	elapsed = 10000;
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
	width = 800;
	height = 600;

	Game::Initialise();

	camera->GetController()->position = glm::vec3(0, 4, 20);
	return true;
}

void FluidGame::Update(float timeDelta)
{
	Game::Update(timeDelta);
}

