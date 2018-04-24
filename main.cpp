#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;
#define PI 3.14159265359
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
double test(double a){
    __asm {
      fld qword ptr [a]
      fsin
      "movl %%eax, %0;" : "=g" ( $result ) : "g" ( $a )
    }
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

int main(int argc, char** argv) {
    int numero1, numero2;
    float fnumero1, fnumero2;
    float deg;
    char x='v';
    do{
        printf( " Calculadora Cientifica\n\n" );
        printf( "\n\t\t Operaciones Aritmeticas" );
        printf( "\n\t a) Suma" );
        printf( "\n\t b) Resta" );
        printf( "\n\t c) Multiplicacion" );
        printf( "\n\t d) Division" );

        printf( "\n\n\t\t Operaciones Matematicas" );
        printf( "\n\t e) Seno" );
        printf( "\n\t f) Coseno" );
        printf( "\n\t g) Tangente" );
        printf( "\n\t h) Seno hiperbolico" );
        printf( "\n\t i) Coseno hiperbolico" );
        printf( "\n\t j) Tangente hiperbolica" );
        printf( "\n\t k) Cosecante" );
        printf( "\n\t s) Salir" );

        /*
        printf( "\n\n\t\t Ingresar el primer numero entero : " );
        scanf( "%d", &numero1 );
        printf( "\n\n\t\t Ingresar el segundo numero entero : " );
        scanf( "%d", &numero2 );
        printf( "\n\n" );
        printf( "\t\t El area es = %d\n", AreaT(numero1,numero2) );
        printf( "\n\n" );
        printf( "\n\n\t\t Presiona v para volver a calcular o s para salir: " );
         */
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
                printf( "\t\t La cosecnate del angulo %f es = %f\n", deg,cosecante(deg) );
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
