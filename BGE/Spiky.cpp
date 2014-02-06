#include "Spiky.h"


Spiky::Spiky(void)
{
}

Spiky::Spiky(float ks)
{
	kernelSize = ks;
	KernelSizeSquared = pow(kernelSize,2);
}


Spiky::~Spiky(void)
{
}

void Spiky::CalculateFactor()
{
	double kernelSizeRad = pow((double)kernelSize,6.0);
	double pi = 3.14159265358979323846264338327950288;
	kernelFactor = 15.0f/(pi * kernelSizeRad);
}
float Spiky::Calculate(glm::vec3 distance)
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

	float factor = kernelSize - sqrt(lenpow2);

	return kernelFactor * factor * factor * factor;
}
glm::vec3 Spiky::CalculateGradient(glm::vec3 distance)
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

	float sqrtLen = sqrt(lenpow2);
	float factor = -kernelFactor * 3.0f * (kernelSize - sqrtLen) * (kernelSize - sqrtLen)/ sqrtLen;

	return glm::vec3(distance.x * factor, distance.y * factor, distance.z * factor);
}

float Spiky::CalculateLaplacian(glm::vec3 distance)
{

}

