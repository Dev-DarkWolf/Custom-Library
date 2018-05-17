//----------------------------------------
//File Name: Matrix3.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#include <math.h>
#include <assert.h>
#include "Vector4.h"

//------------------------------------------
//		--- Default Constructor ---
//------------------------------------------
Vector4::Vector4()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

//------------------------------------------
//		   --- Constructor ---
//------------------------------------------
Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

//------------------------------------------
//		--- Vector (Plus) Vector ---
//------------------------------------------
Vector4 Vector4::operator+(Vector4 rhs)
{
	Vector4 vResult;
	vResult.x = this->x + rhs.x;
	vResult.y = this->y + rhs.y;
	vResult.z = this->z + rhs.z;
	vResult.w = this->w + rhs.w;

	return vResult;
}

//------------------------------------------
//		--- Vector (Minus) Vector ---
//------------------------------------------
Vector4 Vector4::operator-(Vector4 rhs)
{
	Vector4 vResult;
	vResult.x = this->x - rhs.x;
	vResult.y = this->y - rhs.y;
	vResult.z = this->z - rhs.z;
	vResult.w = this->w - rhs.w;

	return vResult;
}

//------------------------------------------
//	  --- Vector (Multiplied By) Vector ---
//------------------------------------------
Vector4 Vector4::operator*(float scalar)
{
	Vector4 vResult;
	vResult.x = this->x * scalar;
	vResult.y = this->y * scalar;
	vResult.z = this->z * scalar;
	vResult.w = this->w * scalar;

	return vResult;
}

//------------------------------------------
//	 ---  ---
//------------------------------------------
float& Vector4::operator[](int nIndex)
{
	return ((float*)this)[nIndex];
}

//------------------------------------------
//				--- Cast ---
//------------------------------------------
Vector4::operator float*()
{
	return &x;
}

//------------------------------------------
//		  --- Get Dot Product ---
//------------------------------------------
float Vector4::dot(Vector4 rhs)
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w));
}

Vector4 Vector4::cross(Vector4 vVector)
{
	Vector4 vResult;

	vResult.x = (y*vVector.z) - (z*vVector.y);
	vResult.y = (z*vVector.x) - (x*vVector.z);
	vResult.z = (x*vVector.y) - (y*vVector.x);
	vResult.w = 0;

	return vResult;
}

//------------------------------------------
//		   --- Get Magnitude ---
//------------------------------------------
float Vector4::magnitude()
{
	return sqrtf((x*x) + (y*y) + (z*z) + (w*w));
}

//------------------------------------------
//		   --- Normalize Vector ---
//------------------------------------------
void Vector4::normalise()
{
	float fMagnitude = magnitude();
	x /= fMagnitude;
	y /= fMagnitude;
	z /= fMagnitude;
	w /= fMagnitude;
}