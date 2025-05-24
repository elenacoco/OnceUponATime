
#include "Vector4f.h"
#include <iostream>
#include <cmath>


using namespace std;
Vector4f::Vector4f()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4f::Vector4f(float a)
{
	x = a;
	y = a;
	z = a;
	w = a;

}

Vector4f::Vector4f(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;

}

Vector4f::Vector4f(const Vector4f& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

Vector4f Vector4f::operator+(Vector4f othervect)
{

	return Vector4f(x + othervect.x,  y + othervect.y,  z + othervect.z,  w + othervect.w);

}

Vector4f Vector4f::operator-(Vector4f othervect)
{
	return Vector4f(x - othervect.x, y - othervect.y, z - othervect.z, w - othervect.w);

}


Vector4f Vector4f :: operator+= (Vector4f other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}


Vector4f Vector4f :: operator-= (Vector4f other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;

	return *this;
}


Vector4f& Vector4f :: operator= (const Vector4f other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;

	return *this;
}

Vector4f Vector4f::operator*(float f) // prodotto tra vettore e scalare
{
	return Vector4f(x * f,  y * f,  z * f,  w * f);
}


Vector4f Vector4f::operator/(float f) // divisione tra vettore e scalare
{
	if (f != 0)
	{
		return Vector4f(x / f,  y / f,  z / f,  w/f);
	}
	else
	{
		return *this;
		std::cout << "Errore, impossibile dividere per zero";
	}
	
}

Vector4f& Vector4f :: operator*=  (float f) // prodotto tra vettore e scalare
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}


Vector4f& Vector4f:: operator/= (float f)  // divisione tra vettore e scalare
{
	if (f != 0)
	{
		x /= f;
		y /= f;
		z /= f;
		w /= f;
		return *this;
	}
	else
	{
		return *this;
		std::cout << "Errore, impossibile dividere per zero";
	}
	
}



//Vector4f operator*(float f, const Vector4f& v)
//{
//	return Vector4f(f * v.x, f * v.y, f * v.z, f * v.w);
//}

float Vector4f::dotProd(Vector4f other) // Prodotto scalare tra due vettori
{
	float xtot = x * other.x;
	float ytot = y * other.y;
	float ztot = z * other.z;
	float wtot = w * other.w;


	return xtot + ytot + ztot + wtot;
}

float Vector4f::operator*(Vector4f v)
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

float Vector4f::norm()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w,2));

}

void Vector4f::normalize()
{
	float len = norm();
	if (len != 0.0f)
		*this = *this / len;
	else
		std::cout << "la norma 2 del vettore è 0!";
}

Vector4f Vector4f::getNormalized()
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


bool Vector4f::operator==(const Vector4f& other) const {
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vector4f::operator!=(const Vector4f& other) const {
	return !(*this == other);
}


ostream& operator<<(ostream& output, Vector4f& v)
{
	output << "(" << v.x << ", " << v.y << ", " << v.z << ", "<< v.w << ")";
	return output;
}