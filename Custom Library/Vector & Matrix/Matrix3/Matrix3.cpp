//----------------------------------------
//File Name: Matrix3.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//             MATRIX3
// Holds a 2D object's transform in a 3x3 float
// array. 
//------------------------------------------
//			     3x3 MATRIX
//	  +-----------+	   +--------------+
//	  | 1 | 0 | 0 |	   | Xx | Yx | Tx |
//	  | 0 | 1 | 0 | -> | Xy | Yy | Ty |
//	  | 0 | 0 | 1 |	   | Xz | Yz | Tz |
//	  +-----------+	   +--------------+
//-----------------------------------------
//          
//          		ROTATION
//          +----------------------+
//          | cos(a) | -sin(a) | 0 |
//          | sin(a) |  cos(a) | 0 | 
//          |   0    |    0    | 1 |
//          +----------------------+
//          
//          	    POSITION
//          	 +-----------+
//          	 | 1 | 0 | x |
//          	 | 0 | 1 | y |
//          	 | 0 | 0 | 1 |
//          	 +-----------+
//          
//          		 SCALE
//          	 +-----------+
//          	 | x | 0 | 0 |
//          	 | 0 | y | 0 |
//          	 | 0 | 0 | 1 |
//          	 +-----------+
//------------------------------------------
// http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/objectpool.html
//------------------------------------------
#include "Matrix3.h"
#include <math.h>

//------------------------------------------
//		 --- Default Constructor ---
//------------------------------------------
//				+-----------+
//				| 1 | 0 | 0 |
//				| 0 | 1 | 0 |
//				| 0 | 0 | 1 |
//				+-----------+
//------------------------------------------
Matrix3::Matrix3()
{
	m[0] = 1.0f;	//Xx
	m[1] = 0.0f;	//Xy
	m[2] = 0.0f;	//Xz
					
	m[3] = 0.0f;	//Yx
	m[4] = 1.0f;	//Yy
	m[5] = 0.0f;	//Yz
					
	m[6] = 0.0f;	//Zx
	m[7] = 0.0f;	//Zy
	m[8] = 1.0f;	//Zz
}

//------------------------------------------
//			 --- Constructor ---
//------------------------------------------
//			  +--------------+
//			  | Xx | Yx | Tx |
//			  | Xy | Yy | Ty |
//			  | Xz | Yz | Tz |
//			  +--------------+
//------------------------------------------
Matrix3::Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Tx, float Ty, float Tz)
{
	m[0] = Xx;	//Xx
	m[1] = Xy;	//Xy
	m[2] = Xz;	//Xz

	m[3] = Yx;	//Yx
	m[4] = Yy;	//Yy
	m[5] = Yz;	//Yz

	m[6] = Tx;	//Tx
	m[7] = Ty;	//Ty
	m[8] = Tz;	//Tz
}

//------------------------------------------
//	 --- Matrix (Multiplied By) Vector ---
//------------------------------------------
Vector3 Matrix3::operator*(Vector3 rhs)
{
	Vector3 vResult;

	vResult.x = (m[0] * rhs.x) + (m[3] * rhs.y) + (m[6] * rhs.z);
	vResult.y = (m[1] * rhs.x) + (m[4] * rhs.y) + (m[7] * rhs.z);
	vResult.z = (m[2] * rhs.x) + (m[5] * rhs.y) + (m[8] * rhs.z);

	return vResult;
}

//------------------------------------------
//	 --- Matrix (Multiplied By) Matrix ---
//------------------------------------------
Matrix3 Matrix3::operator*(Matrix3 rhs)
{
	Matrix3 vResult;

	vResult.m[0] = (m[0] * rhs.m[0]) + (m[3] * rhs.m[1]) + (m[6] * rhs.m[2]);
	vResult.m[1] = (m[1] * rhs.m[0]) + (m[4] * rhs.m[1]) + (m[7] * rhs.m[2]);
	vResult.m[2] = (m[2] * rhs.m[0]) + (m[5] * rhs.m[1]) + (m[8] * rhs.m[2]);

	vResult.m[3] = (m[0] * rhs.m[3]) + (m[3] * rhs.m[4]) + (m[6] * rhs.m[5]);
	vResult.m[4] = (m[1] * rhs.m[3]) + (m[4] * rhs.m[4]) + (m[7] * rhs.m[5]);
	vResult.m[5] = (m[2] * rhs.m[3]) + (m[5] * rhs.m[4]) + (m[8] * rhs.m[5]);

	vResult.m[6] = (m[0] * rhs.m[6]) + (m[3] * rhs.m[7]) + (m[6] * rhs.m[8]);
	vResult.m[7] = (m[1] * rhs.m[6]) + (m[4] * rhs.m[7]) + (m[7] * rhs.m[8]);
	vResult.m[8] = (m[2] * rhs.m[6]) + (m[5] * rhs.m[7]) + (m[8] * rhs.m[8]);

	return vResult;
}

