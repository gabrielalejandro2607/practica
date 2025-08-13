#include <stdio.h>
#include <windows.h>
#include "poker.h"
#include <time.h> 
#include <string.h>

#define ACTIVO 1
#define INACTIVO 0
#define MAX_CARTAS 10
#define RESET "\x1b[0m"

//struct cartas
typedef struct{
    int valor;
    int paloIndex;
}carta;
//juegador
typedef struct {
    int puntuacion;
    char nombre[20];
    carta cartas[MAX_CARTAS];
    int cantCartas;
    int estado;
    int puntajeFinal;
    int cartaEspecialMay;
} jugador;

int cantjugadores;
//funcion para guardar archivo-txt
void GuardarPuntaje(jugador jugadores[], int cantjugadores) {
    FILE *archivo = fopen("datos/puntaje.txt", "a");
    if (archivo == NULL) {
        perror("Error al abrir archivo");
        return;
    }

    // encabezado para el orden
    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    if (tam == 0) {
        fprintf(archivo, "Nombre     | Puntaje\n");
        fprintf(archivo, "---------------------\n");
    }

    // Escribir cada jugador ordenado
    for (int i = 0; i < cantjugadores; i++) {
        fprintf(archivo, "%-10s | %6d\n", jugadores[i].nombre, jugadores[i].puntajeFinal);
    }

    fclose(archivo);
    printf(" El puntaje se guardó correctamente \n");
}

int menuInicial() {
    int eleccion;
    printf(CYAN"|====================================|\n");
    printf(CYAN"|BIENVENIDO A JACKONE (BALATRO 2.0)|\n");
    printf("|====================================|\n");
    printf("QUE QUIERES HACER?\n");
    printf("----------------------\n");
    printf("1.JUGAR\n-----\n2.ACERCA DE JACKSTONE\n-----\n3.SALIR\n-----\n");
    scanf("%d", &eleccion);
    printf(RESET"\n");
    switch (eleccion)
    {
    case 1:
    do {
        system("CLS");
        printf("Ingrese cuántos jugadores van a jugar (3-4):\n");
        scanf("%d", &cantjugadores);


        if (cantjugadores < 3 || cantjugadores > 4) {
            printf("Número inválido, tiene que ser un número permitido.\n");
        }
    } while (cantjugadores < 3 || cantjugadores > 4);
    break;
    case 2:
    system("CLS");
        printf("Jackstone es un juego de cartas el cual esta enfocado en la diversion\n");
        printf("y fue creado para la diversion de las personas que quieran jugar algo interesante sin la necesidad de internet\n");
        system("PAUSE");
        system ("CLS");
        return menuInicial();
    break;
    case 3: 
    system("CLS");
    printf("Gracias por elegirnos\n");
    printf("Pronto con mas juegos\n");
    exit(0);
    break;
    default:
        printf("vuelve a intentarlo porfavor\n");
        system("PAUSE");
        system("CLS");
        return menuInicial();
        break;

}

    return cantjugadores;
}
int valorEspecial( char letra){
    switch (letra)
    {
    case 11:
        return 1;
        break;
    case 12:
        return 2;
        break;
    case 13:
    return 3;
    break;
    default:
    return 0;
        break;
    }
}

void datosJugadores(jugador jugadores[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        system("CLS");
        printf("Hola jugador %d, por favor dime tu nombre:\n", i + 1);
        scanf(" %[^\n]", jugadores[i].nombre);
        system("CLS");
        
    }
}

int cartaEspecial(int carta) {
    return (carta == 11 || carta == 12 || carta == 13);
}

void cambCartas(int valor, char* salida) {
    switch (valor) {
        case 1: strcpy(salida, "A"); break;
        case 11: strcpy(salida, "J"); break;
        case 12: strcpy(salida, "Q"); break;
        case 13: strcpy(salida, "K"); break;
        default: sprintf(salida, "%d", valor); break;
    }
}

