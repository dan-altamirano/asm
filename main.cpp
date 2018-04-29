#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;
#define PI 3.14159265359

float iround( double $a, double $b ) {
  float $result;
  __asm__ __volatile__(
  "fmovl %1, %%eax;"
  "fmovl %2, %%ebx;"
  "faddl %%ebx,%%eax;"
  "fmovl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
  );
  return $result ;
}
// float sinx( float degree ) {
//     float result, two_right_angles = 180.0f ;
//     /* Convert angle from degrees to radians and then calculate sin value */
//     __asm__ __volatile__ ( "fldl %1;"
//                             "fldl %2;"
//                             "fldpi;"
//                             "fmul;"
//                             "fdiv;"
//                             "fsin;"
//                             "fistpl %0"
//                             "fldl %0;" : "=g" (result) :
//                     				"g"(two_right_angles), "g" (degree)
//     ) ;
//     return result ;
// }

int suma( int $a, int $b ){
    int $result;
    __asm__ __volatile__(
    "movl %1, %%eax;"
    "movl %2, %%ebx;"
    "addl %%ebx,%%eax;"
    "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    return $result ;
}
int resta( int $a, int $b ){
    int $result;
    __asm__ __volatile__(
    "movl %1, %%eax;"
    "movl %2, %%ebx;"
    "subl %%ebx,%%eax;"
    "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    return $result ;
}
int multiplicacion( int $a, int $b ){
    int $result;
    __asm__ __volatile__(
    "movl %1, %%eax;"
    "movl %2, %%ebx;"
    "imull %%ebx,%%eax;"
    "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    //$result=fix($result,2);
    return $result ;
}
float division( int $a, int $b ){
    int $result;
    float val=(float)$a/(float)$b;
    __asm__ __volatile__(
    "movl %1, %%eax;"
    "movl %2, %%ebx;"
    "cltd;"
    "idivl %%ebx;"
    "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    if ($result == val){
        return $result;
    }
    else{
        return val;
    }
}
float porcentaje(float a, float b, char op){
    float result = 0;
    if (op == '+') {
      result = (a/100)*b+a;
    }
    if (op == '-') {
      result = a-((a/100)*b);
    }
    return result;
}
float exponente(float a, float b){
    float result = a;
    for (int i = 0; i < b; i++) {
      result += result * a;
    }
    return result;
}
double test(double a){

    return 0.0;
}
float seno(float deg){
    float result;
    result = sin(deg*PI/180);
    return result;
}
float coseno(float deg){
    float result;
    result = cos(deg*PI/180);
    return result;
}
float tangente(float deg){
    float result;
    result = tan(deg*PI/180);
    return result;
}
float senoh(float deg){
    float result;
    //result = sinh(deg*PI/180);
    result = sinh(deg);
    return result;
}
float cosenoh(float deg){
    float result;
    result = cosh(deg);
    return result;
}
float tangenteh(float deg){
    float result;
    result = tanh(deg);
    return result;
}
float cosecante(float deg){
    float result;
    result = 1/sin(deg*PI/180);
    return result;
}
float secante(float deg){
    float result;
    result = 1/cos(deg*PI/180);
    return result;
}
float cotangente(float deg){
    float result;
    result = 1/tan(deg*PI/180);
    return result;
}

int main(int argc, char** argv) {
    int numero1, numero2;
    float fnumero1, fnumero2;
    float deg;
    double test, res;
    char x='z';
    do{
        printf( " Calculadora Cientifica\n\n" );
        printf( "\n\t\t Operaciones Aritmeticas" );
        printf( "\n\t a) Suma" );
        printf( "\n\t b) Resta" );
        printf( "\n\t c) Multiplicacion" );
        printf( "\n\t d) Division" );
        printf( "\n\t e) Porcentaje" );
        printf( "\n\t f) Operacion Exponencial" );

        printf( "\n\n\t\t Operaciones Matematicas" );
        printf( "\n\t g) Seno" );
        printf( "\n\t h) Coseno" );
        printf( "\n\t i) Tangente" );
        printf( "\n\t j) Seno hiperbolico" );
        printf( "\n\t k) Coseno hiperbolico" );
        printf( "\n\t l) Tangente hiperbolica" );
        printf( "\n\t m) Cosecante" );
        printf( "\n\t n) Secante" );
        printf( "\n\t o) Cotangente" );
        printf( "\n\t s) Salir" );

        printf( "\n\n\t\t Ingresa una opcion : " );
        cin>>x;
        switch (x){
            case 'a':
                printf( "\n\t\t Suma" );
                printf( "\n\n\t\t Ingresar el primer numero entero : " );
                scanf( "%d", &numero1 );
                printf( "\n\n\t\t Ingresar el segundo numero entero : " );
                scanf( "%d", &numero2 );
                printf( "\n\n" );
                printf( "\t\t La suma es = %d\n", suma(numero1,numero2) );
                printf( "\n\n" );
                break;
            case 'b':
                printf( "\n\t\t Resta" );
                printf( "\n\n\t\t Ingresar el primer numero entero : " );
                scanf( "%d", &numero1 );
                printf( "\n\n\t\t Ingresar el segundo numero entero : " );
                scanf( "%d", &numero2 );
                printf( "\n\n" );
                printf( "\t\t La resta es = %d\n", resta(numero1,numero2) );
                printf( "\n\n" );
                break;
            case 'c':
                printf( "\n\t\t Multiplicacion" );
                printf( "\n\n\t\t Ingresar el primer numero entero : " );
                scanf( "%d", &numero1 );
                printf( "\n\n\t\t Ingresar el segundo numero entero : " );
                scanf( "%d", &numero2 );
                printf( "\n\n" );
                printf( "\t\t La multiplicacion es = %d\n", multiplicacion(numero1,numero2) );
                printf( "\n\n" );
                break;
            case 'd':
                printf( "\n\t\t Division" );
                printf( "\n\n\t\t Ingresar el primer numero entero : " );
                scanf( "%d", &numero1 );
                printf( "\n\n\t\t Ingresar el segundo numero entero : " );
                scanf( "%d", &numero2 );
                printf( "\n\n" );
                printf( "\t\t La division es = %f\n", division(numero1,numero2) );
                printf( "\n\n" );
                break;
            case 'e':
                printf( "\n\t\t Seno" );
                printf( "\n\n\t\t Ingresa el angulo: " );
                scanf( "%f", &deg );
                printf( "\n\n" );
                printf( "\t\t El seno del angulo %f es = %f\n", deg,seno(deg) );
                printf( "\n\n" );
                break;
            case 'f':
                printf( "\n\t\t Coseno" );
                printf( "\n\n\t\t Ingresa el angulo: " );
                scanf( "%f", &deg );
                printf( "\n\n" );
                printf( "\t\t El coseno del angulo %f es = %f\n", deg,coseno(deg) );
                printf( "\n\n" );
                break;
            case 'g':
                printf( "\n\t\t Tangente" );
                printf( "\n\n\t\t Ingresa el angulo: " );
                scanf( "%f", &deg );
                printf( "\n\n" );
                printf( "\t\t La tangente del angulo %f es = %f\n", deg,tangente(deg) );
                printf( "\n\n" );
                break;
            case 'h':
                printf( "\n\t\t Seno hiperbolico" );
                printf( "\n\n\t\t Ingresa el angulo expresado en radianes: " );
                scanf( "%f", &deg );
                printf( "\n\n" );
                printf( "\t\t El seno hiperbolico del angulo %f es = %f\n", deg,senoh(deg) );
                printf( "\n\n" );
                break;
            case 'i':
                printf( "\n\t\t Coseno hiperbolico" );
                printf( "\n\n\t\t Ingresa el angulo expresado en radianes: " );
                scanf( "%f", &deg );
                printf( "\n\n" );
                printf( "\t\t El coseno hiperbolico del angulo %f es = %f\n", deg,cosenoh(deg) );
                printf( "\n\n" );
                break;
            case 'j':
                printf( "\n\t\t Tangente hiperbolica" );
                printf( "\n\n\t\t Ingresa el angulo expresado en radianes: " );
                scanf( "%f", &deg );
                printf( "\n\n" );
                printf( "\t\t La tangente hiperbolica del angulo %f es = %f\n", deg,tangenteh(deg) );
                printf( "\n\n" );
                break;
            case 'k':
                printf( "\n\t\t Cosecante" );
                printf( "\n\n\t\t Ingresa el angulo: " );
                scanf( "%f", &deg );
                printf( "\n\n" );
                printf( "\t\t La cosecate del angulo %f es = %f\n", deg,cosecante(deg) );
                printf( "\n\n" );
                break;
            case 'l':

                break;
            case 'm':

                break;
            case 't':
                printf( "\n\t\t Test" );
                printf( "\n\n\t\t Ingresa un meme: " );
                scanf( "%lf", &test );
                printf( "\n\n" );
                res = iround(test,10.2);
                printf( "\t\t Resultado %lf es = %lf\n", test,res );
                printf( "\n\n" );
                break;
            default:
                if ( x != 's' ){
                    cout<<"\nOpcion incorrecta"<<endl<<endl;
                }
                else{
                    cout<<"\nOpcion salir"<<endl<<endl;
                }
                break;
        }
    }
    while(x!='s');
    return 0;
}
