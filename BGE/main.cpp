#include<sdl.h>
#include <windows.h>
#include <GL/glew.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include<glm.hpp>
#include "Game.h"
#include "TriangleTest.h"
#include "TexturedCube.h"
#include "CubeTest.h"
#include "PhysicsGame1.h"
#include "VRGame.h"
#include "ModelTest.h"
#include "SteeringGame.h"
#include "SceneGraphGame.h"
#include "Lab5.h"
#include "Lab4.h"
#include "FluidGame.h"

using namespace BGE;

int main(int argc, char *argv[])
{
	FluidGame game;


	game.Run();

	return 0;
}