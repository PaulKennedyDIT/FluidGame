#include "Poly6.h"


Poly6::Poly6(void)
{
}

Poly6::Poly6(float ks)
{
	kernelSize = ks;
	KernelSizeSquared = pow(kernelSize,2);
}

Poly6::~Poly6(void)
{
}

void Poly6::CalculateFactor()
{
	double kernelSizeRad = pow((double)kernelSize,9.0);
	double pi = 3.14159265358979323846264338327950288;
	kernelFactor = 315.0f/(64.0f * pi * kernelSizeRad);
}
float Poly6::Calculate(glm::vec3 distance)
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

	float diff = KernelSizeSquared - lenpow2;
	return kernelFactor * diff * diff * diff;
}
glm::vec3 Poly6::CalculateGradient(glm::vec3 distance)
{
	
	float len = distance.length();
	float lenpow2 = pow(len,2);
	float epsilon = ldexp(1.192092896,-7);

	if(lenpow2 > KernelSizeSquared)
	{
		return glm::vec3(0,0,0);
	}

	if(lenpow2 < epsilon)
	{
		lenpow2 = epsilon;
	}

	float diff = KernelSizeSquared - lenpow2;
	float factor = -kernelFactor * 6.0f * diff * diff;

	return glm::vec3(distance.x * factor, distance.y * factor, distance.z * factor);
}

float Poly6::CalculateLaplacian(glm::vec3 distance)
{
	return 0.0f;
}