void repartirCartas(jugador jugadores[], int cantjugadores) {
    const char* palos[] = { "♠", "♣", "♥", "♦" };
    const char* colores[] = { BLUE, BLUE, RED, RED };

    for (int i = 0; i < cantjugadores; i++) {
        printf("Jugador %d recibe:\n", i + 1);

        for (int j = 0; j < 2; j++) {
            int valor = rand() % 13 + 1;
            int paloIndex = rand() % 4;

            char nombre[4];
            cambCartas(valor, nombre);

            const char* palo = palos[paloIndex];
            const char* color = colores[paloIndex];

            printCard(palo, nombre, color);
            printf(RESET "\n");
            

            if (jugadores[i].cantCartas < MAX_CARTAS) {
                jugadores[i].cartas[jugadores[i].cantCartas].valor = valor;
                jugadores[i].cartas[jugadores[i].cantCartas].paloIndex = paloIndex;
                jugadores[i].cantCartas++;
            } else {
                printf("El jugador ya tiene muchas cartas.\n");
            }
            
        }
            system("PAUSE");
            system("CLS");
    }
}

void darCartas(jugador *j, int cantidad) {
    const char* palos[] = { "♠", "♣", "♥", "♦" };
    const char* colores[] = { BLUE, BLUE, RED, RED };

    for (int i = 0; i < cantidad; i++) {
        if (j->cantCartas >= MAX_CARTAS) {
            printf("Ya tienes muchas cartas, no puedes agarrar más.\n");
            break;
        }

        int valor = rand() % 13 + 1;
        int paloIndex = rand() % 4;

        char nombre[4];
        cambCartas(valor, nombre);
        const char* palo = palos[paloIndex];
        const char* color = colores[paloIndex];

        printf("\nHas robado esta carta:\n");
        printCard(palo, nombre, color);
        printf(RESET"\n");
        system("PAUSE");
        system("CLS");

        j->cartas[j->cantCartas].valor = valor;
        j->cartas[j->cantCartas].paloIndex= paloIndex;
        j->cantCartas++;
    }
}
int calcularPuntaje(jugador *j) {
    int puntaje = 0;
    for (int i = 0; i < j->cantCartas; i++) {
        int valor = j->cartas[i].valor;
        if (valor == 1) {
            puntaje += 1;
        } else if (valor >= 2 && valor <= 10) {
            puntaje += valor;
        }
    }
    return puntaje;
}

int siguienteJugadorActivo(jugador jugadores[], int actual, int direccion, int cantjugadores) {
    int siguiente = actual;
    int intentos = 0;
    do {
        siguiente = (siguiente + direccion + cantjugadores) % cantjugadores;
        intentos++;
        if (intentos > cantjugadores) return -1;
    } while (jugadores[siguiente].estado != ACTIVO);
    return siguiente;
}

void EfectoCartas(int carta, jugador jugadores[], int turnos, int *cambDireccion, int *salto, int *saltojugador, int cantjugadores) {
    int victima;

    switch (carta) {
        case 13: { //carta K
            int siguiente = (turnos + *cambDireccion + cantjugadores) % cantjugadores;
            printf("Ha salido la carta K, %s pierde un turno.\n", jugadores[siguiente].nombre);
            *salto = 1;
            *saltojugador = siguiente;
            break;
        }
        case 12: //carta Q
            printf("Ha salido la carta Q, ahora se cambia el sentido de la partida.\n");
            *cambDireccion *= -1;
            break;
        case 11: { // carta j
            victima = siguienteJugadorActivo(jugadores, turnos,*cambDireccion, cantjugadores);
            if(victima!=-1){
            int nuevoPuntaje = calcularPuntaje(&jugadores[victima]);
            jugadores[victima].puntuacion = nuevoPuntaje;

            if (nuevoPuntaje > 21) {
                printf("%s se ha pasado con %d puntos tras recibir el castigo. Queda fuera de la partida.\n", jugadores[victima].nombre, nuevoPuntaje);
                jugadores[victima].estado = INACTIVO;
            }
            if (jugadores[victima].cantCartas >= MAX_CARTAS){
                printf("has llegado al limite de cartas permitido\n");
            }else{
                int castigo;
                if (jugadores[victima].cantCartas % 2 == 0){
                    castigo=2;
                }else{
                    castigo=4;
                }
                darCartas(&jugadores[victima], castigo);
            }
        }else {
            printf("no hay jugadores disponibles para recibir el castigo\n");
        }
          
            break;
        }
    }
}

