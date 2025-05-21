#include <iostream>
#include <iomanip>
#include <cmath>
#include "Matrix3x3f.h"
#include "Matrix4x4f.h"
#include "Vector4f.h"

using namespace std;
//sto impazzendo

Matrix4x4f::Matrix4x4f() {
    a11 = 1; a12 = 0; a13 = 0; a14 = 0;
    a21 = 0; a22 = 1; a23 = 0; a24 = 0;
    a31 = 0; a32 = 0; a33 = 1; a34 = 0;
    a41 = 0; a42 = 0; a43 = 0; a44 = 1;
}

Matrix4x4f::Matrix4x4f(float a) {
    a11 = a12 = a13 = a14 = a;
    a21 = a22 = a23 = a24 = a;
    a31 = a32 = a33 = a34 = a;
    a41 = a42 = a43 = a44 = a;
}

Matrix4x4f::Matrix4x4f(float a11, float a12, float a13, float a14,
    float a21, float a22, float a23, float a24,
    float a31, float a32, float a33, float a34,
    float a41, float a42, float a43, float a44) {
    this->a11 = a11; this->a12 = a12; this->a13 = a13; this->a14 = a14;
    this->a21 = a21; this->a22 = a22; this->a23 = a23; this->a24 = a24;
    this->a31 = a31; this->a32 = a32; this->a33 = a33; this->a34 = a34;
    this->a41 = a41; this->a42 = a42; this->a43 = a43; this->a44 = a44;
}

Matrix4x4f Matrix4x4f::operator+(Matrix4x4f other) {
    return Matrix4x4f(
        a11 + other.a11, a12 + other.a12, a13 + other.a13, a14 + other.a14,
        a21 + other.a21, a22 + other.a22, a23 + other.a23, a24 + other.a24,
        a31 + other.a31, a32 + other.a32, a33 + other.a33, a34 + other.a34,
        a41 + other.a41, a42 + other.a42, a43 + other.a43, a44 + other.a44
    );
}

Matrix4x4f Matrix4x4f::operator-(Matrix4x4f other) {
    return Matrix4x4f(
        a11 - other.a11, a12 - other.a12, a13 - other.a13, a14 - other.a14,
        a21 - other.a21, a22 - other.a22, a23 - other.a23, a24 - other.a24,
        a31 - other.a31, a32 - other.a32, a33 - other.a33, a34 - other.a34,
        a41 - other.a41, a42 - other.a42, a43 - other.a43, a44 - other.a44
    );
}

Matrix4x4f Matrix4x4f::operator*(float a) {
    return Matrix4x4f(
        a11 * a, a12 * a, a13 * a, a14 * a,
        a21 * a, a22 * a, a23 * a, a24 * a,
        a31 * a, a32 * a, a33 * a, a34 * a,
        a41 * a, a42 * a, a43 * a, a44 * a
    );
}

Matrix4x4f Matrix4x4f::operator/(float a) {
    if (a != 0) {
        return Matrix4x4f(
            a11 / a, a12 / a, a13 / a, a14 / a,
            a21 / a, a22 / a, a23 / a, a24 / a,
            a31 / a, a32 / a, a33 / a, a34 / a,
            a41 / a, a42 / a, a43 / a, a44 / a
        );
    }
    else {
        cout << "Errore: divisione per zero in Matrix4x4f::operator/" << endl;
        return Matrix4x4f();
    }
}

Matrix4x4f& Matrix4x4f::operator+=(Matrix4x4f s) {
    a11 += s.a11; a12 += s.a12; a13 += s.a13; a14 += s.a14;
    a21 += s.a21; a22 += s.a22; a23 += s.a23; a24 += s.a24;
    a31 += s.a31; a32 += s.a32; a33 += s.a33; a34 += s.a34;
    a41 += s.a41; a42 += s.a42; a43 += s.a43; a44 += s.a44;
    return *this;
}

