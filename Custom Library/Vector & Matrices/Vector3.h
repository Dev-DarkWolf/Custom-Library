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

struct Vector2;
struct Vector4;

#pragma once
struct Vector3
{
	LIBRARY_API Vector3();
	LIBRARY_API Vector3(float x, float y, float z);
	
	LIBRARY_API Vector3 operator+(Vector3 rhs);
	LIBRARY_API Vector3 operator-(Vector3 rhs);
	LIBRARY_API Vector3 operator*(float scalar);
	LIBRARY_API Vector3 operator/(float scalar);

	LIBRARY_API bool operator!=(Vector3 rhs);
	LIBRARY_API bool operator==(Vector3 rhs);
	
	LIBRARY_API float& operator[](int nIndex);
	 
	LIBRARY_API explicit operator float*(); //Cast To Float
	LIBRARY_API explicit operator Vector2*(); //Cast To Vector2
	LIBRARY_API explicit operator Vector4*(); //Cast To Vector4
	
	LIBRARY_API float dot(Vector3 rhs);
	LIBRARY_API Vector3 cross(Vector3 vVector);
	LIBRARY_API float magnitude();
	LIBRARY_API float MagnitudeSquared();
	LIBRARY_API void normalise();

	LIBRARY_API void SetXYZ(float x, float y, float z);
	LIBRARY_API Vector3 Clamp(float fMinAxis, float fMaxAxis);
	LIBRARY_API bool ContainsNaN();
	LIBRARY_API float Distance(Vector3 vVectorToCompare);
	LIBRARY_API Vector3 RoundToVector();
	LIBRARY_API Vector3 Swizzle(char* xyzOrder = "xyz");


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