void Jugarturno(jugador jugadores[]) {
    int cambDireccion = 1;
    int saltojugador = -1;
    int salto = 0;
    int turnoActual = 0;

    while (1) {
        if (jugadores[turnoActual].estado != ACTIVO) {
            turnoActual = siguienteJugadorActivo(jugadores, turnoActual, cambDireccion, cantjugadores);
            if (turnoActual == -1) {
                printf("Todos los jugadores están inactivos. Fin de la partida.\n");

                int mejorpuntaje = 0;
                for(int i =0; i<cantjugadores; i++){
                    if(jugadores[i].puntuacion<=21 && jugadores[i].puntuacion>mejorpuntaje){
                        mejorpuntaje=jugadores[i].puntuacion;
                    }
                }
                if (mejorpuntaje == 0){
                    printf("ningun jugador logro un puntaje valido\n");
                }else{
                    int empatados[cantjugadores];
                    int cantempatados = 0;
                    for(int j=0; j<cantjugadores; j++){
                        if(jugadores[j].puntuacion == mejorpuntaje){
                            empatados[cantempatados++]=j;
                        }
                    }
                    if(cantempatados==1){
                        int ganador = empatados[0];
                        printf("%s ha ganado con un puntaje de %d\n", jugadores[ganador].nombre, mejorpuntaje);
                    }else{
                        //por desempate
                        int ganadorDesempate = -1;
                        int cartaMax = 0;
                        printf("hay empate, se definira por la carta especial mas grande\n");
                        for(int i=0; i<cantjugadores;i++){
                            int idx =empatados[i];
                            char nombre[4];
                            cambCartas(jugadores[idx].cartaEspecialMay, nombre);
                            printf("%s (carta especial mas grande: %s)\n",jugadores[idx].nombre, nombre);

                            if(jugadores[idx].cartaEspecialMay > cartaMax){
                                cartaMax = jugadores[idx].cartaEspecialMay;
                                ganadorDesempate = idx;
                            }
                        }
                        if (ganadorDesempate != 1){
                            char nombreGandor [4];
                            cambCartas(cartaMax, nombreGandor);
                            printf("%s ha ganado por desempate con la carta especial: %s\n", jugadores[ganadorDesempate].nombre, nombreGandor);
                        }else{
                            printf("no hubo ganadro por carta especial\n");
                        }
                    }
                }
                break;
            }
            continue;
        }

        printf("\nTurno de %s\n", jugadores[turnoActual].nombre);

        if (turnoActual == saltojugador) {
            printf("%s fue salteado.\n", jugadores[turnoActual].nombre);
            saltojugador = -1;
            salto=0;
            turnoActual = siguienteJugadorActivo(jugadores, turnoActual, cambDireccion, cantjugadores);
            continue;
        }

        int turnoFinalizado = 0;
        while (!turnoFinalizado) {
            printf("Cartas actuales:\n");
            for (int k = 0; k < jugadores[turnoActual].cantCartas; k++) {
                int valor = jugadores[turnoActual].cartas[k].valor;
                int paloIndex= jugadores[turnoActual].cartas[k].paloIndex;
                if (valor == 0) continue;
                char nombre[4];
                cambCartas(valor, nombre);
                const char* palos[] = { "♠", "♣", "♥", "♦" };
                const char* colores[] = { BLUE, BLUE, RED, RED };
                printCard(palos[paloIndex], nombre, colores[paloIndex]);
                printf(RESET "\n");
            }

            int puntos = calcularPuntaje(&jugadores[turnoActual]);
            jugadores[turnoActual].puntuacion = puntos;

            if (puntos == 21) {
                
                printf("¡Felicidades %s, has ganado!\n", jugadores[turnoActual].nombre);
                jugadores[turnoActual].estado = INACTIVO;
                turnoFinalizado = 1;
                system("PAUSE");
                system("CLS");
                break;
            } else if (puntos > 21) {
                printf("%s se ha pasado de los puntos permitidos.\n", jugadores[turnoActual].nombre);
                system("PAUSE");
                system("CLS");
                jugadores[turnoActual].estado = INACTIVO;
                turnoFinalizado = 1;
                break;
            }

            printf("\n¿Qué deseas hacer?\n 1. Hit (jugar carta especial)\n 2. Draw (tomar carta)\n 3. Stand (quedarse)\n> ");
            int accion;
            scanf("%d", &accion);

            switch (accion) {
                case 1: {
                    int especiales[10], countEspeciales = 0;
                    for (int x = 0; x < jugadores[turnoActual].cantCartas; x++) {
                        if (cartaEspecial(jugadores[turnoActual].cartas[x].valor)) {
                            especiales[countEspeciales++] = x;
                        }
                    }

                    if (countEspeciales > 0) {
                        printf("Tienes estas cartas especiales:\n");
                        for (int e = 0; e < countEspeciales; e++) {
                            int idx = especiales[e];
                            printf("  [%d] Carta: %d\n", e + 1, jugadores[turnoActual].cartas[idx].valor);
                        }

                        printf("¿Cuál quieres jugar? Ingresa el número correspondiente:\n> ");
                        int eleccion;
                        scanf("%d", &eleccion);
                        
                        if (eleccion >= 1 && eleccion <= countEspeciales) {
                            int idx = especiales[eleccion - 1];
                            int cartaElegida = jugadores[turnoActual].cartas[idx].valor;
                            EfectoCartas(cartaElegida, jugadores, turnoActual, &cambDireccion, &salto, &saltojugador, cantjugadores);
                            if(valorEspecial(cartaElegida)>valorEspecial(jugadores[turnoActual].cartaEspecialMay)){
                                jugadores[turnoActual].cartaEspecialMay = cartaElegida;
                                printf("%s ha usado su carta especial con mas poder\n", jugadores[turnoActual].nombre);
                            }
                            for (int m = idx; m < jugadores[turnoActual].cantCartas - 1; m++) {
                                jugadores[turnoActual].cartas[m] = jugadores[turnoActual].cartas[m + 1];
                            }
                            jugadores[turnoActual].cantCartas--;
                            turnoFinalizado = 1;
                        } else {
                            printf("Elección inválida, no se juega carta especial.\n");
                        }
                    } else {
                        printf("No tenías carta especial, debes tomar una carta.\n");
                        darCartas(&jugadores[turnoActual], 1);
                    }
                    break;
                }

                case 2: 
                    printf("Decidiste tomar una carta.\n");
                    darCartas(&jugadores[turnoActual], 1);
                        printf(RESET"\n");
                    break;
        
                case 3:
                    printf("%s ha decidido quedarse con sus cartas.\n", jugadores[turnoActual].nombre);
                    jugadores[turnoActual].estado = INACTIVO;
                    turnoFinalizado = 1;
                    break;

                default:
                    printf("Acción inválida.\n");
                    break;
            }

            if (jugadores[turnoActual].puntuacion >= 21) {
                turnoFinalizado = 1;
            }
        }

         if (salto == 1){
            int saltado = (turnoActual+cambDireccion+cantjugadores)%cantjugadores;
            saltojugador=saltado;
        } 

        turnoActual=siguienteJugadorActivo(jugadores, turnoActual, cambDireccion, cantjugadores);
        if (turnoActual==-1)
        {
            printf("todos los jugadores estan inactivos, fin de partida\n");
            break;
        }
    }
}

