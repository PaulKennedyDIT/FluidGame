#pragma once

#include "SmoothingKernel.h"
class Viscosity : public SmoothingKernel
{
public:
	Viscosity(void);
	Viscosity(float ks);
	~Viscosity(void);

	void CalculateFactor();
	float Calculate(glm::vec3 distance);
	glm::vec3 CalculateGradient(glm::vec3 distance);
	float CalculateLaplacian(glm::vec3 distance);
};

