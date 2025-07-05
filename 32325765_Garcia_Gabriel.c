#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GREEN  "\033[0;32m"
#define RESET  "\033[0m"
#define RED "\033[0;31m"

    int main()
{
    char titulo[50][50];
    char autor[50][50];
    char genero[50][50];
    float ganancia[500];
    char codigo[10][11];
    //use IA para ayudarme con esto pq al ingresar el codigo en la consola me mostraba lo que no era o de por si no me mostraba nada.
    int cantdispo[50];
    float precio[50];
    int cantlibros;
    int i, j;
    char codbuscado[11];
    int encontrado=0;

    printf("INGRESE LA CANTIDAD DE LIBROS QUE QUIERE BUSCAR\n");
    scanf("%d", &cantlibros);

    for(i=0; i<cantlibros;i++){
        printf("INGRESE EL LIBRO NUMERO %d:  ",i+1);
        scanf(" %[^\n]s", &titulo[i]);

        printf("CUAL ES SU AUTOR:  ");
        scanf(" %[^\n]s", &autor[i]);

        printf("DE QUE GENERO ES EL LIBRO:  ");
        scanf(" %[^\n]s", &genero[i]);

        printf("INGRESE EL CODIGO DEL LIBRO:  ");
        scanf("%10s", codigo[i]);

        printf("INGRESE EL STOCK DE ESTE LIBRO:  ");
        scanf("%d", &cantdispo[i]);

        printf("INGRESE SU PRECIO:  ");
        scanf("%f", &precio[i]);

        ganancia[i]=cantdispo[i]*precio[i];


    }

     system("CLS");
        printf("\n%-20s %-15s %-15s %-12s %10s %10s %10s\n","TITULO", "AUTOR", "GENERO", "CODIGO", "CANT", "PRECIO", "GANANCIA");

        for(i=0;i<cantlibros;i++){
        printf("%-20s %-15s %-15s %-12s %10d %10.2f ", titulo[i], autor[i], genero[i], codigo[i], cantdispo[i], precio[i], ganancia[i]);

        if(ganancia[i]>=0){
            printf(GREEN);
        }
        if(ganancia[i]<0){
            printf(RED);
        }
        printf("%10.2f", ganancia[i]);

        if(ganancia[i]>=0){
            printf(RESET);
        }
        if(ganancia[i]<=0){
            printf(RESET);
        }
        printf("\n");
        }


            printf("INGRESE EL CODIGO DEL LIBRO QUE DESEA BUSCAR:  ");
            scanf("%s", codbuscado);

           for(i=0;i<cantlibros;i++){

            if (strcmp(codigo[i], codbuscado) == 0) {

                printf("LIBRO ENCONTRADO\n");
                printf("TITULO: %s | AUTOR: %s | PRECIO: %f | CODIGO: %10s\n", titulo[i], autor[i], precio[i], codigo[i]);
                encontrado=1;
                break;
          }  }
            if (!encontrado) {

            printf("EL LIBRO NO SE ENCONTRO O NO ESTA DISPONIBLE");
            }

}