Matrix4x4f& Matrix4x4f::operator-=(Matrix4x4f s) {
    a11 -= s.a11; a12 -= s.a12; a13 -= s.a13; a14 -= s.a14;
    a21 -= s.a21; a22 -= s.a22; a23 -= s.a23; a24 -= s.a24;
    a31 -= s.a31; a32 -= s.a32; a33 -= s.a33; a34 -= s.a34;
    a41 -= s.a41; a42 -= s.a42; a43 -= s.a43; a44 -= s.a44;
    return *this;
}

Matrix4x4f& Matrix4x4f::operator=(Matrix4x4f s) {
    a11 = s.a11; a12 = s.a12; a13 = s.a13; a14 = s.a14;
    a21 = s.a21; a22 = s.a22; a23 = s.a23; a24 = s.a24;
    a31 = s.a31; a32 = s.a32; a33 = s.a33; a34 = s.a34;
    a41 = s.a41; a42 = s.a42; a43 = s.a43; a44 = s.a44;
    return *this;
}

Matrix4x4f& Matrix4x4f::operator*=(float s) {
    a11 *= s; a12 *= s; a13 *= s; a14 *= s;
    a21 *= s; a22 *= s; a23 *= s; a24 *= s;
    a31 *= s; a32 *= s; a33 *= s; a34 *= s;
    a41 *= s; a42 *= s; a43 *= s; a44 *= s;
    return *this;
}

Matrix4x4f& Matrix4x4f::operator/=(float s) {
    if (s != 0.0f) {
        a11 /= s; a12 /= s; a13 /= s; a14 /= s;
        a21 /= s; a22 /= s; a23 /= s; a24 /= s;
        a31 /= s; a32 /= s; a33 /= s; a34 /= s;
        a41 /= s; a42 /= s; a43 /= s; a44 /= s;
    }
    else {
        cout << "Errore: divisione per zero in Matrix4x4f::operator/=" << endl;
    }
    return *this;
}

Vector4f Matrix4x4f::operator*(Vector4f& v) {
    float x = a11 * v.x + a12 * v.y + a13 * v.z + a14 * v.w;
    float y = a21 * v.x + a22 * v.y + a23 * v.z + a24 * v.w;
    float z = a31 * v.x + a32 * v.y + a33 * v.z + a34 * v.w;
    float w = a41 * v.x + a42 * v.y + a43 * v.z + a44 * v.w;
    return Vector4f(x, y, z, w);
}

Matrix4x4f Matrix4x4f::operator*(const Matrix4x4f& other) const {
    float m11 = a11 * other.a11 + a12 * other.a21 + a13 * other.a31 + a14 * other.a41;
    float m12 = a11 * other.a12 + a12 * other.a22 + a13 * other.a32 + a14 * other.a42;
    float m13 = a11 * other.a13 + a12 * other.a23 + a13 * other.a33 + a14 * other.a43;
    float m14 = a11 * other.a14 + a12 * other.a24 + a13 * other.a34 + a14 * other.a44;

    float m21 = a21 * other.a11 + a22 * other.a21 + a23 * other.a31 + a24 * other.a41;
    float m22 = a21 * other.a12 + a22 * other.a22 + a23 * other.a32 + a24 * other.a42;
    float m23 = a21 * other.a13 + a22 * other.a23 + a23 * other.a33 + a24 * other.a43;
    float m24 = a21 * other.a14 + a22 * other.a24 + a23 * other.a34 + a24 * other.a44;

    float m31 = a31 * other.a11 + a32 * other.a21 + a33 * other.a31 + a34 * other.a41;
    float m32 = a31 * other.a12 + a32 * other.a22 + a33 * other.a32 + a34 * other.a42;
    float m33 = a31 * other.a13 + a32 * other.a23 + a33 * other.a33 + a34 * other.a43;
    float m34 = a31 * other.a14 + a32 * other.a24 + a33 * other.a34 + a34 * other.a44;

    float m41 = a41 * other.a11 + a42 * other.a21 + a43 * other.a31 + a44 * other.a41;
    float m42 = a41 * other.a12 + a42 * other.a22 + a43 * other.a32 + a44 * other.a42;
    float m43 = a41 * other.a13 + a42 * other.a23 + a43 * other.a33 + a44 * other.a43;
    float m44 = a41 * other.a14 + a42 * other.a24 + a43 * other.a34 + a44 * other.a44;

    return Matrix4x4f(
        m11, m12, m13, m14,
        m21, m22, m23, m24,
        m31, m32, m33, m34,
        m41, m42, m43, m44
    );
}

