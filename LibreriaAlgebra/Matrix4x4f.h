#pragma once
#include "Vector4f.h"
using namespace std;

class Matrix4x4f
{
public:

    float a11, a12, a13, a14;
    float a21, a22, a23, a24;
    float a31, a32, a33, a34;
    float a41, a42, a43, a44;

    //Costrutore identità
    Matrix4x4f();

    Matrix4x4f(float a11, float a12, float a13, float a14,
        float a21, float a22, float a23, float a24,
        float a31, float a32, float a33, float a34,
        float a41, float a42, float a43, float a44);

    Matrix4x4f(float a);

    //Costruttore con 4 vettori messi per riga
    Matrix4x4f(Vector4f row1, Vector4f row2, Vector4f row3, Vector4f row4);

    //Copy Constructor
    Matrix4x4f(const Matrix4x4f& m);

    Matrix4x4f operator+(Matrix4x4f a);
    Matrix4x4f operator-(Matrix4x4f a);

    Matrix4x4f& operator+=(Matrix4x4f s);
    Matrix4x4f& operator-=(Matrix4x4f s);
    Matrix4x4f& operator= (Matrix4x4f s);

    Matrix4x4f operator*(float a);
    Matrix4x4f operator/(float a);

    Matrix4x4f& operator*=(float a);
    Matrix4x4f& operator/=(float a);

    Vector4f operator*(Vector4f& s);
    Matrix4x4f operator*(const Matrix4x4f& m) const;

    Matrix4x4f traspose();
    float det();
    Matrix4x4f inv();

    bool operator==(const Matrix4x4f& other) const;
    bool operator!=(const Matrix4x4f& other) const;

};

ostream& operator<<(ostream& output, Matrix4x4f& v);