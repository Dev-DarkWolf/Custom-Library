#pragma once
struct Vector2
{
	Vector2();
	Vector2(float x, float y);

	Vector2 operator+(Vector2 rhs);
	Vector2 operator-(Vector2 rhs);
	Vector2 operator*(float scalar);

	float& operator[](int nIndex);

	explicit operator float*();

	float dot(Vector2 rhs);

	float magnitude();
	void normalise();

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


