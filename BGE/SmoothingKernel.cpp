#include "SmoothingKernel.h"


SmoothingKernel::SmoothingKernel(void)
{
		kernelFactor = 1.0f;
		kernelSize   = 1.0f;
}

SmoothingKernel::SmoothingKernel(float ks)
{
		kernelFactor = 1.0f;
		kernelSize   = ks;
		KernelSizeSquared = pow(kernelSize,2);
}


SmoothingKernel::~SmoothingKernel(void)
{

}

void SmoothingKernel::CalculateFactor()
{

}
float SmoothingKernel::Calculate(glm::vec3 distance)
{

}
glm::vec3 SmoothingKernel::CalculateGradient(glm::vec3 distance)
{

}

float SmoothingKernel::CalculateLaplacian(glm::vec3 distance)
{

}

