//----------------------------------------
//File Name: Matrix4.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#pragma once
#include "Vector4.h"
#include "Vector3.h"
#include <assert.h>

struct Matrix4
{
	Matrix4();
	Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw);

	Vector4 operator*(Vector4 rhs);
	Matrix4 operator*(Matrix4 rhs);

	Vector4& operator[](int nIndex);
	explicit operator float*();

	void setRotateX(float fRaidians);
	void setRotateY(float fRaidians);
	void setRotateZ(float fRaidians);

	void setPosition(float x, float y, float z);
	void setPosition(Vector3 pos);

	void setScale(float x, float y, float z);
	void setScale(Vector3 pos);

	Vector3 getPosition();
	Vector3 getForwardVector();
	Vector3 getRightVector();
	Vector3 getUpVector();
	Vector3 getScale();

	union
	{
		float m[16];
		Vector4 vec[3];
	};

};
//  +-----------------+	
//  | 0 | 4 |  8 | 12 |	
//  | 1 | 5 |  9 | 13 | 
//  | 2 | 6 | 10 | 14 | 
//  | 3 | 7 | 11 | 15 |	
//  +-----------------+	
