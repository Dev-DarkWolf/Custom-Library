//----------------------------------------
//File Name: Vector2.h
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
struct Vector2
{
	LIBRARY_API Vector2();
	LIBRARY_API Vector2(float x, float y);
	 
	LIBRARY_API Vector2 operator+(Vector2 rhs);
	LIBRARY_API Vector2 operator-(Vector2 rhs);
	LIBRARY_API Vector2 operator*(float scalar);
	 
	LIBRARY_API float& operator[](int nIndex);
	 
	LIBRARY_API explicit operator float*();
	
	LIBRARY_API float dot(Vector2 rhs);
 
	LIBRARY_API float magnitude();
	LIBRARY_API void normalise();

	float x;
	float y;
};

//------------------------------------------
//  --- Static (Multiplacation) Overide ---
//------------------------------------------
 static Vector2 operator*(float scalar, Vector2 vec)
{
	Vector2 vResult;
	vResult.x = vec.x * scalar;
	vResult.y = vec.y * scalar;

	return vResult;
}


