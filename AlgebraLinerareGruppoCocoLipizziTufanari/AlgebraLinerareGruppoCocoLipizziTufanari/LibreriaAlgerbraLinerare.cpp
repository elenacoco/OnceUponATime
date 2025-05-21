#include "Vector2f.h"
#include "Vector3f.h"
#include "Vector4f.h"
#include "Matrix2x2f.h"
#include "Matrix3x3f.h"
#include "Matrix4x4f.h"
#include <iostream>

using namespace std;

int main()
{
    Vector2f v1_2f(0.1f, 0.2f);
    Vector2f v2_2f(0.1f, 0.3f);
    Vector2f v3_2f(0.1f, 0.2f);
    Vector2f v4_2f;


    float n = 0.3f;

    cout << "=== Test classe Vector2f ===\n" << endl;

    // Stampa dei vettori2f
    cout << "[Vector2f v1]: " << v1_2f << endl;
    cout << "[Vector2f v2]: " << v2_2f << endl;
    cout << "[Vector2f v3]: " << v3_2f << endl;
    cout << "[Vector2f v4]: " << v4_2f << endl;

    v4_2f = v1_2f;  // Usa operator=
    cout << "[Operator= -> v4=v1] "<< "v1 = " << v1_2f << ", v4 = " << v4_2f <<  endl; 
  

    // Operator+
    cout << "[Somma di due Vector2f (operator+)] ";
    cout << v1_2f << " + " << v2_2f << " = ";
    Vector2f vsommauguale_2f = v1_2f + v2_2f;
    cout << vsommauguale_2f << endl;

    // Operator+=
    Vector2f v1_copy_add = v1_2f;
    cout << "[Somma di due Vector2f (operator+=)] ";
    cout << v1_copy_add << " += " << v2_2f << " = ";
    v1_copy_add += v2_2f;
    cout << v1_copy_add << endl;

    // Operator-
    cout << "[Differenza di due Vector2f (operator-)] ";
    cout << v1_2f << " - " << v2_2f << " = ";
    Vector2f vdiff_2f = v1_2f - v2_2f;
    cout << vdiff_2f << endl;

    // Operator-=
    Vector2f v1_copy_sub_eq = v1_2f;
    cout << "[Differenza di due Vector2f (operator-=)] ";
    cout << v1_copy_sub_eq << " -= " << v2_2f << " = ";
    v1_copy_sub_eq -= v2_2f;
    cout << v1_copy_sub_eq << endl;

    // Prodotto per scalare
    Vector2f vprod_2f = v1_2f * n;
    cout << "[Prodotto Vector2f * float] ";
    cout << v1_2f << " * " << n << " = " << vprod_2f << endl;

    // Divisione per scalare
    Vector2f vdiv_2f = v1_2f / n;
    cout << "[Divisione di Vector2f per float] ";
    cout << v1_2f << " / " << n << " = " << vdiv_2f << endl;

   // //Operator* (n*v)
   //// Vector2f prodnv_2f = n * v1_2f;  // chiama operator*(float, Vector2f)

   // cout << "[Prodotto float  * Vector2f] ";
   // cout << n << " * " << v1_2f << " = " << prodnv_2f << endl;
 
    // Prodotto scalare
    float dot_2f = v1_2f.dotProd(v2_2f);
    cout << "[Prodotto scalare di due Vector2f] ";
    cout << v1_2f << " scalar " << v2_2f << " = " << dot_2f << endl;

    // Lunghezza
    cout << "[Lunghezza di un Vector2f] |" << v1_2f << "| = " << v1_2f.norm() << endl;

    // Normalizzazione (in-place)
    Vector2f vnorm_copy_2f = v1_2f;
    cout << "[Normalizzazione di un Vector2f (in-place)] ";
    cout << vnorm_copy_2f << " -> ";
    vnorm_copy_2f.normalize();
    cout << vnorm_copy_2f << endl;

    // Normalizzazione (getNormalized)
    Vector2f vnorm_2f = v1_2f.getNormalized();
    cout << "[Normalizzazione di un Vector2f (non distruttiva)] ";
    cout << v1_2f << " -> " << vnorm_2f << endl;


    cout << boolalpha; // stampa "true"/"false" invece di 1/0
    cout << "v1 == v2? " << (v1_2f == v2_2f) << endl; // false
    cout << "v1 != v3? " << (v1_2f != v3_2f) << endl; // false

    cout << "\n=== Fine test classe Vector2f ===\n\n" << endl;



    //VECTOR3F
    Vector3f v1_3f(0.1f, 0.2f, 0.3f);
    Vector3f v2_3f(0.4f, 0.5f, 0.7f);
    Vector3f v3_3f(0.5f, 0.29f, 0.9f);
    Vector3f v4_3f;


    cout << "=== Test classe Vector3f ===\n" << endl;
    // Stampa dei vettori3f
    cout << "[Vector3f v1]: " << v1_3f << endl;
    cout << "[Vector3f v2]: " << v2_3f << endl;
    cout << "[Vector3f v3]: " << v3_3f << endl;
    cout << "[Vector3f v4]: " << v4_3f << endl;


    v4_3f = v1_3f;  // Usa operator=
    cout << "[Operator= -> v4=v1] " << "v1 = " << v1_3f << ", v4 = " << v4_3f << endl;

    // Operator+
    cout << "[Somma di due Vector3f (operator+)] ";
    cout << v1_3f << " + " << v2_3f << " = ";
    Vector3f vsommauguale_3f = v1_3f + v2_3f;
    cout << vsommauguale_3f << endl;

    // Operator+=
    Vector3f v1_copy_add_3f = v1_3f;
    cout << "[Somma di due Vector3f (operator+=)] ";
    cout << v1_copy_add_3f << " += " << v2_3f << " = ";
    v1_copy_add_3f += v2_3f;
    cout << v1_copy_add_3f << endl;

    // Operator-
    cout << "[Differenza di due Vector3f (operator-)] ";
    cout << v1_3f << " - " << v2_3f << " = ";
    Vector3f vdiff_3f = v1_3f - v2_3f;
    cout << vdiff_3f << endl;

    // Operator-=
    Vector3f v1_copy_sub_eq_3f = v1_3f;
    cout << "[Differenza di due Vector3f (operator-=)] ";
    cout << v1_copy_sub_eq_3f << " -= " << v2_3f << " = ";
    v1_copy_sub_eq_3f -= v2_3f;
    cout << v1_copy_sub_eq_3f << endl;


    // Prodotto per scalare
    Vector3f vprod_3f = v1_3f * n;
    cout << "[Prodotto Vector3f * float] ";
    cout << v1_3f << " * " << n << " = " << vprod_3f << endl;

    // Divisione per scalare
    Vector3f vdiv_3f = v1_3f / n;
    cout << "[Divisione di Vector3f per float] ";
    cout << v1_3f << " / " << n << " = " << vdiv_3f << endl;

    ////Operator* (n*v)
    //Vector3f prodnv_3f = n * v1_3f;  // chiama operator*(float, Vector3f)
    //cout << "[Prodotto float  * Vector3f] ";
    //cout << n << " * " << v1_3f << " = " << prodnv_3f << endl;

    // Prodotto scalare
    float dot_3f = v1_3f.dotProd(v2_3f);
    cout << "[Prodotto scalare di due Vector3f] ";
    cout << v1_3f << " scalar " << v2_3f << " = " << dot_3f << endl;

    //// Prodotto vettoriale
    Vector3f cross_3f = v1_3f.crossProd(v2_3f);
    cout << "[Prodotto vettoriale di due Vector3f] ";
    cout << v1_3f << " x " << v2_3f << "=" << cross_3f << endl;

    // Lunghezza
    cout << "[Lunghezza di un Vector3f] |v1| = " << v1_3f.norm() << endl;

    // Normalizzazione (in-place)
    Vector3f vnorm_copy_3f = v1_3f;
    cout << "[Normalizzazione di un Vector3f (in-place)] ";
    cout << vnorm_copy_3f << " -> ";
    vnorm_copy_3f.normalize();
    cout << vnorm_copy_3f << endl;

    // Normalizzazione (getNormalized)
    Vector3f vnorm_3f = v1_3f.getNormalized();
    cout << "[Normalizzazione di un Vector3f (non distruttiva)] ";
    cout << v1_3f << " -> " << vnorm_3f << endl;


    cout << boolalpha; // stampa "true"/"false" invece di 1/0
    cout << "v1 == v2? " << (v1_3f == v2_3f) << endl; // false
    cout << "v1 != v3? " << (v1_3f != v3_3f) << endl; // false


    cout << "\n=== Fine test classe Vector3f ===\n\n" << endl;


     // VECTOR4F
    cout << "=== Test classe Vector4f ===\n" << endl;

    Vector4f v1_4f(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4f v2_4f(0.5f, 1.5f, -1.0f, 2.0f);
    Vector4f v3_4f(0.5f, 1.5f, -1.0f, 2.0f);
    Vector4f v4_4f;


    // Stampa dei vettori3f
    cout << "[Vector4f v1]: " << v1_4f << endl;
    cout << "[Vector4f v2]: " << v2_4f << endl;
    cout << "[Vector4f v3]: " << v3_4f << endl;
    cout << "[Vector4f v4]: " << v4_4f << endl;

    v4_4f = v1_4f;  // Usa operator=
    cout << "[Operator= -> v4=v1] " << "v1 = " << v1_4f << ", v4 = " << v4_4f << endl;

    // Operator+
    cout << "[Somma di due Vector4f (operator+)] ";
    cout << v1_4f << " + " << v2_4f << " = ";
    Vector4f vsommauguale_4f = v1_4f + v2_4f;
    cout << vsommauguale_4f << endl;

    // Operator+=
    Vector4f v1_copy_add_4f = v1_4f;
    cout << "[Somma di due Vector4f (operator+=)] ";
    cout << v1_copy_add_4f << " += " << v2_4f << " = ";
    v1_copy_add_4f += v2_4f;
    cout << v1_copy_add_4f << endl;

    // Operator-
    cout << "[Differenza di due Vector4f (operator-)] ";
    cout << v1_4f << " - " << v2_4f << " = ";
    Vector4f vdiff_4f = v1_4f - v2_4f;
    cout << vdiff_4f << endl;

    // Operator-=
    Vector4f v1_copy_sub_eq_4f = v1_4f;
    cout << "[Differenza di due Vector4f (operator-=)] ";
    cout << v1_copy_sub_eq_4f << " -= " << v2_4f << " = ";
    v1_copy_sub_eq_4f -= v2_4f;
    cout << v1_copy_sub_eq_4f << endl;

    // Prodotto per scalare
    Vector4f vprod_4f = v1_4f * n;
    cout << "[Prodotto Vector4f * float] ";
    cout << v1_4f << " * " << n << " = " << vprod_4f << endl;

    // Divisione per scalare
    Vector4f vdiv_4f = v1_4f / n;
    cout << "[Divisione di Vector4f per float] ";
    cout << v1_4f << " / " << n << " = " << vdiv_4f << endl;

    ////Operator* (n*v)
    //Vector4f prodnv_4f = n * v1_4f;  // chiama operator*(float, Vector3f)
    //cout << "[Prodotto float  * Vector4f] ";
    //cout << n << " * " << v1_4f << " = " << prodnv_4f << endl;

    // Prodotto scalare
    float dot_4f = v1_4f.dotProd(v2_4f);
    cout << "[Prodotto scalare di due Vector4f] ";
    cout << v1_4f << " scalar " << v2_4f << " = " << dot_4f << endl;

   

    // Lunghezza
        cout << "[Lunghezza di un Vector4f] |v1| = " << v1_4f.norm() << endl;

    // Normalizzazione (in-place)
    Vector4f vnorm_copy_4f = v1_4f;
    cout << "[Normalizzazione di un Vector4f (in-place)] ";
    cout << vnorm_copy_4f << " -> ";
    vnorm_copy_4f.normalize();
    cout << vnorm_copy_4f << endl;

    // Normalizzazione (getNormalized)
    Vector4f vnorm_4f = v1_4f.getNormalized();
    cout << "[Normalizzazione di un Vector4f (non distruttiva)] ";
    cout << v1_4f << " -> " << vnorm_4f << endl;


    cout << boolalpha; // stampa "true"/"false" invece di 1/0
    cout << "v1 == v2? " << (v1_4f == v2_4f) << endl; // false
    cout << "v1 != v3? " << (v1_4f != v3_4f) << endl; // false


    cout << "\n=== Fine test Vector4f ===" << endl;

    // Test Matrix2x2f
    cout << "=== Test classe Matrix2x2f ===\n" << endl;

    // Creazione di tre matrici
    Matrix2x2f m1_2x2(1.0f, 2.0f,
                      2.0f, 4.0f
                 );

    Matrix2x2f m2_2x2(9.0f, 8.0f,
                      6.0f, 5.0f );


    Matrix2x2f m3_2x2(8.0f, 8.0f, 
                      6.0f, 5.0f
                     );

    Matrix2x2f m4_2x2(8.0f);


    float scalare = 2.4;


    // Stampa delle matrici
    // Stampa delle matrici con una formattazione migliore
    cout << "---------------------------------" << endl;
    cout << "Matrix 1: " << endl << m1_2x2 << endl;
    cout << "Matrix 2: " << endl << m2_2x2 << endl;
    cout << "Matrix 3: " << endl << m3_2x2 << endl;
    cout << "Matrix 4: " << endl << m4_2x2 << endl;

    // Operazione di somma
    Matrix2x2f mSomma_2x2 = m1_2x2 + m2_2x2;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Somma di Matrix1 e Matrix2" << endl;
    cout << "Matrix 1 + Matrix 2 =  "<< endl << mSomma_2x2 << endl;



    // Operazione di differenza
    Matrix2x2f mDifferenza_2x2 = m1_2x2 - m2_2x2;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Differenza di Matrix1 e Matrix2" << endl;
    cout << "Risultato: Matrix 1 - Matrix 2 = " << endl<< mDifferenza_2x2 << endl;

    // Operazione di prodotto con scalare
    Matrix2x2f mProdotto_2x2 = m1_2x2 * scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * scalare" << endl;
    cout << "Risultato: Matrix 1 * " << scalare << " = "<< endl << mProdotto_2x2 << endl;

    // Operazione di divisione per scalare
    Matrix2x2f mDivisione_2x2 = m1_2x2 / scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 / scalare" << endl;
    cout << "Risultato: Matrix 1 / " << scalare << " = "<<endl << mDivisione_2x2 << endl;
   

    cout << "========== TEST OPERATORI DI ASSEGNAZIONE ==========" << endl;

    // Partenza: Matrix1 e Matrix2
    cout << "Matrix 1 (iniziale):" << endl << m1_2x2 << endl;
    cout << "Matrix 2:" << endl << m2_2x2 << endl;

    // Test operator+=
    Matrix2x2f mTest1_2x2 = m1_2x2;
    mTest1_2x2 += m2_2x2;
    cout << "Dopo Matrix1 += Matrix2:" << endl << mTest1_2x2 << endl;

    // Test operator-=
    Matrix2x2f mTest2_2x2 = m1_2x2;
    mTest2_2x2 -= m2_2x2;
    cout << "Dopo Matrix1 -= Matrix2:" << endl << mTest2_2x2 << endl;

    // Test operator=
    Matrix2x2f mTest3_2x2;
    cout <<"Prima di fare m3=Matrix2"<<endl << mTest3_2x2 << endl;
    mTest3_2x2 = m2_2x2;
    cout << "Dopo Matrix(nulla) = Matrix2:" << endl << mTest3_2x2 << endl;


    // Test operatore *= scalare
    Matrix2x2f mTest4_2x2 = m1_2x2;

   mTest4_2x2 *= scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix *= scalare (" << scalare << ")" << endl;
    cout << "Risultato: " << endl << mTest4_2x2 << endl;

    // Test operatore /= scalare
    Matrix2x2f mTest5_2x2 = m1_2x2;

    mTest5_2x2 /= scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix /= scalare (" << scalare << ")" << endl;
    cout << "Risultato: " << endl << mTest5_2x2 << endl;
    cout << "---------------------------------" << endl;

    cout << "====================================================" << endl;

    // Prodotto matrice per matrice
    Matrix2x2f mProdottoMatriciale_2x2 = m1_2x2 * m2_2x2;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * Matrix2 = " << endl << mProdottoMatriciale_2x2 << endl;

    // Prodotto matrice per vettore
    Vector2f vProdotto_2x2 = m1_2x2 * v1_2f;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * Vector2f = " << endl << m1_2x2 << "*" << v1_2f << "=" << endl;
    cout << vProdotto_2x2 <<endl;
    
   

    ////Calcolare determinante
    float determinante_2x2 = m1_2x2.det();
    cout << "---------------------------------" << endl;
    cout << "Operazione: determinanante di Matrix1 = " << endl << determinante_2x2 << endl;

    ////Calcolo L'inversa
    Matrix2x2f noninv_2x2 = m1_2x2.inv();
    cout << "---------------------------------" << endl;
    cout << "Operazione: inversa di una matrice(ritorna la stessa matrice xche proporzioal = "<< endl <<noninv_2x2<<endl;
   

    ////Calcolo L'inversa
    Matrix2x2f inv_2x2 = m2_2x2.inv();
    cout << "---------------------------------" << endl;
    cout << "Operazione: inversa di una matrice = " << endl << inv_2x2 << endl;


    //Calcolo la trasposta
    Matrix2x2f tras_2x2 = m2_2x2.traspose();
    cout << "---------------------------------" << endl;
    cout << "Operazione: trasposta di una matrice = " << endl << tras_2x2;

    //Operatori == e !=
    cout << "---------------------------------" << endl;
    cout << boolalpha; // stampa "true"/"false" invece di 1/0
    cout << "Matrix1 == Matrix2?  " << (m1_2x2 == m2_2x2) << endl;
    cout << "Matrix1 != Matrix2?  " << (m1_2x2 != m2_2x2) << endl;


  
    cout << "\n=== Fine test Matrix2x2f ===\n\n" << endl;

    // Test Matrix3x3f
    cout << "=== Test classe Matrix3x3f ===\n" << endl;

    // Creazione di tre matrici
    Matrix3x3f m1_3x3(1.0f, 2.0f, 3.0f,
                      4.0f, 5.0f, 6.0f,
                      7.0f, 8.0f, 9.0f);

    Matrix3x3f m2_3x3(9.0f, 8.0f, 7.0f,
                      6.0f, 5.0f, 4.0f,
                      3.0f, 2.0f, 1.0f);


    Matrix3x3f m3_3x3(8.0f, 8.0f, 7.0f,
                      6.0f, 5.0f, 4.0f,
                      3.0f, 2.0f, 1.0f);

    Matrix3x3f m4_3x3(1.2f);
    // Stampa delle matrici
     // Stampa delle matrici con una formattazione migliore
    cout << "---------------------------------" << endl;
    cout << "Matrix 1: " << endl << m1_3x3 << endl;
    cout << "Matrix 2: " << endl << m2_3x3 << endl;
    cout << "Matrix 3: " << endl << m3_3x3 << endl;
    cout << "Matrix 4: " << endl << m4_3x3 << endl;

    // Operazione di somma
    Matrix3x3f mSomma_3x3 = m1_3x3 + m2_3x3;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Somma di Matrix1 e Matrix2" << endl;
    cout << "Matrix 1 + Matrix 2 =  " << endl << mSomma_3x3 << endl;
    


    // Operazione di differenza
    Matrix3x3f mDifferenza_3x3 = m1_3x3 - m2_3x3;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Differenza di Matrix1 e Matrix2" << endl;
    cout << "Risultato: Matrix 1 - Matrix 2 = " << endl << mDifferenza_3x3 << endl;

    // Operazione di prodotto con scalare
    Matrix3x3f mProdotto_3x3 = m1_3x3 * scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * scalare" << endl;
    cout << "Risultato: Matrix 1 * " << scalare << " = " << endl << mProdotto_3x3 << endl;

    // Operazione di divisione per scalare
    Matrix3x3f mDivisione_3x3 = m1_3x3 / scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 / scalare" << endl;
    cout << "Risultato: Matrix 1 / " << scalare << " = " << endl << mDivisione_3x3 << endl;


    cout << "========== TEST OPERATORI DI ASSEGNAZIONE ==========" << endl;

    // Partenza: Matrix1 e Matrix2
    cout << "Matrix 1 (iniziale):" << endl << m1_3x3 << endl;
    cout << "Matrix 2:" << endl << m2_3x3 << endl;

    // Test operator+=
    Matrix3x3f mTest1_3x3 = m1_3x3;
    mTest1_3x3 += m2_3x3;
    cout << "Dopo Matrix1 += Matrix2:" << endl << mTest1_3x3 << endl;

    // Test operator-=
    Matrix3x3f mTest2_3x3 = m1_3x3;
    mTest2_3x3 -= m2_3x3;
    cout << "Dopo Matrix1 -= Matrix2:" << endl << mTest2_3x3 << endl;

    // Test operator=
    Matrix3x3f mTest3_3x3;
    cout << "Prima di fare m3=Matrix2" << endl << mTest3_3x3 << endl;
    mTest3_3x3 = m2_3x3;
    cout << "Dopo Matrix(nulla) = Matrix2:" << endl << mTest3_3x3 << endl;


    // Test operatore *= scalare
    Matrix3x3f mTest4_3x3 = m1_3x3;

    mTest4_3x3 *= scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix *= scalare (" << scalare << ")" << endl;
    cout << "Risultato: " << endl << mTest4_3x3 << endl;

    // Test operatore /= scalare
    Matrix3x3f mTest5_3x3 = m1_3x3;

    mTest5_3x3 /= scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix /= scalare (" << scalare << ")" << endl;
    cout << "Risultato: " << endl << mTest5_3x3 << endl;
    cout << "---------------------------------" << endl;

    cout << "====================================================" << endl;

    // Prodotto matrice per matrice
    Matrix3x3f mProdottoMatriciale_3x3 = m1_3x3 * m2_3x3;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * Matrix2 = " << endl << mProdottoMatriciale_3x3 << endl;

    // Prodotto matrice per vettore
    Vector3f vProdotto_3x3 = m1_3x3 * v1_3f;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * Vector2f = " << endl << m1_3x3 << "*" << v1_3f << "=" << endl;
    cout << vProdotto_3x3 << endl;



    ////Calcolare determinante
    float determinante_3x3 = m1_3x3.det();
    cout << "---------------------------------" << endl;
    cout << "Operazione: determinanante di Matrix1 = " << endl << determinante_3x3 << endl;

    ////Calcolo L'inversa
    Matrix3x3f noninv_3x3 = m1_3x3.inv();
    cout << "---------------------------------" << endl;
    cout << "Operazione: inversa di una matrice(ritorna la stessa matrice xche proporzioal = " << endl << noninv_3x3 << endl;


    ////Calcolo L'inversa
    Matrix3x3f inv_3x3 = m2_3x3.inv();
    cout << "---------------------------------" << endl;
    cout << "Operazione: inversa di una matrice = " << endl << inv_3x3 << endl;


    //Calcolo la trasposta
    Matrix3x3f tras_3x3 = m2_3x3.traspose();
    cout << "---------------------------------" << endl;
    cout << "Operazione: trasposta di una matrice = " << endl << tras_3x3;

    //Operatori == e !=
    cout << "---------------------------------" << endl;
    cout << boolalpha; // stampa "true"/"false" invece di 1/0
    cout << "Matrix1 == Matrix2?  " << (m1_3x3 == m2_3x3) << endl;
    cout << "Matrix1 != Matrix2?  " << (m1_3x3 != m2_3x3) << endl;



    cout << "\n=== Fine test Matrix3x3f ===\n\n" << endl;



    // Test Matrix4x4f
    cout << "=== Test classe Matrix4x4f ===\n" << endl;

    // Creazione di tre matrici
    Matrix4x4f m1_4x4(
        1.0f, 2.0f, 3.0f, 10.0f,
        4.0f, 5.0f, 6.0f, 11.0f,
        7.0f, 8.0f, 9.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    );

    Matrix4x4f m2_4x4(
        9.0f, 8.0f, 7.0f, 6.0f,
        6.0f, 5.0f, 4.0f, 3.0f,
        3.0f, 2.0f, 1.0f, 0.0f,
        1.0f, 2.0f, 3.0f, 4.0f
    );

    Matrix4x4f m3_4x4(
        8.0f, 8.0f, 7.0f, 6.0f,
        6.0f, 5.0f, 4.0f, 3.0f,
        3.0f, 2.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 2.0f, 3.0f
    );


    Matrix3x3f m4_4x4(1.2f);
    // Stampa delle matrici
     // Stampa delle matrici con una formattazione migliore
    cout << "---------------------------------" << endl;
    cout << "Matrix 1: " << endl << m1_4x4 << endl;
    cout << "Matrix 2: " << endl << m2_4x4 << endl;
    cout << "Matrix 3: " << endl << m3_4x4 << endl;
    //cout << "Matrix 4: " << endl << m4_4x4 << endl;

    // Operazione di somma
    Matrix4x4f mSomma_4x4 = m1_4x4 + m2_4x4;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Somma di Matrix1 e Matrix2" << endl;
    cout << "Matrix 1 + Matrix 2 =  " << endl << mSomma_4x4 << endl;



    // Operazione di differenza
    Matrix4x4f mDifferenza_4x4 = m1_4x4 - m2_4x4;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Differenza di Matrix1 e Matrix2" << endl;
    cout << "Risultato: Matrix 1 - Matrix 2 = " << endl << mDifferenza_4x4 << endl;

    // Operazione di prodotto con scalare
    Matrix4x4f mProdotto_4x4 = m1_4x4 * scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * scalare" << endl;
    cout << "Risultato: Matrix 1 * " << scalare << " = " << endl << mProdotto_4x4 << endl;

    // Operazione di divisione per scalare
    Matrix4x4f mDivisione_4x4 = m1_4x4 / scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 / scalare" << endl;
    cout << "Risultato: Matrix 1 / " << scalare << " = " << endl << mDivisione_4x4 << endl;

    cout << "========== TEST OPERATORI DI ASSEGNAZIONE ==========" << endl;

    // Partenza: Matrix1 e Matrix2
    cout << "Matrix 1 (iniziale):" << endl << m1_4x4 << endl;
    cout << "Matrix 2:" << endl << m2_4x4 << endl;

    // Test operator+=
    Matrix4x4f mTest1_4x4 = m1_4x4;
    mTest1_4x4 += m2_4x4;
    cout << "Dopo Matrix1 += Matrix2:" << endl << mTest1_4x4 << endl;

    // Test operator-=
    Matrix4x4f mTest2_4x4 = m1_4x4;
    mTest2_4x4 -= m2_4x4;
    cout << "Dopo Matrix1 -= Matrix2:" << endl << mTest2_4x4 << endl;

    // Test operator=
    Matrix4x4f mTest3_4x4;
    cout << "Prima di fare m3=Matrix2" << endl << mTest3_4x4 << endl;
    mTest3_4x4 = m2_4x4;
    cout << "Dopo Matrix(nulla) = Matrix2:" << endl << mTest3_4x4 << endl;

    // Test operatore *= scalare
    Matrix4x4f mTest4_4x4 = m1_4x4;
    mTest4_4x4 *= scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix *= scalare (" << scalare << ")" << endl;
    cout << "Risultato: " << endl << mTest4_4x4 << endl;

    // Test operatore /= scalare
    Matrix4x4f mTest5_4x4 = m1_4x4;
    mTest5_4x4 /= scalare;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix /= scalare (" << scalare << ")" << endl;
    cout << "Risultato: " << endl << mTest5_4x4 << endl;
    cout << "---------------------------------" << endl;

    cout << "====================================================" << endl;

    // Prodotto matrice per matrice
    Matrix4x4f mProdottoMatriciale_4x4 = m1_4x4 * m2_4x4;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * Matrix2 = " << endl << mProdottoMatriciale_4x4 << endl;

    // Prodotto matrice per vettore
    Vector4f vProdotto_4x4 = m1_4x4 * v1_4f;
    cout << "---------------------------------" << endl;
    cout << "Operazione: Matrix1 * Vector4f = " << endl << m1_4x4 << "*" << v1_4f << "=" << endl;
    cout << vProdotto_4x4 << endl;

    // Calcolare determinante
    float determinante_4x4 = m1_4x4.det();
    cout << "---------------------------------" << endl;
    cout << "Operazione: determinanante di Matrix1 = " << endl << determinante_4x4 << endl;

    // Calcolo dell'inversa
    Matrix4x4f noninv_4x4 = m1_4x4.inv();
    cout << "---------------------------------" << endl;
    cout << "Operazione: inversa di una matrice (ritorna la stessa matrice se non invertibile) = " << endl << noninv_4x4 << endl;

    Matrix4x4f inv_4x4 = m2_4x4.inv();
    cout << "---------------------------------" << endl;
    cout << "Operazione: inversa di una matrice = " << endl << inv_4x4 << endl;

    // Calcolo la trasposta
    Matrix4x4f tras_4x4 = m2_4x4.traspose();
    cout << "---------------------------------" << endl;
    cout << "Operazione: trasposta di una matrice = " << endl << tras_4x4;

    // Operatori == e !=
    cout << "---------------------------------" << endl;
    cout << boolalpha;
    cout << "Matrix1 == Matrix2?  " << (m1_4x4 == m2_4x4) << endl;
    cout << "Matrix1 != Matrix2?  " << (m1_4x4 != m2_4x4) << endl;

    cout << "\n=== Fine test Matrix4x4f ===\n\n" << endl;


    return 0;
}
