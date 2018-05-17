//----------------------------------------
//File Name: Matrix3.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#include <math.h>
#include <assert.h>
#include "Vector2.h"

//------------------------------------------
//		--- Default Constructor ---
//------------------------------------------
Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

//------------------------------------------
//		   --- Constructor ---
//------------------------------------------
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

//------------------------------------------
//		--- Vector (Plus) Vector ---
//------------------------------------------
Vector2 Vector2::operator+(Vector2 rhs)
{
	Vector2 vResult;
	vResult.x = this->x + rhs.x;
	vResult.y = this->y + rhs.y;

	return vResult;
}

//------------------------------------------
//		--- Vector (Minus) Vector ---
//------------------------------------------
Vector2 Vector2::operator-(Vector2 rhs)
{
	Vector2 vResult;
	vResult.x = this->x - rhs.x;
	vResult.y = this->y - rhs.y;

	return vResult;
}

//------------------------------------------
//	  --- Vector (Multiplied By) Vector ---
//------------------------------------------
Vector2 Vector2::operator*(float scalar)
{
	Vector2 vResult;
	vResult.x = this->x * scalar;
	vResult.y = this->y * scalar;

	return vResult;
}

//------------------------------------------
//	 ---  ---
//------------------------------------------
float& Vector2::operator[](int nIndex)
{
	return ((float*)this)[nIndex];
}

//------------------------------------------
//				--- Cast ---
//------------------------------------------
Vector2::operator float*()
{
	return &x;
}

//------------------------------------------
//		  --- Get Dot Product ---
//------------------------------------------
float Vector2::dot(Vector2 rhs)
{
	return ((x * rhs.x) + (y * rhs.y));
}

//------------------------------------------
//		   --- Get Magnitude ---
//------------------------------------------
float Vector2::magnitude()
{
	return sqrtf((x*x) + (y*y));
}

//------------------------------------------
//		   --- Normalize Vector ---
//------------------------------------------
void Vector2::normalise()
{
	float fMagnitude = magnitude();
	x /= fMagnitude;
	y /= fMagnitude;
}