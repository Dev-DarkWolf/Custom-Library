#pragma once
struct Vector4
{
	Vector4();
	Vector4(float x, float y, float z, float w);

	Vector4 operator+(Vector4 rhs);
	Vector4 operator-(Vector4 rhs);
	Vector4 operator*(float scalar);

	float& operator[](int nIndex);

	explicit operator float*();

	float dot(Vector4 rhs);
	Vector4 cross(Vector4 vVector);
	float magnitude();
	void normalise();

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


