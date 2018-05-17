//----------------------------------------
//File Name: Vector3.h
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
struct Vector3
{
	LIBRARY_API Vector3();
	LIBRARY_API Vector3(float x, float y, float z);
	
	LIBRARY_API Vector3 operator+(Vector3 rhs);
	LIBRARY_API Vector3 operator-(Vector3 rhs);
	LIBRARY_API Vector3 operator*(float scalar);
	
	LIBRARY_API float& operator[](int nIndex);
	 
	LIBRARY_API explicit operator float*();
	
	LIBRARY_API float dot(Vector3 rhs);
	LIBRARY_API Vector3 cross(Vector3 vVector);
	LIBRARY_API float magnitude();
	LIBRARY_API void normalise();

	float x;
	float y;
	float z;
};

//------------------------------------------
//  --- Static (Multiplacation) Overide ---
//------------------------------------------
static Vector3 operator*(float fScaylar, Vector3 vVector)
{
	Vector3 vResult;

	vResult.x = vVector.x * fScaylar;
	vResult.y = vVector.y * fScaylar;
	vResult.z = vVector.z * fScaylar;

	return vResult;
}


