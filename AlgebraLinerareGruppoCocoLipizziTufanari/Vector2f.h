#pragma once
#include <iostream>
using namespace std;

class Vector2f
{
public:

	float x, y;
	//Creo vettore nullo
	Vector2f(); 
	//Creo un vettore a partire da due numeri passati
	Vector2f(float x, float y);
	//Creo un vettore che ha due le componenti uguali
	Vector2f(float a);
	//Copy constructor
	Vector2f(const Vector2f& v);


	Vector2f operator+(Vector2f s); // sum of 2 array of dim 2
	Vector2f operator-(Vector2f v);  // differece between 2 array
	
	Vector2f& operator+=(Vector2f s);	 // operator +=

	Vector2f& operator-=(Vector2f s);    // operator -=

	Vector2f& operator= (const Vector2f s);    // operator = // copy assignment

	
	Vector2f operator* (float a);       //product between array an scalar
	Vector2f operator/ (float a);       //division between array an scalar

	Vector2f& operator*= (float a);       //product between array an scalar

	Vector2f& operator/= (float a);       //division between array an scalar

	//friend Vector2f operator*(float f, const Vector2f& v); //cosi nel main si puo scrivere scalare * vettore

	float dotProd(Vector2f s); // prodotto scalare tra due vettori

	float operator*(Vector2f v); // prodotto scalare tra due vettori

	float norm(); // norma 2 del vettore

	//normalizza il vettore
	void normalize();

	//restituisce un 
	Vector2f getNormalized();

	bool operator==(const Vector2f& other) const;
	bool operator!=(const Vector2f& other) const;



	
	friend ostream& operator<<(ostream& output, Vector2f& v);


};