//------------------------------------------
//	 ---  ---
//------------------------------------------
Vector3& Matrix3::operator[](int nIndex)
{
	assert(nIndex < 2 || nIndex > 0, "Out Of Bounds: nIndex (0 - 2)");
	return vec[nIndex];
}


Matrix3::operator float*()
{
	return &m[0];
}

//------------------------------------------
//		 --- Set X Rotation ---
//------------------------------------------
//		+----------------------+
//		| 1 |   0    |    0    |
//		| 0 | cos(a) | -sin(a) |
//		| 0 | sin(a) |  cos(a) |
//		+----------------------+
//------------------------------------------
void Matrix3::setRotateX(float fRaidians)
{
	m[4] = cos(fRaidians);
	m[5] = sin(fRaidians);

	m[7] = -sin(fRaidians);
	m[8] = cos(fRaidians);
}

//------------------------------------------
//		 --- Set Y Rotation ---
//------------------------------------------
//		+-----------------------+
//		| cos(a)  | 0 |  sin(a) |
//		|   0     | 0 |    1    |
//		| -sin(a) | 0 |  cos(a) |
//		+-----------------------+
//------------------------------------------
void Matrix3::setRotateY(float fRaidians)
{
	m[0] = cos(fRaidians);
	m[2] = -sin(fRaidians);

	m[6] = sin(fRaidians);
	m[8] = cos(fRaidians);
}

//------------------------------------------
//		 --- Set Z Rotation ---
//------------------------------------------
//		+----------------------+
//		| cos(a) | -sin(a) | 0 |
//		| sin(a) |  cos(a) | 0 |
//		|   0    |    0    | 1 |
//		+----------------------+
//------------------------------------------
void Matrix3::setRotateZ(float fRaidians)
{
	m[0] = cos(fRaidians);
	m[1] = sin(fRaidians);

	m[3] = -sin(fRaidians);
	m[4] = cos(fRaidians);
}

//------------------------------------------
//		 --- Set Position(x,y) ---
//------------------------------------------
//			 +-----------+
//			 | 1 | 0 | x |
//			 | 0 | 1 | y |
//			 | 0 | 0 | 1 |
//			 +-----------+
//------------------------------------------
void Matrix3::setPosition(float x, float y)
{
	m[6] = x;
	m[7] = y;
}

//------------------------------------------
//		--- Set Position(Vector3) ---
//------------------------------------------
//			 +-----------+
//			 | 1 | 0 | x |
//			 | 0 | 1 | y |
//			 | 0 | 0 | 1 |
//			 +-----------+
//------------------------------------------
void Matrix3::setPosition(Vector2 pos)
{
	m[6] = pos.x;
	m[7] = pos.y;
}

//------------------------------------------
//		  --- Set Scale(x,y) ---
//------------------------------------------
//			 +-----------+
//			 | x | 0 | 0 |
//			 | 0 | y | 0 |
//			 | 0 | 0 | 1 |
//			 +-----------+
//------------------------------------------
void Matrix3::setScale(float x, float y)
{
	m[0] = x;
	m[4] = y;
}

//------------------------------------------
//		  --- Set Scale(Vector2) ---
//------------------------------------------
//			 +-----------+
//			 | x | 0 | 0 |
//			 | 0 | y | 0 |
//			 | 0 | 0 | 1 |
//			 +-----------+
//------------------------------------------
void Matrix3::setScale(Vector2 pos)
{
	m[0] = pos.x;
	m[4] = pos.y;
}

//------------------------------------------
//			--- Get Position ---
//------------------------------------------
Vector2 Matrix3::getPosition()
{
	Vector2 vResult;

	vResult.x = m[6];
	vResult.y = m[7];

	return vResult;
}

//------------------------------------------
//		  --- Get Facing Vector ---
//------------------------------------------
Vector2 Matrix3::getUpVector()
{
	Vector2 vResult;

	vResult.x = m[3];
	vResult.y = m[4];

	return vResult;
}

//------------------------------------------
//		  --- Get Right Vector ---
//------------------------------------------
Vector2 Matrix3::getRightVector()
{
	Vector2 vResult;

	vResult.x = m[0];
	vResult.y = m[1];

	return vResult;
}

//------------------------------------------
//		  --- Get Scale Vector ---
//------------------------------------------
Vector2 Matrix3::getScale()
{
	Vector2 vResult;

	vResult.x = m[0];
	vResult.y = m[4];

	return vResult;
}

