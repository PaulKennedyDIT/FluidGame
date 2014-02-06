#include "Viscosity.h"


Viscosity::Viscosity(void)
{
}

Viscosity::Viscosity(float ks)
{
	kernelSize = ks;
	KernelSizeSquared = pow(kernelSize,2);
}



Viscosity::~Viscosity(void)
{

}

void Viscosity::CalculateFactor()
{
	double kernelSizeRad = pow((double)kernelSize,3.0);
	double pi = 3.14159265358979323846264338327950288;
	kernelFactor = 15.0f/(2.0f * pi * kernelSizeRad);
}
float Viscosity::Calculate(glm::vec3 distance)
{
	float len = distance.length();
	float lenpow2 = pow(len,2);
	float epsilon = ldexp(1.192092896,-7);

	if(lenpow2 > KernelSizeSquared)
	{
		return 0.0f;
	}

	if(lenpow2 < epsilon)
	{
		lenpow2 = epsilon;
	}

	float lenSqrt = sqrt(lenpow2);
	float lenpow3 = pow(lenSqrt,3);
	return kernelFactor * (((-lenpow3/(2.0f * kernelSizepow3)) * (lenSqrt/ KernelSizeSquared) + (kernelSize /(2.0f * lenSqrt))) - 1.0f);
}
glm::vec3 Viscosity::CalculateGradient(glm::vec3 distance)
{
	return glm::vec3(0,0,0);
}

float Viscosity::CalculateLaplacian(glm::vec3 distance)
{
	float len = distance.length();
	float lenpow2 = pow(len,2);
	float epsilon = ldexp(1.192092896,-7);

	if(lenpow2 > KernelSizeSquared)
	{
		return 0.0f;
	}

	if(lenpow2 < epsilon)
	{
		lenpow2 = epsilon;
	}

	float lenSqrt = sqrt(lenpow2);
	return kernelFactor * (6.0f/ kernelSizepow3) * (kernelSize - lenpow2);
}
