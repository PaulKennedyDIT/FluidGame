#pragma once
#include <glm.hpp>
#include <GL/glew.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include<glm.hpp>
class FluidParticle
{
public:
	FluidParticle(void);
	~FluidParticle(void);

	float ComputeDensity(glm::vec3 position);

	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 force;
	glm::vec3 pressure;
	glm::vec3 color;

	float mass;
	float density;
	float viscosity;
	float size;
	float radius;
};

