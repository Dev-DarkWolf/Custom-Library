//----------------------------------------
//File Name: Matrix4.cpp
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//             Matrix4
// Holds a 2D object's transform in a 3x3 float
// array. 
//------------------------------------------
//				 4x4 MATRIX
//  +-----------------+	   +---------------+	+-------------------+
//  | 0 | 4 |  8 | 12 |	   | 1 | 0 | 0 | 0 |    | Xx | Yx | Zx | Tx |
//  | 1 | 5 |  9 | 13 | -> | 0 | 1 | 0 | 0 | -> | Xy | Yy | Zy | Ty |
//  | 2 | 6 | 10 | 14 | -> | 0 | 0 | 1 | 0 | -> | Xz | Yz | Zz | Tz |
//  | 3 | 7 | 11 | 15 |	   | 0 | 0 | 0 | 1 |	| Xw | Yw | Zw | Tw |
//  +-----------------+	   +---------------+	+-------------------+
//-----------------------------------------
//          
//  	   X ROTATION       	      Y ROTATION        	    Z ROTATION
//  +----------------------+    +----------------------+	+----------------------+
//  | 1 |  0   |   0   | 0 |	| cos(a)| 0 |sin(a)| 0 |	|cos(a)|-sin(a)| 0 | 0 |
//  | 0 |cos(a)|-sin(a)| 0 | -> |   0   | 0 |  1   | 0 | -> |sin(a)| cos(a)| 0 | 0 |
//  | 0 |sin(a)| cos(a)| 0 | -> |-sin(a)| 0 |cos(a)| 0 | -> |  0   |   0   | 1 | 0 |
//  | 0 |  0   |   0   | 1 |	|   0   | 0 |    0 | 1 |	|  0   |   0   | 0 | 1 |
//  +----------------------+	+----------------------+    +----------------------+
//
//          		     POSITION
//					 +---------------+
//					 | 1 | 0 | 0 | x |
//					 | 0 | 1 | 0 | y |
//					 | 0 | 0 | 1 | z |
//					 | 0 | 0 | 0 | 1 |
//					 +---------------+
//					
//						  SCALE
//					 +---------------+
//					 | x | 0 | 0 | 0 |
//					 | 0 | y | 0 | 0 |
//					 | 0 | 0 | z | 0 |
//					 | 0 | 0 | 0 | 1 |
//					 +---------------+
//------------------------------------------
// http://
//------------------------------------------
#include "Matrix4.h"
#include <math.h>

//------------------------------------------
//		 --- Default Constructor ---
//------------------------------------------
//			  +---------------+
//			  | 1 | 0 | 0 | 0 |
//			  | 0 | 1 | 0 | 0 |
//			  | 0 | 0 | 1 | 0 |
//			  | 0 | 0 | 0 | 1 |
//			  +---------------+
//------------------------------------------
Matrix4::Matrix4()
{
	m[0] = 1.0f;	//Xx
	m[1] = 0.0f;	//Xy
	m[2] = 0.0f;	//Xz
	m[3] = 0.0f;	//Xw

	m[4] = 0.0f;	//Yx
	m[5] = 1.0f;	//Yy
	m[6] = 0.0f;	//Yz
	m[7] = 0.0f;	//Yw

	m[8] = 0.0f;	//Zx
	m[9] = 0.0f;	//Zy
	m[10] = 1.0f;	//Zz
	m[11] = 0.0f;	//Zw

	m[12] = 0.0f;	//Tx
	m[13] = 0.0f;	//Ty
	m[14] = 0.0f;	//Tz
	m[15] = 1.0f;	//Tw

}

//------------------------------------------
//			 --- Constructor ---
//------------------------------------------
//			+-------------------+
//			| Xx | Yx | Zx | Tx |
//			| Xy | Yy | Zy | Ty |
//			| Xz | Yz | Zz | Tz |
//			| Xw | Yw | Zw | Tw |
//			+-------------------+
//------------------------------------------
Matrix4::Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw)
{
	m[0] = Xx;	//Xx
	m[1] = Xy;	//Xy
	m[2] = Xz;	//Xz
	m[3] = Xw;	//Xw

	m[4] = Yx;	//Yx
	m[5] = Yy;	//Yy
	m[6] = Yz;	//Yz
	m[7] = Yw;	//Yw

	m[8] = Zx;	//Zx
	m[9] = Zy;	//Zy
	m[10] = Zz;	//Zz
	m[11] = Zw;	//Zw

	m[12] = Tx;	//Tx
	m[13] = Ty;	//Ty
	m[14] = Tz;	//Tz
	m[15] = Tw;	//Tw
}

