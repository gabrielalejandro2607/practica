#include <stdio.h>
#include <stdbool.h>

// Practica bool
bool esPrimo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int numero;

    printf("====================================\n");
    printf("|   Verificador de numero primo    |\n");
    printf("====================================\n");
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    if (esPrimo(numero)) {
        printf("El numero %d es primo.\n", numero);
    } else {
        printf("El numero %d NO es primo.\n", numero);
    }

    return 0;
}

