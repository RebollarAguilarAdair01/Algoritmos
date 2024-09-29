#include <stdio.h>
#include<time.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n; 
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); 
    }
}

int main(int argc, char *argv[]) {
    int n;
    clock_t comienzo;

    comienzo = clock();

    
    printf("Ingresa un numero entero para calcular el Fibonacci: ");
    scanf("%i", &n);

    
    printf("El termino %i de la serie de Fibonacci es: %i\n", n, fibonacci(n));
    printf("\nNumero de segundos transcurridos desde el comienzo del programa: %f s\n", (clock()-comienzo)/(double)CLOCKS_PER_SEC );

    return 0;
}