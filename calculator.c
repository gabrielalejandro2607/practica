#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    float suma, resta, mult, div,  num1, num2;
    float resultado;
    char operacion[10];
    char respuesta[5];

    do{

    printf("QUE OPERACION DESEA HACER: \n");
    scanf("%s", operacion);
    if (strcmp(operacion, "suma")==0){
        printf("ingrese el numero que quiere sumar: ");
        scanf("%f", &num1);

        printf("ingrese el otro: ");
        scanf("%f", &num2);

        resultado=num1+num2;
        printf("el resultado es: %2.f\n", resultado);

    }

       if (strcmp(operacion, "multiplicacion")==0){
        printf("ingrese el numero que quiere multiplicar: ");
        scanf("%f", &num1);

        printf("ingrese el otro: ");
        scanf("%f", &num2);

        resultado=num1*num2;
        printf("el resultado es: %2.f\n", resultado);

    }

     if (strcmp(operacion, "division")==0){
        printf("ingrese el numero que quiere restar: ");
        scanf("%f", &num1);

        printf("ingrese el otro: ");
        scanf("%f", &num2);

        resultado=num1/num2;
        printf("el resultado es: %2.f\n", resultado);

    }

     if (strcmp(operacion, "resta")==0){
        printf("ingrese el numero que quiere restar: ");
        scanf("%f", &num1);

        printf("ingrese el otro: ");
        scanf("%f", &num2);

        resultado=num1-num2;
        printf("el resultado es: %2.f\n", resultado);

    }

    printf("desea hacer otra operacion?\n");
    scanf("%s", &respuesta);

    }while (strcmp(respuesta,"si")==0);


}
