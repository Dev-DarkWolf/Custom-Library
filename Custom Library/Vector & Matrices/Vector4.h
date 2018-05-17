//----------------------------------------
//File Name: Vector4.h
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
struct Vector4
{
	LIBRARY_API Vector4();
	LIBRARY_API Vector4(float x, float y, float z, float w);
	
	LIBRARY_API Vector4 operator+(Vector4 rhs);
	LIBRARY_API Vector4 operator-(Vector4 rhs);
	LIBRARY_API Vector4 operator*(float scalar);
	
	LIBRARY_API float& operator[](int nIndex);

	LIBRARY_API explicit operator float*();
	
	LIBRARY_API float dot(Vector4 rhs);
	LIBRARY_API Vector4 cross(Vector4 vVector);
	LIBRARY_API float magnitude();
	LIBRARY_API void normalise();

	float x;
	float y;
	float z;
	float w;
};

//------------------------------------------
//  --- Static (Multiplacation) Overide ---
//------------------------------------------
static Vector4 operator*(float fScaylar, Vector4 vVector)
{
	Vector4 vResult;

	vResult.x = vVector.x * fScaylar;
	vResult.y = vVector.y * fScaylar;
	vResult.z = vVector.z * fScaylar;
	vResult.w = vVector.w * fScaylar;

	return vResult;
}


