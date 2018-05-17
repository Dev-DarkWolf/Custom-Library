//----------------------------------------
//File Name: Matrix2.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------
#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include <assert.h>

struct Matrix2
{
	Matrix2();
	Matrix2(float Xx, float Xy, float Xz, float Yx);

	Vector2 operator*(Vector2 rhs);
	Matrix2 operator*(Matrix2 rhs);

	Vector2& operator[](int nIndex);
	explicit operator float*();

	void setRotate(float fRaidians);

	Vector2 getUpVector();
	Vector2 getRightVector();

	union
	{
		float m[9];
		Vector2 vec[3];
	};

};

