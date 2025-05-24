#pragma once
#include <iostream>
using namespace std;

class Vector4f
{
public:

	float x, y, z, w;
	//	//Creo vettore nullo
	Vector4f();
	//Creo un vettore a partire da tre numeri passati
	Vector4f(float x, float y, float z, float w);
	//Creo un vettore che ha le componenti uguali
	Vector4f(float a);
	//Copy constructor
	Vector4f(const Vector4f& v);
	
	Vector4f operator+(Vector4f s);  //sum o 2 array of dim 4
	Vector4f operator-(Vector4f s); //difference between 2 vector4

	Vector4f operator+=(Vector4f s); //operator +=
	Vector4f operator-=(Vector4f s); //operator -=

	Vector4f& operator=(const Vector4f s);    // operator =

	Vector4f operator*(float a);       //product between array an scalar
	Vector4f operator/(float a);       //division between array an scalar

	Vector4f& operator*= (float a);       //product between array an scalar changing the array
	Vector4f& operator/= (float a);       //division between array an scalar changing the array

	//friend Vector4f operator*(float f, const Vector4f& v); //s * v


	float dotProd(Vector4f s); // prodotto scalare tra due vettore
	float operator*(Vector4f v);

	float norm(); // lunghezza del vettore
	void normalize(); //normalizza il vettore
	Vector4f getNormalized(); //crea una copia del vettore normalizzato

	bool operator==(const Vector4f& other) const;
	bool operator!=(const Vector4f& other) const;


};

ostream& operator<<(ostream& output, Vector4f& v); // operatore put
