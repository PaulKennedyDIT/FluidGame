#pragma once
#include "SmoothingKernel.h"

class Spiky: public SmoothingKernel
{
public:
	Spiky(void);
	Spiky(float ks);
	~Spiky(void);

	void CalculateFactor();
	float Calculate(glm::vec3 distance);
	glm::vec3 CalculateGradient(glm::vec3 distance);
	float CalculateLaplacian(glm::vec3 distance);

};
