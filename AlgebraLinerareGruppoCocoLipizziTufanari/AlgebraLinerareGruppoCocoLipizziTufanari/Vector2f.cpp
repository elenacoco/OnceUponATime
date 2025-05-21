
#include "Vector2f.h"
#include <iostream>

using namespace std;
Vector2f::Vector2f()
{
	x = 0;
	y = 0;
}

Vector2f::Vector2f(float a)
{
	x = a;
	y = a;
}

Vector2f::Vector2f(float a, float b)
{
	x = a;
	y = b;
}


Vector2f Vector2f::operator+(Vector2f othervect)
{

	return Vector2f(x + othervect.x, y + othervect.y);

}

Vector2f Vector2f::operator-(Vector2f othervect)
{
	return Vector2f(x - othervect.x, y - othervect.y);

}

Vector2f& Vector2f :: operator+= (Vector2f other)
{
	x += other.x;
	y += other.y;
	
	return *this;
}
//
//void Vector2f::operator+=(Vector2f v)
//{
//	x += v.x;
//	y  += v.y;
//}

Vector2f& Vector2f :: operator-= (Vector2f other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}
//void Vector2f::operator+=(Vector2f v)
//{
//	x -= v.x;
//	y -= v.y;
//}

Vector2f& Vector2f :: operator= (const Vector2f other)
{
	x = other.x;
	y = other.y;

	return *this;
}



Vector2f Vector2f:: operator/ (float f)  // divisione tra vettore e scalare
{
	return Vector2f(x / f, y / f);
}


Vector2f Vector2f :: operator*  (float f) // prodotto tra vettore e scalare
{
	return Vector2f(x * f, y * f);
}





Vector2f& Vector2f :: operator*=  (float f) // prodotto tra vettore e scalare
{
	x *= f;
	y *= f;
	return *this;
}

//void Vector2f::operator*=(float num)
//{
//	x *= num;
//	y *= num;
//}
Vector2f& Vector2f:: operator/= (float f)  // divisione tra vettore e scalare
{
	x /= f;
	y /= f;
	return *this;
}


//void Vector2f::operator*=(float num)
//{
//	x /= num;
//	y /= num;
//}

Vector2f operator*(float f, const Vector2f& v) 
{
	return Vector2f(f * v.x, f * v.y);
}




float Vector2f::dotProd(Vector2f other) // Prodotto scalare tra due vettori
{
	float xtot = x * other.x;
	float ytot = y * other.y;

	return xtot + ytot;
}

float Vector2f::operator*(Vector2f v)
{
	return x * v.x + y * v.y;
}

float Vector2f::norm()
{
	return sqrt(x * x + y * y);
}

void Vector2f::normalize()
{
	float len = norm();
	if (len != 0.0f)
		*this = *this / len;
	else
		std::cout << "la norma 2 del vettore è 0!";
}

Vector2f Vector2f::getNormalized()
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

bool Vector2f::operator==(const Vector2f& other) const {
	return x == other.x && y == other.y;
}

bool Vector2f::operator!=(const Vector2f& other) const {
	return !(*this == other);
}



ostream& operator<< (ostream& output, Vector2f& v)
{
	output << "(" << v.x << "," << v.y << ")";
	return output;
}
