#pragma once
struct Vector3
{
	Vector3();
	Vector3(float x, float y, float z);

	Vector3 operator+(Vector3 rhs);
	Vector3 operator-(Vector3 rhs);
	Vector3 operator*(float scalar);

	float& operator[](int nIndex);

	explicit operator float*();

	float dot(Vector3 rhs);
	Vector3 cross(Vector3 vVector);
	float magnitude();
	void normalise();

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