void calcularPuntajesFinales(jugador jugadores[], int cantjugadores) {
    int totalGanadores = 0;
    for (int i = 0; i < cantjugadores; i++) {
        if (jugadores[i].puntuacion == 21) {
            totalGanadores++;
        }
    }

    for (int j = 0; j < cantjugadores; j++) {
        if (jugadores[j].puntuacion > 21) {
            jugadores[j].puntajeFinal = jugadores[j].puntuacion;
        } else if (jugadores[j].puntuacion == 21) {
            jugadores[j].puntajeFinal = 100 / (totalGanadores > 0 ? totalGanadores : 1);
        } else {
            jugadores[j].puntajeFinal = jugadores[j].puntuacion;
        }
    }
}

void mostrarPuntajeFinal(jugador jugadores[], int cantjugadores) {
    system("CLS");
    printf(CYAN"\nRESULTADOS FINALES:\n");
    for (int i = 0; i < cantjugadores; i++) {
        printf("Nombre: %s | Puntos: %d | Puntaje Final: %d\n",
               jugadores[i].nombre,
               jugadores[i].puntuacion,
               jugadores[i].puntajeFinal);
    }
    printf(RESET"\n");
}
void anunciarGanadorFinal(jugador jugadores[], int cantjugadores) {
    int mejorPuntaje = 0;
    int ganador = -1;
    int empatados[cantjugadores];
    int cantEmpatados = 0;

    for (int i = 0; i < cantjugadores; i++) {
        if (jugadores[i].puntuacion <= 21 && jugadores[i].puntuacion > mejorPuntaje) {
            mejorPuntaje = jugadores[i].puntuacion;
        }
    }

    for (int i = 0; i < cantjugadores; i++) {
        if (jugadores[i].puntuacion == mejorPuntaje) {
            empatados[cantEmpatados++] = i;
        }
    }

    if (mejorPuntaje == 0) {
        printf("Ningún jugador logró un puntaje válido.\n");
    } else if (cantEmpatados == 1) {
        ganador = empatados[0];
        printf(" %s ha ganado con un puntaje de %d\n", jugadores[ganador].nombre, mejorPuntaje);
    } else {
        printf(" Hay empate entre los siguientes jugadores con %d puntos:\n", mejorPuntaje);
        for (int i = 0; i < cantEmpatados; i++) {
            int idx = empatados[i];
            char nombreCarta[4];
            if(jugadores[idx].cartaEspecialMay!=-1){
            cambCartas(jugadores[idx].cartaEspecialMay, nombreCarta);
            printf("  - %s (Carta especial más alta: %s)\n", jugadores[idx].nombre, nombreCarta);
            }else{
                printf("%s no uso carta especial\n", jugadores[idx].nombre);
            }
        }

        // Desempate por carta especial
        int cartaMax = 0;
        int ganadorDesempate = -1;
        for (int i = 0; i < cantEmpatados; i++) {
            int idx = empatados[i];
            if (jugadores[idx].cartaEspecialMay > cartaMax) {
                cartaMax = jugadores[idx].cartaEspecialMay;
                ganadorDesempate = idx;
            }
        }

        if (ganadorDesempate != -1) {
            char nombreGanador[4];
            cambCartas(cartaMax, nombreGanador);
            printf("\n %s ha ganado por desempate con la carta especial '%s'\n", jugadores[ganadorDesempate].nombre, nombreGanador);
        }
    }
}

int main() {
    system("CLS");
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    jugador jugadores[4];
    char seguir;

    cantjugadores = menuInicial();
    datosJugadores(jugadores, cantjugadores);

    do {
        for (int i = 0; i < cantjugadores; i++) {
            jugadores[i].cantCartas = 0;
            jugadores[i].puntuacion = 0;
            jugadores[i].puntajeFinal = 0;
            jugadores[i].estado = ACTIVO;
            for (int k = 0; k < MAX_CARTAS; k++) {
                jugadores[i].cartas[k].valor = 0;
                jugadores[i].cartas[k].paloIndex = 0;
            }
        }

        repartirCartas(jugadores, cantjugadores);
        Jugarturno(jugadores);
        calcularPuntajesFinales(jugadores, cantjugadores);
        mostrarPuntajeFinal(jugadores, cantjugadores);
        anunciarGanadorFinal(jugadores, cantjugadores);
        GuardarPuntaje(jugadores, cantjugadores);

        printf("\n¿Deseas jugar otra partida? (s/n):\n");
        scanf(" %c", &seguir);
    } while (seguir == 's' || seguir == 'S');
}