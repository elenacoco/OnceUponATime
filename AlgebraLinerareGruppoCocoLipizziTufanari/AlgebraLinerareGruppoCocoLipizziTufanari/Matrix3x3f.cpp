#include "Matrix3x3f.h"
#include <iostream>
#include <iomanip>  // Per std::setprecision e std::fixed
#include <cmath>
#include "Vector3f.h"

using namespace std;
//ci riprovo un'altra volta

Matrix3x3f::Matrix3x3f()
{
	a11 = 1; a12 = 0; a13 = 0;
	a21 = 0; a22 = 1; a23 = 0;
	a31 = 0; a32 = 0; a33 = 1;
}

Matrix3x3f::Matrix3x3f(float a)
{
	a11 = a; a12 = a; a13 = a;
	a21 = a; a22 = a; a23 = a;
	a31 = a; a32 = a; a33 = a;
}

Matrix3x3f::Matrix3x3f(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33)
{
	this->a11 = a11; this->a12 = a12; this->a13 = a13;
	this->a21 = a21; this->a22 = a22; this->a23 = a23;
	this->a31 = a31; this->a32 = a32; this->a33 = a33;
}



Matrix3x3f Matrix3x3f::operator+(Matrix3x3f other)
{
	return Matrix3x3f(a11 + other.a11, a12 + other.a12, a13 + other.a13,
					 a21 + other.a21, a22 + other.a22, a23 + other.a23,
					 a31 + other.a31, a32 + other.a32, a33 + other.a33
	);
}

Matrix3x3f Matrix3x3f :: operator-(Matrix3x3f other)
{
	return Matrix3x3f(a11 - other.a11, a12 - other.a12, a13 - other.a13,
					  a21 - other.a21, a22 - other.a22, a23 - other.a23,
					  a31 - other.a31, a32 - other.a32, a33 - other.a33
	);
}

Matrix3x3f Matrix3x3f :: operator*(float a)
{
	return Matrix3x3f(a11 * a, a12 * a, a13 * a,
		a21 * a, a22 * a, a23 * a,
		a31 * a, a32 * a, a33 * a
	);
}

Matrix3x3f Matrix3x3f :: operator/(float a)
{
	if (a != 0)
	{
		return Matrix3x3f(  a11 / a, a12 / a, a13 / a,
							a21 / a, a22 / a, a23 / a,
							a31 / a, a32 / a, a33 / a
		);
	}
	else
	{
		return Matrix3x3f();
		cout << "Error , impossible divide by 0" << endl;
	}

}

Matrix3x3f& Matrix3x3f::operator+=(Matrix3x3f s) {
	a11 += s.a11; a12 += s.a12; a13 += s.a13;
	a21 += s.a21; a22 += s.a22; a23 += s.a23;
	a31 += s.a31; a32 += s.a32; a33 += s.a33;
	return *this;
}

Matrix3x3f& Matrix3x3f::operator-=(Matrix3x3f s) {
	a11 -= s.a11; a12 -= s.a12; a13 -= s.a13;
	a21 -= s.a21; a22 -= s.a22; a23 -= s.a23;
	a31 -= s.a31; a32 -= s.a32; a33 -= s.a33;
	return *this;
}

Matrix3x3f& Matrix3x3f::operator=(Matrix3x3f s) {
	a11 = s.a11; a12 = s.a12; a13 = s.a13;
	a21 = s.a21; a22 = s.a22; a23 = s.a23;
	a31 = s.a31; a32 = s.a32; a33 = s.a33;
	return *this;
}

Matrix3x3f& Matrix3x3f::operator*=(float s) {
	a11 *= s; a12 *= s; a13 *= s;
	a21 *= s; a22 *= s; a23 *= s;
	a31 *= s; a32 *= s; a33 *= s;
	return *this;
}

Matrix3x3f& Matrix3x3f::operator/=(float s) {
	if (s != 0.0f) {
		a11 /= s; a12 /= s; a13 /= s;
		a21 /= s; a22 /= s; a23 /= s;
		a31 /= s; a32 /= s; a33 /= s;
	}
	else {
		cout << "Errore: divisione per zero in Matrix3x3f::operator/=" << endl;
	}
	return *this;
}

