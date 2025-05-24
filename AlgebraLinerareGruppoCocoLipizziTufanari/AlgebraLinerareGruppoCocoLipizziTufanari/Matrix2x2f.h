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

	//Costruisce una matrice mettendo per riga due vettori (capire se è meglio metterli per colonna)
	Matrix2x2f(Vector2f row1, Vector2f row2);

	//Copy constructor
	Matrix2x2f(const Matrix2x2f& m);

	Matrix2x2f operator+(Matrix2x2f a);
	Matrix2x2f operator-(Matrix2x2f a);

	Matrix2x2f& operator+=(Matrix2x2f s);	 // operator +=
	Matrix2x2f& operator-=(Matrix2x2f s);    // operator -=

	Matrix2x2f& operator= (const Matrix2x2f s);    // operator = copy assignment
	
	
	Matrix2x2f operator*(float a);
	Matrix2x2f operator/(float a);

	Matrix2x2f& operator*=(float a);
	Matrix2x2f& operator/=(float a);


	Vector2f operator*(Vector2f& s);
	Matrix2x2f operator* (Matrix2x2f& m); //prodotto righe-colonne


	Matrix2x2f traspose();
	float det();
	Matrix2x2f inv();

	bool operator==(const Matrix2x2f& other) const;
	bool operator!=(const Matrix2x2f& other) const;

};

ostream& operator<<(ostream& output, Matrix2x2f& v);