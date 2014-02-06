#pragma once

#include <glm.hpp>

class SmoothingKernel
{
public:
	SmoothingKernel(void);
	SmoothingKernel(float ks);
	~SmoothingKernel(void);

	float kernelFactor;
	float kernelSize;
	float KernelSizeSquared;
	float kernelSizepow3;
private:
	void CalculateFactor();
	float Calculate(glm::vec3 distance);
	glm::vec3 CalculateGradient(glm::vec3 distance);
	float CalculateLaplacian(glm::vec3 distance);
};