// M * v (v � considerato un vettore colonna)
Vector3f Matrix3x3f::operator*(Vector3f& vect) {
	float x = a11 * vect.x + a12 * vect.y + a13 * vect.z;
	float y = a21 * vect.x + a22 * vect.y + a23 * vect.z;
	float z = a31 * vect.x + a32 * vect.y + a33 * vect.z;

	return Vector3f(x, y, z);
}

Matrix3x3f Matrix3x3f::operator*(const Matrix3x3f& othermatrix) const {
	float a = a11 * othermatrix.a11 + a12 * othermatrix.a21 + a13 * othermatrix.a31;
	float b = a11 * othermatrix.a12 + a12 * othermatrix.a22 + a13 * othermatrix.a32;
	float c = a11 * othermatrix.a13 + a12 * othermatrix.a23 + a13 * othermatrix.a33;

	float d = a21 * othermatrix.a11 + a22 * othermatrix.a21 + a23 * othermatrix.a31;
	float e = a21 * othermatrix.a12 + a22 * othermatrix.a22 + a23 * othermatrix.a32;
	float f = a21 * othermatrix.a13 + a22 * othermatrix.a23 + a23 * othermatrix.a33;

	float g = a31 * othermatrix.a11 + a32 * othermatrix.a21 + a33 * othermatrix.a31;
	float h = a31 * othermatrix.a12 + a32 * othermatrix.a22 + a33 * othermatrix.a32;
	float i = a31 * othermatrix.a13 + a32 * othermatrix.a23 + a33 * othermatrix.a33;

	return Matrix3x3f(
		a, b, c,
		d, e, f,
		g, h, i
	);
}


float Matrix3x3f::det() 
{

	return  ((a11 * (a22 * a33 - a23 * a32)
		    - a12 * (a21 * a33 - a23 * a31)
		    + a13 * (a21 * a32 - a22 * a31)));
}
Matrix3x3f Matrix3x3f::inv() 
{
	float determinante = det();

	if (determinante == 0) {
		cout << endl << "Matrice non invertibile (determinante = 0)." << endl;
		return *this; // oppure puoi ritornare una matrice nulla o gestire diversamente
	}
	else {
		float c11 =  (a22 * a33 - a23 * a32);
		float c12 = -(a21 * a33 - a23 * a31);
		float c13 =  (a21 * a32 - a22 * a31);

		float c21 = -(a12 * a33 - a13 * a32);
		float c22 =  (a11 * a33 - a13 * a31);
		float c23 = -(a11 * a32 - a12 * a31);

		float c31 =  (a12 * a23 - a13 * a22);
		float c32 = -(a11 * a23 - a13 * a21);
		float c33 =  (a11 * a22 - a12 * a21);

		// Trasposta dei cofattori (l'aggiunta)
		Matrix3x3f adj(
			c11, c21, c31,
			c12, c22, c32,
			c13, c23, c33
		);

		return adj / determinante;
	}
}

Matrix3x3f Matrix3x3f::traspose()
{
	return Matrix3x3f(
		a11, a21, a31,
		a12, a22, a32,
		a13, a23, a33
	);
}

bool Matrix3x3f::operator==(const Matrix3x3f& other) const {
	return a11 == other.a11 && a12 == other.a12 && a13 == other.a13 &&
		   a21 == other.a21 && a22 == other.a22 && a23 == other.a23 &&
		   a31 == other.a31 && a32 == other.a32 && a33 == other.a33;
}

bool Matrix3x3f::operator!=(const Matrix3x3f& other) const {
	return !(*this == other);
}






ostream& operator<< (ostream& output, Matrix3x3f& v)
{
	// Imposta la precisione a 2 decimali (modifica a seconda delle tue esigenze)
	output << fixed << setprecision(3);
	output << "[" << v.a11 << " , " << v.a12 << " , " << v.a13 << "]" << endl
		   << "[" << v.a21 << " , " << v.a22 << " , " << v.a23 << "]" << endl
	       << "[" << v.a31 << " , " << v.a32 << " , " << v.a33 << "]" << endl;
	return output;
}








