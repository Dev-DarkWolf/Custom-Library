//----------------------------------------
//File Name: Matrix3.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#include <math.h>
#include <assert.h>
#include "Vector3.h"

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