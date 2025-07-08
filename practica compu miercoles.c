#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[3][3];
    char etiqueta [20];
    int f, c;
    float sumatotal=0;
    int rest=0;
    float promelementos=0;
    float porce=0;

    for(f=0;f<3;f++){
        for(c=0;c<3;c++){
            printf("ingrese el valor %d de la fila y %d de la columna\n", f,c);
            scanf("%d", &matriz[f][c]);
        }
    }
    system("CLS");
    printf("la matriz es\n");
    printf("-----------------\n");
    for(f=0;f<3;f++){
       for(c=0;c<3;c++){
    printf("%d |\t", matriz[f][c]);
       }
       printf("\n");
    }
    for (f=0;f<3;f++){
        for(c=0; c<3;c++){
            sumatotal+=matriz[f][c];
            rest-=matriz[f][c];

        }
    }
    printf("la diagonal principal es: ");
    for(f=0; f<3;f++){
        for(c=0;c<3;c++){
            if(f==c){
                printf("%d", matriz[f][c]);
            }
        }
    }
    printf("\nla diagonal secundaria es: ");
    for(f=0;f<3;f++){
        for(c=0;c<3;c++){
            if((f+c)==(3-1)){
                printf("%d", matriz[f][c]);
            }
        }
    }
    porce=(sumatotal/900)*100;
    promelementos=sumatotal/9;
    printf("\nla suma total es de:  %2.f\n", sumatotal);
    printf("la resta acumulada es de:  %d\n", rest);
    printf("el promedio de todos los elementos es de:  %2.f\n", promelementos);
    printf("el porcentaje total de la matriz seria:  %2.f\n", porce);

    printf("el valor de la matriz es: ");

    if(sumatotal>70){
        printf("alto\n");
    }else if(sumatotal>40&&sumatotal<=69){
    printf("medio\n");
    } else {
    printf("bajo");
    }
return 0;
}