Matrix4x4f Matrix4x4f::traspose() {
    return Matrix4x4f(
        a11, a21, a31, a41,
        a12, a22, a32, a42,
        a13, a23, a33, a43,
        a14, a24, a34, a44
    );
}

float Matrix4x4f::det() {
    Matrix3x3f minor1(
        a22, a23, a24,
        a32, a33, a34,
        a42, a43, a44
    );

    Matrix3x3f minor2(
        a21, a23, a24,
        a31, a33, a34,
        a41, a43, a44
    );

    Matrix3x3f minor3(
        a21, a22, a24,
        a31, a32, a34,
        a41, a42, a44
    );

    Matrix3x3f minor4(
        a21, a22, a23,
        a31, a32, a33,
        a41, a42, a43
    );

    return a11 * minor1.det()
        - a12 * minor2.det()
        + a13 * minor3.det()
        - a14 * minor4.det();
}

Matrix4x4f Matrix4x4f::inv()  {
    Matrix4x4f inv;
    // Calcolo dei minori (determinanti delle sottodeterminanti 3x3)
    float minor11 = a22 * (a33 * a44 - a34 * a43)
        - a23 * (a32 * a44 - a34 * a42)
        + a24 * (a32 * a43 - a33 * a42);
    float minor12 = a21 * (a33 * a44 - a34 * a43)
        - a23 * (a31 * a44 - a34 * a41)
        + a24 * (a31 * a43 - a33 * a41);
    float minor13 = a21 * (a32 * a44 - a34 * a42)
        - a22 * (a31 * a44 - a34 * a41)
        + a24 * (a31 * a42 - a32 * a41);
    float minor14 = a21 * (a32 * a43 - a33 * a42)
        - a22 * (a31 * a43 - a33 * a41)
        + a23 * (a31 * a42 - a32 * a41);

    float minor21 = a12 * (a33 * a44 - a34 * a43)
        - a13 * (a32 * a44 - a34 * a42)
        + a14 * (a32 * a43 - a33 * a42);
    float minor22 = a11 * (a33 * a44 - a34 * a43)
        - a13 * (a31 * a44 - a34 * a41)
        + a14 * (a31 * a43 - a33 * a41);
    float minor23 = a11 * (a32 * a44 - a34 * a42)
        - a12 * (a31 * a44 - a34 * a41)
        + a14 * (a31 * a42 - a32 * a41);
    float minor24 = a11 * (a32 * a43 - a33 * a42)
        - a12 * (a31 * a43 - a33 * a41)
        + a13 * (a31 * a42 - a32 * a41);

    float minor31 = a12 * (a23 * a44 - a24 * a43)
        - a13 * (a22 * a44 - a24 * a42)
        + a14 * (a22 * a43 - a23 * a42);
    float minor32 = a11 * (a23 * a44 - a24 * a43)
        - a13 * (a21 * a44 - a24 * a41)
        + a14 * (a21 * a43 - a23 * a41);
    float minor33 = a11 * (a22 * a44 - a24 * a42)
        - a12 * (a21 * a44 - a24 * a41)
        + a14 * (a21 * a42 - a22 * a41);
    float minor34 = a11 * (a22 * a43 - a23 * a42)
        - a12 * (a21 * a43 - a23 * a41)
        + a13 * (a21 * a42 - a22 * a41);

    float minor41 = a12 * (a23 * a34 - a24 * a33)
                  - a13 * (a22 * a34 - a24 * a32)
                  + a14 * (a22 * a33 - a23 * a32);
    float minor42 = a11 * (a23 * a34 - a24 * a33)
                  - a13 * (a21 * a34 - a24 * a31)
                  + a14 * (a21 * a33 - a23 * a31);
    float minor43 = a11 * (a22 * a34 - a24 * a32)
                  - a12 * (a21 * a34 - a24 * a31)
                  + a14 * (a21 * a32 - a22 * a31);
    float minor44 = a11 * (a22 * a33 - a23 * a32)
                  - a12 * (a21 * a33 - a23 * a31)
                  + a13 * (a21 * a32 - a22 * a31);

    // Calcolo dei cofattori con segno (-1)^(i+j)
    float cof11 = minor11;
    float cof12 = -minor12;
    float cof13 = minor13;
    float cof14 = -minor14;

    float cof21 = -minor21;
    float cof22 = minor22;
    float cof23 = -minor23;
    float cof24 = minor24;

    float cof31 = minor31;
    float cof32 = -minor32;
    float cof33 = minor33;
    float cof34 = -minor34;

    float cof41 = -minor41;
    float cof42 = minor42;
    float cof43 = -minor43;
    float cof44 = minor44;

    // Calcolo del determinante (usando la prima riga dei cofattori)
    float det = a11 * cof11 + a12 * cof12 + a13 * cof13 + a14 * cof14;

    // Se il determinante � zero, restituisci identit� e stampa errore
    if (det == 0.0f) {
        std::cerr << "Errore: determinante uguale a zero; restituisco matrice identit�\n";
        Matrix4x4f I;
        I.a11 = 1.0f; I.a12 = 0.0f; I.a13 = 0.0f; I.a14 = 0.0f;
        I.a21 = 0.0f; I.a22 = 1.0f; I.a23 = 0.0f; I.a24 = 0.0f;
        I.a31 = 0.0f; I.a32 = 0.0f; I.a33 = 1.0f; I.a34 = 0.0f;
        I.a41 = 0.0f; I.a42 = 0.0f; I.a43 = 0.0f; I.a44 = 1.0f;
        return I;
    }

    // Calcolo dell'inversa come matrice aggiunta / determinante
    inv.a11 = cof11 / det;
    inv.a12 = cof21 / det;
    inv.a13 = cof31 / det;
    inv.a14 = cof41 / det;

    inv.a21 = cof12 / det;
    inv.a22 = cof22 / det;
    inv.a23 = cof32 / det;
    inv.a24 = cof42 / det;

    inv.a31 = cof13 / det;
    inv.a32 = cof23 / det;
    inv.a33 = cof33 / det;
    inv.a34 = cof43 / det;

    inv.a41 = cof14 / det;
    inv.a42 = cof24 / det;
    inv.a43 = cof34 / det;
    inv.a44 = cof44 / det;

    return inv;
}




bool Matrix4x4f::operator==(const Matrix4x4f& other) const {
    return a11 == other.a11 && a12 == other.a12 && a13 == other.a13 && a14 == other.a14 &&
           a21 == other.a21 && a22 == other.a22 && a23 == other.a23 && a24 == other.a24 &&
           a31 == other.a31 && a32 == other.a32 && a33 == other.a33 && a34 == other.a34 &&
           a41 == other.a41 && a42 == other.a42 && a43 == other.a43 && a44 == other.a44;
}

bool Matrix4x4f::operator!=(const Matrix4x4f& other) const {
    return !(*this == other);
}



ostream& operator<<(ostream& output, Matrix4x4f& m) {
    output << fixed << setprecision(4);
    output << "[" << m.a11 << ", " << m.a12 << ", " << m.a13 << ", " << m.a14 << "]\n"
           << "[" << m.a21 << ", " << m.a22 << ", " << m.a23 << ", " << m.a24 << "]\n"
           << "[" << m.a31 << ", " << m.a32 << ", " << m.a33 << ", " << m.a34 << "]\n"
           << "[" << m.a41 << ", " << m.a42 << ", " << m.a43 << ", " << m.a44 << "]\n";
    return output;
}
