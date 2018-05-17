//----------------------------------------
//File Name: Matrix3.h
//Author: Trent Manks
//------------------------------------------
#ifdef STATIC
	#define LIBRARY_API //Static Library
#else
	#ifdef DLL
		#define LIBRARY_API	__declspec(dllexport) //DLL Export
	#else
		#define LIBRARY_API __declspec(dllimport) //Dll Import
	#endif // DLL
#endif
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include <assert.h>


struct Matrix3
{
	LIBRARY_API Matrix3();
	LIBRARY_API Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);
	
	LIBRARY_API Vector3 operator*(Vector3 rhs);
	LIBRARY_API Matrix3 operator*(Matrix3 rhs);
	
	LIBRARY_API Vector3& operator[](int nIndex);
	LIBRARY_API explicit operator float*();
	
	LIBRARY_API void setRotateX(float fRaidians);
	LIBRARY_API void setRotateY(float fRaidians);
	LIBRARY_API void setRotateZ(float fRaidians);
	
	LIBRARY_API void setPosition(float x, float y);
	LIBRARY_API void setPosition(Vector2 pos);

	LIBRARY_API void setScale(float x, float y);
	LIBRARY_API void setScale(Vector2 pos);

	LIBRARY_API Vector2 getPosition();
	LIBRARY_API Vector2 getUpVector();
	LIBRARY_API Vector2 getRightVector();
	LIBRARY_API Vector2 getScale();

	union
	{
		float m[9];
		Vector3 vec[3];
	};
	
};

