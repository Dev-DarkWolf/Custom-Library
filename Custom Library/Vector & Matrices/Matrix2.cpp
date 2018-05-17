//----------------------------------------
//File Name: Matrix2.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//             Matrix2
// Holds a 2D object's transform in a 3x3 float
// array. 
//------------------------------------------
//			     2x2 MATRIX
//			+-------+	 +---------+
//			| 1 | 0 | -> | Xx | Yx | 
//			| 0 | 1 | -> | Xy | Yy | 
//		    +-------+	 +---------+
//-----------------------------------------
//          
//------------------------------------------
// http://
//------------------------------------------
#include "Matrix2.h"
#include <math.h>

//------------------------------------------
//		 --- Default Constructor ---
//------------------------------------------
//				+-------+
//				| 1 | 0 |
//				| 0 | 1 |
//				+-------+
//------------------------------------------
Matrix2::Matrix2()
{
	m[0] = 1.0f;	//Xx
	m[1] = 0.0f;	//Xy

	m[2] = 0.0f;	//Yx
	m[3] = 0.0f;	//Yy
}

//------------------------------------------
//			 --- Constructor ---
//------------------------------------------
//			    +---------+
//			    | Xx | Yx |
//			    | Xy | Yy |
//			    +---------+
//------------------------------------------
Matrix2::Matrix2(float Xx, float Xy, float Yx, float Yy)
{
	m[0] = Xx;	//Xx
	m[1] = Xy;	//Xy

	m[2] = Yx;	//Xz
	m[3] = Yy;	//Yx
}

//------------------------------------------
//	 --- Matrix (Multiplied By) Vector ---
//------------------------------------------
Vector2 Matrix2::operator*(Vector2 rhs)
{
	Vector2 vResult;

	vResult.x = (m[0] * rhs.x) + (m[2] * rhs.y);
	vResult.y = (m[1] * rhs.x) + (m[3] * rhs.y);

	return vResult;
}

//------------------------------------------
//	 --- Matrix (Multiplied By) Matrix ---
//------------------------------------------
Matrix2 Matrix2::operator*(Matrix2 rhs)
{
	Matrix2 vResult;

	vResult.m[0] = (m[0] * rhs.m[0]) + (m[2] * rhs.m[1]);
	vResult.m[1] = (m[1] * rhs.m[0]) + (m[3] * rhs.m[1]);

	vResult.m[2] = (m[0] * rhs.m[2]) + (m[2] * rhs.m[3]);
	vResult.m[3] = (m[1] * rhs.m[2]) + (m[3] * rhs.m[3]);

	return vResult;
}

//------------------------------------------
//	 ---  ---
//------------------------------------------
Vector2& Matrix2::operator[](int nIndex)
{
	assert(nIndex < 1 || nIndex > 0, "Out Of Bounds: nIndex (0 - 1)");
	return vec[nIndex];
}


Matrix2::operator float*()
{
	return &m[0];
}

//------------------------------------------
//		 --- Set Rotation ---
//------------------------------------------
//		
//------------------------------------------
void Matrix2::setRotate(float fRaidians)
{
	m[0] = cos(fRaidians);
	m[1] = sin(fRaidians);

	m[2] = -sin(fRaidians);
	m[3] = cos(fRaidians);
}

//------------------------------------------
//		  --- Get Facing Vector ---
//------------------------------------------
Vector2 Matrix2::getUpVector()
{
	Vector2 vResult;

	vResult.x = m[2];
	vResult.y = m[3];

	return vResult;
}

//------------------------------------------
//		  --- Get Right Vector ---
//------------------------------------------
Vector2 Matrix2::getRightVector()
{
	Vector2 vResult;

	vResult.x = m[0];
	vResult.y = m[1];

	return vResult;
}
