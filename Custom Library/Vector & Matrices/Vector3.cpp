//----------------------------------------
//File Name: Matrix3.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#include <math.h>
#include <string>
#include <assert.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

//------------------------------------------
//		--- Default Constructor ---
//------------------------------------------
Vector3::Vector3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

//------------------------------------------
//		   --- Constructor ---
//------------------------------------------
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

//------------------------------------------
//		--- Vector (Plus) Vector ---
//------------------------------------------
Vector3 Vector3::operator+(Vector3 rhs)
{
	Vector3 vResult;
	vResult.x = this->x + rhs.x;
	vResult.y = this->y + rhs.y;
	vResult.z = this->z + rhs.z;

	return vResult;
}

//------------------------------------------
//		--- Vector (Minus) Vector ---
//------------------------------------------
Vector3 Vector3::operator-(Vector3 rhs)
{
	Vector3 vResult;
	vResult.x = this->x - rhs.x;
	vResult.y = this->y - rhs.y;
	vResult.z = this->z - rhs.z;

	return vResult;
}

//------------------------------------------
//	  --- Vector (Multiplied By) Vector ---
//------------------------------------------
Vector3 Vector3::operator*(float scalar)
{
	Vector3 vResult;
	vResult.x = this->x * scalar;
	vResult.y = this->y * scalar;
	vResult.z = this->z * scalar;

	return vResult;
}

 Vector3 Vector3::operator/(float scalar)
{
	 Vector3 vResult;
	 vResult.x = this->x / scalar;
	 vResult.y = this->y / scalar;
	 vResult.z = this->z / scalar;

	 return vResult;
}

bool Vector3::operator!=(Vector3 rhs)
{
	return ((this->x != rhs.x) && (this->y != rhs.y) && (this->z != rhs.z));
}

bool Vector3::operator==(Vector3 rhs)
{
	return ((this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z));
}

//------------------------------------------
//	 ---  ---
//------------------------------------------
float& Vector3::operator[](int nIndex)
{
	return ((float*)this)[nIndex];
}

//------------------------------------------
//				--- Cast ---
//------------------------------------------
Vector3::operator float*()
{
	return &x;
}

//------------------------------------------
//				--- Cast ---
//------------------------------------------
Vector3::operator Vector2*()
{
	Vector2 vResult;
	vResult.x = x;
	vResult.y = y;

	return &vResult;
}

//------------------------------------------
//				--- Cast ---
//------------------------------------------
Vector3::operator Vector4*()
{
	Vector4 vResult;
	vResult.x = x;
	vResult.y = y;
	vResult.z = z;
	vResult.w = 0;

	return &vResult;
}
//------------------------------------------
//		  --- Get Dot Product ---
//------------------------------------------
float Vector3::dot(Vector3 rhs)
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
}

Vector3 Vector3::cross(Vector3 vVector)
{
	Vector3 vResult;

	vResult.x = (y*vVector.z) - (z*vVector.y);
	vResult.y = (z*vVector.x) - (x*vVector.z);
	vResult.z = (x*vVector.y) - (y*vVector.x);

	return vResult;
}

//------------------------------------------
//		   --- Get Magnitude ---
//------------------------------------------
float Vector3::magnitude()
{
	return sqrtf((x*x) + (y*y) + (z*z));
}

float Vector3::MagnitudeSquared()
{
	return ((x*x) + (y*y) + (z*z));
}

//------------------------------------------
//		   --- Normalize Vector ---
//------------------------------------------
void Vector3::normalise()
{
	float fMagnitude = magnitude();
	x /= fMagnitude;
	y /= fMagnitude;
	z /= fMagnitude;
}

void Vector3::SetXYZ(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::Clamp(float fMinAxis, float fMaxAxis)
{
	Vector3 vClamped(x,y,z);
	if (vClamped.magnitude() > fMaxAxis)
	{
		vClamped.normalise();
		vClamped * fMaxAxis;
	}
	else if (vClamped.magnitude() < fMinAxis)
	{
		vClamped.normalise();
		vClamped / fMaxAxis;
	}
	
	return  vClamped;
}

 bool Vector3::ContainsNaN()
{
	return ((x != x) && (y != y) && (z != z));
}

float Vector3::Distance(Vector3 vVectorToCompare)
{
	Vector3 vDistance;
	vDistance.x = x - vVectorToCompare.x;
	vDistance.y = y - vVectorToCompare.y;
	vDistance.z = z - vVectorToCompare.z;

	return sqrt((vDistance.x*vDistance.x) + (vDistance.y*vDistance.y) + (vDistance.z*vDistance.z));
}

Vector3 Vector3::RoundToVector()
{
	Vector3 vResult;
	vResult.x = roundf(x);
	vResult.y = roundf(y);
	vResult.z = roundf(z);
	return vResult;
}

Vector3 Vector3::Swizzle(char * xyzOrder)
{
	Vector3 vSwizzled;
	for (int i = 0; i < 2; i++)
	{
		if(xyzOrder[i] == 'x' || xyzOrder[i] == 'X' || xyzOrder[i] == 'r' || xyzOrder[i] == 'r')
	}
	return );
}
