//----------------------------------------
//File Name: Matrix4.cpp
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
#include "Vector4.h"
#include "Vector3.h"
#include <assert.h>

struct Matrix4
{
	LIBRARY_API Matrix4();
	LIBRARY_API Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw);

	LIBRARY_API Vector4 operator*(Vector4 rhs);
	LIBRARY_API Matrix4 operator*(Matrix4 rhs);

	LIBRARY_API Vector4& operator[](int nIndex);
	LIBRARY_API explicit operator float*();

	LIBRARY_API void setRotateX(float fRaidians);
	LIBRARY_API void setRotateY(float fRaidians);
	LIBRARY_API void setRotateZ(float fRaidians);
	
	LIBRARY_API void setPosition(float x, float y, float z);
	LIBRARY_API void setPosition(Vector3 pos);
	 
	LIBRARY_API void setScale(float x, float y, float z);
	LIBRARY_API void setScale(Vector3 pos);

	LIBRARY_API Vector3 getPosition();
	LIBRARY_API Vector3 getForwardVector();
	LIBRARY_API Vector3 getRightVector();
	LIBRARY_API Vector3 getUpVector();
	LIBRARY_API Vector3 getScale();

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
