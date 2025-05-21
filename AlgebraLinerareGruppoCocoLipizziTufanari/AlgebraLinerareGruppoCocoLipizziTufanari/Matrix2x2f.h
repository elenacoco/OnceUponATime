#pragma once
#include "Vector2f.h"
using namespace std;

class Matrix2x2f
{
public:

	float a11, a12;
	float a21, a22;
	
	//Costruttore identita'
	Matrix2x2f();

	Matrix2x2f(float a11, float a12, 
			   float a21, float a22);

	Matrix2x2f(float a);

	Matrix2x2f(Vector2f row1, Vector2f row2);

	// copy constructor??

	Matrix2x2f operator+(Matrix2x2f a);
	Matrix2x2f operator-(Matrix2x2f a);

	Matrix2x2f& operator+=(Matrix2x2f s);	 // operator +=
	//void operator+=(Matrix2x2f v);	 // operator +=

	Matrix2x2f& operator-=(Matrix2x2f s);    // operator -=
	//void operator-=(Matrix2x2f v);    // operator -=

	Matrix2x2f& operator= (const Matrix2x2f s);    // operator = copy assignment
	
	
	Matrix2x2f operator*(float a);
	Matrix2x2f operator/(float a);

	Matrix2x2f& operator*=(float a);
	//void operator*=(float a);

	Matrix2x2f& operator/=(float a);
	//void operator/=(float a);


	Vector2f operator*(Vector2f& s);
	Matrix2x2f operator* (Matrix2x2f& m);



	Matrix2x2f traspose();
	float det();
	Matrix2x2f inv();

	/*bool isIdentity() const;
	bool isZero() const;*/

	bool operator==(const Matrix2x2f& other) const;
	bool operator!=(const Matrix2x2f& other) const;


	friend ostream& operator<<(ostream& output, Matrix2x2f& v);
};
