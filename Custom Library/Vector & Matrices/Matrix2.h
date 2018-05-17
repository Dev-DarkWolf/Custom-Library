//----------------------------------------
//File Name: Matrix2.h
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

struct Matrix2
{
	LIBRARY_API Matrix2();
	LIBRARY_API Matrix2(float Xx, float Xy, float Xz, float Yx);
	
	LIBRARY_API Vector2 operator*(Vector2 rhs);
	LIBRARY_API Matrix2 operator*(Matrix2 rhs);
	
	LIBRARY_API Vector2& operator[](int nIndex);
	LIBRARY_API explicit operator float*();

	LIBRARY_API void setRotate(float fRaidians);

	LIBRARY_API Vector2 getUpVector();
	LIBRARY_API Vector2 getRightVector();

	union
	{
		float m[9];
		Vector2 vec[3];
	};

};

