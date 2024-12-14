#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 100000
#define MIN 1
#define MAX 10000

void generarNumeros(int arr[]) {
    for (int i = 0; i < TAMANO; i++) {
        arr[i] = rand() % (MAX - MIN + 1) + MIN; 
    }
}

int main(int argc, char *argv[]) {
    int arr[TAMANO];
    int contador = 0;
    int sumatoria = 0;
    int k, promedio;

    srand(time(NULL));

    generarNumeros(arr);

    printf("Ingresa k: \n");
    scanf("%i", &k);
    printf("Ingresa promedio: \n");
    scanf("%i", &promedio);


    for (int i = 0; i < k; i++) {
        sumatoria += arr[i];
    }

    
    if (sumatoria >= k * promedio) {
        contador++;
    }

    
    for (int i = k; i < TAMANO; i++) {
        sumatoria += arr[i] - arr[i - k];
        if (sumatoria >= k * promedio) {
            contador++;
        }
    }

    printf("%i\n", contador );



    return 0;
}
