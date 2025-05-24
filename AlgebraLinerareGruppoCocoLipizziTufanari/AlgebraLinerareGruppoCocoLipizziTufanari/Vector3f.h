#pragma once
#include <iostream>
using namespace std;

class Vector3f
{
public:

	float x, y, z;
	//	//Creo vettore nullo
	Vector3f();
	//Creo un vettore a partire da tre numeri passati
	Vector3f(float x, float y, float z);
	//Creo un vettore che ha le componenti uguali
	Vector3f(float a);
	//Copy construtor
	Vector3f(const Vector3f& v);


	Vector3f operator+(Vector3f s); // sum of 2 array of dim 3 ina new array
	Vector3f operator-(Vector3f v);  // differece between 2 array in a new array


	Vector3f& operator+=(Vector3f s);	 // operator += changing the array

	Vector3f& operator-=(Vector3f s);    // operator -=changing the array


	Vector3f& operator= (const Vector3f s);    // operator = operatore di assegnazione

	Vector3f operator* (float a);       //product between array an scalar in a new array
	Vector3f operator/ (float a);       //division between array an scalar in a new array

	Vector3f& operator*= (float a);       //product between array an scalar changing the array

	Vector3f& operator/= (float a);       //division between array an scalar changing the array


	//friend Vector3f operator*(float f, const Vector3f& v); //s * v

	float dotProd(Vector3f s); // prodotto scalare tra due vettore
	float operator*(Vector3f v); // prodotto scalare tra due vettore

	Vector3f crossProd(Vector3f s); // prodotto vettorale tra 2 vettori

	float norm(); // lunghezza del vettore
	void normalize(); //cambia il vettore
	Vector3f getNormalized(); // restituisce un nuovo vettore

	bool operator==(const Vector3f& other) const;
	bool operator!=(const Vector3f& other) const;

};


ostream& operator<<(ostream& output, Vector3f& v); // operatore put