//------------------------------------------
//	 --- Matrix (Multiplied By) Vector ---
//------------------------------------------
Vector4 Matrix4::operator*(Vector4 rhs)
{
	Vector4 vResult;

	vResult.x = (m[0] * rhs.x) + (m[4] * rhs.y) + (m[8] * rhs.z) + (m[12] * rhs.w);
	vResult.y = (m[1] * rhs.x) + (m[5] * rhs.y) + (m[9] * rhs.z) + (m[13] * rhs.w);
	vResult.z = (m[2] * rhs.x) + (m[6] * rhs.y) + (m[10] * rhs.z) + (m[14] * rhs.w);
	vResult.w = (m[3] * rhs.x) + (m[7] * rhs.y) + (m[11] * rhs.z) + (m[15] * rhs.w);

	return vResult;
}

//------------------------------------------
//	 --- Matrix (Multiplied By) Matrix ---
//------------------------------------------
Matrix4 Matrix4::operator*(Matrix4 rhs)
{
	Matrix4 vResult;

	vResult.m[0] = (m[0] * rhs.m[0]) + (m[4] * rhs.m[1]) + (m[8] * rhs.m[2]) + (m[12] * rhs.m[3]);
	vResult.m[1] = (m[1] * rhs.m[0]) + (m[5] * rhs.m[1]) + (m[9] * rhs.m[2]) + (m[13] * rhs.m[3]);
	vResult.m[2] = (m[2] * rhs.m[0]) + (m[6] * rhs.m[1]) + (m[10] * rhs.m[2]) + (m[14] * rhs.m[3]);
	vResult.m[3] = (m[3] * rhs.m[0]) + (m[7] * rhs.m[1]) + (m[11] * rhs.m[2]) + (m[15] * rhs.m[3]);

	vResult.m[4] = (m[0] * rhs.m[4]) + (m[4] * rhs.m[5]) + (m[8] * rhs.m[6]) + (m[12] * rhs.m[7]);
	vResult.m[5] = (m[1] * rhs.m[4]) + (m[5] * rhs.m[5]) + (m[9] * rhs.m[6]) + (m[13] * rhs.m[7]);
	vResult.m[6] = (m[2] * rhs.m[4]) + (m[6] * rhs.m[5]) + (m[10] * rhs.m[6]) + (m[14] * rhs.m[7]);
	vResult.m[7] = (m[3] * rhs.m[4]) + (m[7] * rhs.m[5]) + (m[11] * rhs.m[6]) + (m[15] * rhs.m[7]);

	vResult.m[8] = (m[0] * rhs.m[8]) + (m[4] * rhs.m[9]) + (m[8] * rhs.m[10]) + (m[12] * rhs.m[11]);
	vResult.m[9] = (m[1] * rhs.m[8]) + (m[5] * rhs.m[9]) + (m[9] * rhs.m[10]) + (m[13] * rhs.m[11]);
	vResult.m[10] = (m[2] * rhs.m[8]) + (m[6] * rhs.m[9]) + (m[10] * rhs.m[10]) + (m[14] * rhs.m[11]);
	vResult.m[11] = (m[3] * rhs.m[8]) + (m[7] * rhs.m[9]) + (m[11] * rhs.m[10]) + (m[15] * rhs.m[11]);
	
	vResult.m[12] = (m[0] * rhs.m[12]) + (m[4] * rhs.m[13]) + (m[8] * rhs.m[14]) + (m[12] * rhs.m[15]);
	vResult.m[13] = (m[1] * rhs.m[12]) + (m[5] * rhs.m[13]) + (m[9] * rhs.m[14]) + (m[13] * rhs.m[15]);
	vResult.m[14] = (m[2] * rhs.m[12]) + (m[6] * rhs.m[13]) + (m[10] * rhs.m[14]) + (m[14] * rhs.m[15]);
	vResult.m[15] = (m[3] * rhs.m[12]) + (m[7] * rhs.m[13]) + (m[11] * rhs.m[14]) + (m[15] * rhs.m[15]);

	return vResult;
}

//------------------------------------------
//	 --- Matrix (Multiplied By) Matrix ---
//------------------------------------------
Vector4& Matrix4::operator[](int nIndex)
{
	assert(nIndex < 3 || nIndex > 0, "Out Of Bounds: nIndex (0 - 3)");
	return vec[nIndex];
}

Matrix4::operator float*()
{
	return &m[0];
}

