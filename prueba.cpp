#include <stdio.h>

int main() {
    int MAX_JUGADORES = 30;
    int MAX_JUEGOS = 7;

    int jugadores[MAX_JUGADORES][MAX_JUEGOS];
    float premios[MAX_JUEGOS];

    // Entrada de datos y cálculo del promedio de calificaciones
    for (int i = 0; i < MAX_JUGADORES; i++) {
        int n_jugador, n_juego, calificacion;

        printf("Ingrese el número de jugador (1-30) (0 para terminar): ");
        scanf("%d", &n_jugador);

        if (n_jugador == 0) {
            break;
        }

        printf("Ingrese el número de juego (1-7): ");
        scanf("%d", &n_juego);

        printf("Ingrese la calificación obtenida (1-10): ");
        scanf("%d", &calificacion);

        jugadores[n_jugador - 1][n_juego - 1] = calificacion;
    }

    // Puntaje final obtenido por cada jugador en cada juego que fue calificado
    for (int i = 0; i < MAX_JUGADORES; i++) {
        for (int j = 0; j < MAX_JUEGOS; j++) {
            if (jugadores[i][j] > 0) {
                printf("El jugador %d obtuvo %d puntos en el juego %d\n", i + 1, jugadores[i][j], j + 1);
            }
        }
    }

    // Porcentaje de jugadores que no fueron calificados en ningún juego
    int jugadores_calificados = 0;
    for (int i = 0; i < MAX_JUGADORES; i++) {
        int calificados = 0;
        for (int j = 0; j < MAX_JUEGOS; j++) {
            if (jugadores[i][j] > 0) {
                calificados = 1;
                break;
            }
        }
        if (calificados) {
            jugadores_calificados++;
        }
    }

    float porcentaje_no_calificados = (1 - (float)jugadores_calificados / MAX_JUGADORES) * 100;
    printf("El porcentaje de jugadores no calificados es %.2f%%\n", porcentaje_no_calificados);

    // Monto que cobrará cada jugador por los juegos en los que fue calificado
    printf("Montos a cobrar por los juegos en los que fue calificado:\n");
    for (int i = 0; i < MAX_JUGADORES; i++) {
        int monto_total = 0;
        for (int j = 0; j < MAX_JUEGOS; j++) {
            if (jugadores[i][j] > 8) {
                monto_total += premios[j];
            }
        }
        printf("El jugador %d cobrará $%d\n", i + 1, monto_total);
    }

    return 0;
} 

