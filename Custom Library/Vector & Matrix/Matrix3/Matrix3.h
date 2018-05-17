//----------------------------------------
//File Name: Matrix3.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------
#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include <assert.h>

struct Matrix3
{
	Matrix3();
	Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);

	Vector3 operator*(Vector3 rhs);
	Matrix3 operator*(Matrix3 rhs);

	Vector3& operator[](int nIndex);
	explicit operator float*();

	void setRotateX(float fRaidians);
	void setRotateY(float fRaidians);
	void setRotateZ(float fRaidians);

	void setPosition(float x, float y);
	void setPosition(Vector2 pos);

	void setScale(float x, float y);
	void setScale(Vector2 pos);

	Vector2 getPosition();
	Vector2 getUpVector();
	Vector2 getRightVector();
	Vector2 getScale();

	union
	{
		float m[9];
		Vector3 vec[3];
	};
	
};

