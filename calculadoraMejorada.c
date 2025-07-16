#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int resta(int a, int b){
return a-b;
}

int sumar(int a,int b)
{
    return a+b;
}
int multiplicar (int a, int b){
return a*b;

}
float dividir(float a, float b){

return a/b;
}
int potencia(int a, int b){
return pow(a,b);
}
int raiz(int a){
return sqrt(a);
}
int valABS(int a){
return abs(a);

}
int salir(int a);
int main(){
    int respuesta;
    int a, b;
    char respuestaop;

    printf("======CALCULADORA=======\n");
    printf("que operacion desea hacer\n");
    printf("1.suma\n2.resta\n3.dividir\n4.multiplicar\n5.potencia\n6.raiz\n7.valor absoluto\n8. salir\n");
    scanf("%d", &respuesta);
    printf("---------------------------\n");
    switch(respuesta){
        case 1:
        printf("ingrese el primer numero\n");
        scanf("%d", &a);
        printf("ingrese el segundo numero\n");
        scanf("%d", &b);
        printf("------------------\n");
        printf("resultado: %d\n", sumar(a,b));
        system("PAUSE");
        system("CLS");
        main();
        break;
        case 2:
        printf("ingrese el primer numero\n");
        scanf("%d", &a);
        printf("ingrese el otro\n");
        scanf("%d", &b);
        printf("------------------\n");
        printf("resultado: %d\n", resta(a,b));
        system("PAUSE");
        system("CLS");
        main();
        break;
        case 3:
        printf("ingrese el primer numero\n");
        scanf("%d", &a);
        printf("ingrese el otro\n");
        scanf("%d", &b);
        printf("------------------\n");
        printf("resultado: %2.f\n", dividir(a,b));
        system("PAUSE");
        system("CLS");
        main();
        break;
        case 4:
        printf("ingrese el primer numero\n");
        scanf("%d", &a);
        printf("ingrese el otro\n");
        scanf("%d", &b);
        printf("------------------\n");
        printf("resultado: %d\n", multiplicar(a,b));
        system("PAUSE");
        system("CLS");
        main();
        break;
        case 5:
        printf("ingrese el primer numero\n");
        scanf("%d", &a);
        printf("ingrese el otro\n");
        scanf("%d", &b);
        printf("------------------\n");
        printf("resultado: %d\n", potencia(a,b));
        system("PAUSE");
        system("CLS");
        main();
        break;
        case 6:
        printf("ingrese el primer numero\n");
        scanf("%d", &a);
        printf("------------------\n");
        printf("resultado: %d\n", raiz(a));
        system("PAUSE");
        system("CLS");
        main();
        break;
        case 7:
        printf("ingrese el primer numero\n");
        scanf("%d", &a);
        printf("------------------\n");
        printf("resultado: %d\n", valABS(a));
        system("PAUSE");
        system("CLS");
        main();
        break;
        case 8:
        printf("gracias por usarme\n");
        }
    return 0;
}

