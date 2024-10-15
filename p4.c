#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float distancia(int x1, int x2, int y1, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void medirD(int *x, int *y, int tamano) {
    if (tamano < 2) {
        printf("Se necesitan al menos dos puntos.\n");
        return;
    }

    float min_distancia = distancia(x[0], x[1], y[0], y[1]);
    int p1 = 0, p2 = 1; 

    for (int i = 0; i < tamano - 1; i++) {
        for (int j = i + 1; j < tamano; j++) {
            float dis = distancia(x[i], x[j], y[i], y[j]);
            if (dis < min_distancia) {
                min_distancia = dis;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("Las coordenadas mas cercanas son: (%i, %i) y (%i, %i)\n", 
           x[p1], y[p1], x[p2], y[p2]);
    printf("La distancia entre ellas es: %.2f\n", min_distancia);
}

void generarCoordenada(int *coord) {
    *coord = rand() % 21 - 10; 
}

void llenarArr(int n) {
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        generarCoordenada(&x[i]);
        generarCoordenada(&y[i]);
    }

    printf("Generando %i puntos...\n", n);
    for (int i = 0; i < n; i++) {
        printf("Punto %i: (%i, %i)\n", i + 1, x[i], y[i]);
    }

    medirD(x, y, n);
}

void mostrarMenu() {
    printf("*******Menu*******\n");
    printf("1.- n = 10\n");
    printf("2.- n = 100\n");
    printf("3.- n = 1000\n");
    printf("4.- n = 10000\n");
    printf("5.- n = 100000\n");
    printf("6.- Salir\n");
}

void solicitarOpciones() {
    int opcion;
    do {
        mostrarMenu();
        printf("Elija una opcion: \n");
        scanf("%i", &opcion);

        switch(opcion) {
            case 1: 
                llenarArr(10);
                break;
            case 2: 
                llenarArr(100);
                break;
            case 3: 
                llenarArr(1000);
                break;
            case 4: 
                llenarArr(10000);
                break;
            case 5: 
                llenarArr(100000);
                break;
            case 6: 
                printf("Finalizando programa.\n");
                break;
            default: 
                printf("Opcion no valida, intente de nuevo.\n");
        }

    } while(opcion != 6);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    solicitarOpciones();
    return 0;
}
