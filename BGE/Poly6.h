#pragma once
#include "SmoothingKernel.h"
#include <GL\GL.h>
#include <math.h>


class Poly6 : public SmoothingKernel
{
public:
	Poly6(void);
	Poly6(float ks);
	~Poly6(void);

	void CalculateFactor();
	float Calculate(glm::vec3 distance);
	glm::vec3 CalculateGradient(glm::vec3 distance);
	float CalculateLaplacian(glm::vec3 distance);

};

