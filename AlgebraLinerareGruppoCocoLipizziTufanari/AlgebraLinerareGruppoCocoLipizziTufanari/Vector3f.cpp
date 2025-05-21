
#include "Vector3f.h"
#include <iostream>

using namespace std;
Vector3f::Vector3f()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3f::Vector3f(float a)
{
	x = a;
	y = a;
	z = a;
}

Vector3f::Vector3f(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}




Vector3f Vector3f::operator+(Vector3f othervect)
{

	return Vector3f(x + othervect.x, y + othervect.y, z + othervect.z);

}

Vector3f Vector3f::operator-(Vector3f othervect)
{
	return Vector3f(x - othervect.x, y - othervect.y, z - othervect.z);

}

Vector3f& Vector3f :: operator+= (Vector3f other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

//
//void Vector3f :: operator+= (Vector3f other)
//{
//	x += other.x;
//	y += other.y;
//	z += other.z;
//}

Vector3f& Vector3f :: operator-= (Vector3f other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

//
//void Vector3f :: operator-= (Vector3f other)
//{
//	x -= other.x;
//	y -= other.y;
//	z -= other.z;
//}

Vector3f& Vector3f :: operator= (const Vector3f other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}


Vector3f Vector3f :: operator*  (float f) // prodotto tra vettore e scalare
{
	return Vector3f(x * f, y * f, z * f);
}


Vector3f Vector3f:: operator/ (float f)  // divisione tra vettore e scalare
{
	return Vector3f(x / f, y / f, z / f);
}

Vector3f& Vector3f :: operator*=  (float f) // prodotto tra vettore e scalare
{
	x *= f;
	y *= f;
	z *= f;
	return *this;
}
//
//void Vector3f :: operator*=  (float f) // prodotto tra vettore e scalare
//{
//	x *= f;
//	y *= f;
//	z *= f;
//}

Vector3f& Vector3f:: operator/= (float f)  // divisione tra vettore e scalare
{
	x /= f;
	y /= f;
	z /= f;
	return *this;
}

//void Vector3f:: operator/= (float f)  // divisione tra vettore e scalare
//{
//	x /= f;
//	y /= f;
//	z /= f;
//	
//}
//
//Vector3f operator*(float f, const Vector3f& v)
//{
//	return Vector3f(f * v.x, f * v.y, f * v.z);
//}

float Vector3f::dotProd(Vector3f other) // Prodotto scalare tra due vettori
{
	float xtot = x * other.x;
	float ytot = y * other.y;
	float ztot = z * other.z;

	return xtot + ytot + ztot;
}

float Vector3f::operator*(Vector3f v)
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3f Vector3f::crossProd(Vector3f other) // prodotto vettorale tra 2 vettorali
{
	float det1 =  (y * other.z - z * other.y);
	float det2 = -(x * other.z - z * other.x);
	float det3 =  (x * other.y - y * other.x);

	 return Vector3f (det1, det2, det3);
	
}
float Vector3f::norm()
{
	return sqrt(x * x + y * y + z * z);
}

void Vector3f::normalize()
{
	float len = norm();
	if (len != 0.0f)
		*this = *this / len;
	else
		std::cout << "la norma 2 del vettore è 0!";
}

Vector3f Vector3f::getNormalized()
{
	float len = norm();
	if (len != 0.0f)
		return *this / len;
	else
	{
		std::cout << "la norma 2 del vettore è 0!";
		return *this;
	}
}


bool Vector3f::operator==(const Vector3f& other) const {
	return x == other.x && y == other.y && z==other.z;
}

bool Vector3f::operator!=(const Vector3f& other) const {
	return !(*this == other);
}


ostream& operator<<(ostream& output, Vector3f& v)
{
	output << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return output;
}
