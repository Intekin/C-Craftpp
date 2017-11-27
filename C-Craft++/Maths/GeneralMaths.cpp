#include "GeneralMaths.h"
#include <iostream>



float smoothStep(float edge0, float edge1, float x)
{
	x = x*x*(3 - 2 * x);

	return (edge0 * x) + (edge1 * (1 - x));
}

float clamp(float x, float lowerlimit, float upperlimit)
{
	if (x < lowerlimit) x = lowerlimit;
	if (x > upperlimit) x = upperlimit;

	return x;
}

float smoothInterpolation(float bottomLeft, float topLeft, float bottomRight, float topRight,
	float xMin, float xMax,
	float zMin, float zMax,
	float x, float z)
{
	float width = xMax - xMin;
	float height = zMax - zMin;

	float xValue = 1 - (x - xMin) / width;
	float zValue = 1 - (z - zMin) / height;

	float a = smoothStep(bottomLeft, bottomRight, xValue);
	float b = smoothStep(topLeft, topRight, xValue);

	return smoothStep(a, b, zValue);
}

float bilinearInterpolation(float bottomLeft, float topLeft, float bottomRight, float topRight,
	float xMin, float xMax,
	float zMin, float zMax,
	float x, float z)
{
	float width = xMax - xMin;
	float height = zMax - zMin;

	float xDistanceToMaxValue = xMax - x;
	float zDistanceToMaxValue = zMax - z;

	float xDistanceToMinValue = x - xMin;
	float zDistanceToMinValue = z - zMin;

	return 1.0f / (width / height) *
		(
			bottomLeft * xDistanceToMaxValue * zDistanceToMaxValue +
			bottomRight * xDistanceToMinValue * zDistanceToMaxValue +
			topLeft * xDistanceToMaxValue * zDistanceToMinValue +
			topRight * xDistanceToMinValue * zDistanceToMinValue
			);
}