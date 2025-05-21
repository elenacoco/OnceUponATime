#include <iostream>
#include <cmath>
#include <iomanip>  // Per std::setprecision e std::fixed
#include "Vector2f.h"
#include "Matrix2x2f.h"


//aiutoooooooo
using namespace std;
// ciao sono matteo  ci sono riuscito due volte?

Matrix2x2f::Matrix2x2f()
{
	a11 = 1; a12 = 0;
	a21 = 0; a22 = 1;
	
}
//accca
//jnibiubouylvb
Matrix2x2f::Matrix2x2f(float a)
{
	a11 = a; a12 = a; 
	a21 = a; a22 = a; 
	
}

Matrix2x2f::Matrix2x2f(float a11, float a12, float a21, float a22)
{
	this->a11 = a11; this->a12 = a12;
	this->a21 = a21; this->a22 = a22; 
	
}

Matrix2x2f::Matrix2x2f(Vector2f row1, Vector2f row2)
{
	a11 = row1.x;
	a12 = row1.y;
	a21 = row2.x;
	a22 = row2.y;
}



Matrix2x2f Matrix2x2f::operator+(Matrix2x2f other)
{
	return Matrix2x2f(a11 + other.a11, a12 + other.a12,
					  a21 + other.a21, a22 + other.a22
					 
	); 
}

Matrix2x2f Matrix2x2f :: operator-(Matrix2x2f other)
{
	return Matrix2x2f(a11 - other.a11, a12 - other.a12, 
					  a21 - other.a21, a22 - other.a22
	);
}

Matrix2x2f Matrix2x2f :: operator*(float a)
{
	return Matrix2x2f(a11 * a, a12 * a,
				      a21 * a, a22 * a
		
	);
}

Matrix2x2f Matrix2x2f :: operator/(float a)
{
	if (a != 0)
	{
		return Matrix2x2f(a11 / a, a12 / a,
						  a21 / a, a22 / a
		);
	}
	else
	{
		return Matrix2x2f();
		cout << "Error , impossible divide by 0" << endl;
	}

}

// M * v (v � considerato un vettore colonna)
Vector2f Matrix2x2f::operator*(Vector2f& vect) {
	float x = a11 * vect.x + a12 * vect.y;
	float y = a21 * vect.x + a22 * vect.y;

	return Vector2f(x, y);
}

Matrix2x2f Matrix2x2f::operator*( Matrix2x2f& othermatrix) 
{
	float a = a11 * othermatrix.a11 + a12 * othermatrix.a21;
	float b = a11 * othermatrix.a12 + a12 * othermatrix.a22;
	float c = a21 * othermatrix.a11 + a22 * othermatrix.a21;
	float d = a21 * othermatrix.a12 + a22 * othermatrix.a22;


	return Matrix2x2f(
		a, b, 
		c, d
	);
}

Matrix2x2f& Matrix2x2f::operator+=(Matrix2x2f s) {
	a11 += s.a11; a12 += s.a12;
	a21 += s.a21; a22 += s.a22;
	return *this;
}

//void Matrix2x2f::operator+=(Matrix2x2f matrix)
//{
//	this->a11 += matrix.a11;
//	this->a12 += matrix.a12;
//	this->a21 += matrix.a21;
//	this->a22 += matrix.a22;
//}

Matrix2x2f& Matrix2x2f::operator-=(Matrix2x2f s) {
	a11 -= s.a11; a12 -= s.a12;
	a21 -= s.a21; a22 -= s.a22;
	return *this;
}

//void Matrix2x2f::operator+=(Matrix2x2f matrix)
//{
//	this->a11 -= matrix.a11;
//	this->a12 -= matrix.a12;
//	this->a21 -= matrix.a21;
//	this->a22 -= matrix.a22;
//}

Matrix2x2f& Matrix2x2f::operator=(Matrix2x2f s) {
	a11 = s.a11; a12 = s.a12;
	a21 = s.a21; a22 = s.a22;
	return *this;
}

Matrix2x2f& Matrix2x2f::operator*=(float s) {
	a11 *= s; a12 *= s;
	a21 *= s; a22 *= s;
	return *this;
}
//
//void Matrix2x2f::operator*=(float s) {
//	a11 *= s; a12 *= s;
//	a21 *= s; a22 *= s;
//}




Matrix2x2f& Matrix2x2f::operator/=(float s) {
	if (s != 0.0f) {
		a11 /= s; a12 /= s;
		a21 /= s; a22 /= s;
	}
	else {
		cout << "Errore: divisione per zero in Matrix2x2f::operator/=" << endl;
	}
	return *this;
}
////
////void Matrix2x2f::operator/=(float s) {
////	if (s != 0.0f) {
////		a11 /= s; a12 /= s;
////		a21 /= s; a22 /= s;
////	}
////	else {
////		cout << "Errore: divisione per zero in Matrix2x2f::operator/=" << endl;
////	}
////}


float Matrix2x2f::det()
{

	return  (a11 * a22) - (a12 * a21);
}

Matrix2x2f Matrix2x2f::inv()
{
	float determinante = det();

	if (determinante == 0) {
		cout << endl << "Matrice non invertibile (determinante = 0)." << endl;
		return *this; // oppure puoi ritornare una matrice nulla o gestire diversamente
	}
	else {
		return Matrix2x2f(
			a22, -a12,
		   -a21,  a11 )/determinante;
	}
}

Matrix2x2f Matrix2x2f::traspose()
{
	return Matrix2x2f(
		a11, a21, 
		a12, a22
		
	);
}
/*
bool Matrix2x2f::isIdentity() const {
	return a11 == 1.0f && a12 == 0.0f &&
		   a21 == 0.0f && a22 == 1.0f;
}

bool Matrix2x2f::isZero() const {
	return a11 == 0.0f && a12 == 0.0f &&
		   a21 == 0.0f && a22 == 0.0f;
}*/

bool Matrix2x2f::operator==(const Matrix2x2f& other) const {
	return a11 == other.a11 && a12 == other.a12 &&
		   a21 == other.a21 && a22 == other.a22;
}

bool Matrix2x2f::operator!=(const Matrix2x2f& other) const {
	return !(*this == other);
}

ostream& operator<< (ostream& output, Matrix2x2f& v)
{
	// Imposta la precisione a 2 decimali (modifica a seconda delle tue esigenze)
	output << fixed << setprecision(3);
	output << "[" << v.a11 << " , " << v.a12 << "]" << endl
		   << "[" << v.a21 << " , " << v.a22 << "]" << endl;
	return output;
}



















