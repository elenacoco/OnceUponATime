#pragma once
#include "Vector3f.h"
using namespace std;

class Matrix3x3f
{
public:

	float a11, a12, a13;
	float a21, a22, a23;
	float a31, a32, a33;

	//Costruttore identità
	Matrix3x3f();

	Matrix3x3f( float a11, float a12, float a13, 
				float a21, float a22, float a23, 
				float a31, float a32, float a33);

	Matrix3x3f(float a);

	//Costruttore a partire da 3 vettori, li mette per riga
	Matrix3x3f(Vector3f row1, Vector3f row2, Vector3f row3);

	//Copy Constructor 
	Matrix3x3f(const Matrix3x3f& m);

	Matrix3x3f operator+(Matrix3x3f a);
	Matrix3x3f operator-(Matrix3x3f a);

	Matrix3x3f& operator+=(Matrix3x3f s);	 // operator +=
	Matrix3x3f& operator-=(Matrix3x3f s);    // operator -=
	Matrix3x3f& operator= (Matrix3x3f s);    // operator =

	Matrix3x3f operator*(float a);
	Matrix3x3f operator/(float a);

	Matrix3x3f& operator*=(float a);
	Matrix3x3f& operator/=(float a);

	Vector3f operator*( Vector3f& s) ;
	Matrix3x3f operator*(const Matrix3x3f& m);

	Matrix3x3f traspose();
	float det() ;
	Matrix3x3f inv() ;

	bool operator==(const Matrix3x3f& other) const;
	bool operator!=(const Matrix3x3f& other) const;

};

ostream& operator<<(ostream& output, Matrix3x3f& v);