//------------------------------------------
//		 --- Set X Rotation ---
//------------------------------------------
//		+----------------------+
//		| 1 |  0   |   0   | 0 |
//		| 0 |cos(a)|-sin(a)| 0 |
//		| 0 |sin(a)| cos(a)| 0 |
//		| 0 |  0   |   0   | 1 |
//		+----------------------+
//------------------------------------------
void Matrix4::setRotateX(float fRaidians)
{
	m[5] = cos(fRaidians);
	m[6] = sin(fRaidians);

	m[9] = -sin(fRaidians);
	m[10] = cos(fRaidians);
}

//------------------------------------------
//		 --- Set Y Rotation ---
//------------------------------------------
//		+----------------------+
//		| cos(a)| 0 |sin(a)| 0 |
//		|   0   | 0 |  1   | 0 |
//		|-sin(a)| 0 |cos(a)| 0 |
//		|   0   | 0 |    0 | 1 |
//		+----------------------+
//------------------------------------------
void Matrix4::setRotateY(float fRaidians)
{
	m[0] = cos(fRaidians);
	m[2] = -sin(fRaidians);

	m[8] = sin(fRaidians);
	m[10] = cos(fRaidians);
}

//------------------------------------------
//		 --- Set Z Rotation ---
//------------------------------------------
//		+----------------------+
//		|cos(a)|-sin(a)| 0 | 0 |
//		|sin(a)| cos(a)| 0 | 0 |
//		|  0   |   0   | 1 | 0 |
//		|  0   |   0   | 0 | 1 |
//		+----------------------+
//------------------------------------------
void Matrix4::setRotateZ(float fRaidians)
{
	m[0] = cos(fRaidians);
	m[1] = sin(fRaidians);

	m[4] = -sin(fRaidians);
	m[5] = cos(fRaidians);
}

//------------------------------------------
//		 --- Set Position(x,y) ---
//------------------------------------------
//			+---------------+
//			| 1 | 0 | 0 | x |
//			| 0 | 1 | 0 | y |
//			| 0 | 0 | 1 | z |
//			| 0 | 0 | 0 | 1 |
//			+---------------+
//------------------------------------------
void Matrix4::setPosition(float x, float y, float z)
{
	m[12] = x;
	m[13] = y;
	m[14] = z;
}

//------------------------------------------
//		--- Set Position(Vector2) ---
//------------------------------------------
//			+---------------+
//			| 1 | 0 | 0 | x |
//			| 0 | 1 | 0 | y |
//			| 0 | 0 | 1 | z |
//			| 0 | 0 | 0 | 1 |
//			+---------------+
//------------------------------------------
void Matrix4::setPosition(Vector3 pos)
{
	m[12] = pos.x;
	m[13] = pos.y;
	m[14] = pos.z;
}

//------------------------------------------
//		  --- Set Scale(x,y) ---
//------------------------------------------
//			 +---------------+
//			 | x | 0 | 0 | 0 |
//			 | 0 | y | 0 | 0 |
//			 | 0 | 0 | z | 0 |
//			 | 0 | 0 | 0 | 1 |
//			 +---------------+
//------------------------------------------
void Matrix4::setScale(float x, float y, float z)
{
	m[0] = x;
	m[5] = y;
	m[10] = z;
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
void Matrix4::setScale(Vector3 pos)
{
	m[0] = pos.x;
	m[5] = pos.y;
	m[10] = pos.z;
}

//------------------------------------------
//			--- Get Position ---
//------------------------------------------
Vector3 Matrix4::getPosition()
{
	Vector3 vResult;

	vResult.x = m[12];
	vResult.y = m[13];
	vResult.z = m[14];

	return vResult;
}

//------------------------------------------
//		  --- Get Facing Vector ---
//------------------------------------------
Vector3 Matrix4::getForwardVector()
{
	Vector3 vResult;

	vResult.x = m[4];
	vResult.y = m[5];
	vResult.z = m[6];

	return vResult;
}

//------------------------------------------
//		  --- Get Right Vector ---
//------------------------------------------
Vector3 Matrix4::getRightVector()
{
	Vector3 vResult;

	vResult.x = m[0];
	vResult.y = m[1];
	vResult.z = m[3];

	return vResult;
}

//------------------------------------------
//		  --- Get Right Vector ---
//------------------------------------------
Vector3 Matrix4::getUpVector()
{
	Vector3 vResult;

	vResult.x = m[8];
	vResult.y = m[9];
	vResult.z = m[10];

	return vResult;
}

//------------------------------------------
//		  --- Get Scale Vector ---
//------------------------------------------
Vector3 Matrix4::getScale()
{
	Vector3 vResult;

	vResult.x = m[0];
	vResult.y = m[5];
	vResult.z = m[10];

	return vResult;
}


