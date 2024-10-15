#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef struct {
    int x;
    int y;
} Punto;


float distancia(Punto p1, Punto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}


int comparar_x(const void *a, const void *b) {
    return ((Punto *)a)->x - ((Punto *)b)->x;
}


int comparar_y(const void *a, const void *b) {
    return ((Punto *)a)->y - ((Punto *)b)->y;
}


float encontrar_mas_cercanas(Punto puntos[], int n, Punto *p1, Punto *p2) {
    if (n <= 3) {
        float min_distancia = distancia(puntos[0], puntos[1]);
        *p1 = puntos[0];
        *p2 = puntos[1];
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                float d = distancia(puntos[i], puntos[j]);
                if (d < min_distancia) {
                    min_distancia = d;
                    *p1 = puntos[i];
                    *p2 = puntos[j];
                }
            }
        }
        return min_distancia;
    }

  
    int medio = n / 2;
    Punto puntos_izquierda[medio];
    Punto puntos_derecha[n - medio];

    for (int i = 0; i < medio; i++) {
        puntos_izquierda[i] = puntos[i];
    }
    for (int i = medio; i < n; i++) {
        puntos_derecha[i - medio] = puntos[i];
    }

    
    Punto p1_izq, p2_izq, p1_der, p2_der;
    float d_izq = encontrar_mas_cercanas(puntos_izquierda, medio, &p1_izq, &p2_izq);
    float d_der = encontrar_mas_cercanas(puntos_derecha, n - medio, &p1_der, &p2_der);

    
    float min_distancia = d_izq < d_der ? d_izq : d_der;
    *p1 = d_izq < d_der ? p1_izq : p1_der;
    *p2 = d_izq < d_der ? p2_izq : p2_der;

   
    Punto puntos_cerca_division[n];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (abs(puntos[i].x - puntos[medio].x) < min_distancia) {
            puntos_cerca_division[k++] = puntos[i];
        }
    }

   
    qsort(puntos_cerca_division, k, sizeof(Punto), comparar_y);

    
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k && (puntos_cerca_division[j].y - puntos_cerca_division[i].y) < min_distancia; j++) {
            float d = distancia(puntos_cerca_division[i], puntos_cerca_division[j]);
            if (d < min_distancia) {
                min_distancia = d;
                *p1 = puntos_cerca_division[i];
                *p2 = puntos_cerca_division[j];
            }
        }
    }

    return min_distancia;
}


void generarCoordenada(int *coord) {
    *coord = rand() % 21 - 10;
}


void llenarArr(int n) {
    Punto puntos[n];

    for (int i = 0; i < n; i++) {
        generarCoordenada(&puntos[i].x);
        generarCoordenada(&puntos[i].y);
    }

    printf("Generando %i puntos...\n", n);
    for (int i = 0; i < n; i++) {
        printf("Punto %i: (%i, %i)\n", i + 1, puntos[i].x, puntos[i].y);
    }

 
    qsort(puntos, n, sizeof(Punto), comparar_x);

    
    Punto p1, p2;
    float min_distancia = encontrar_mas_cercanas(puntos, n, &p1, &p2);

    printf("Las coordenadas mas cercanas son: (%i, %i) y (%i, %i)\n", p1.x, p1.y, p2.x, p2.y);
    printf("La distancia entre ellas es: %.2f\n", min_distancia);
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
