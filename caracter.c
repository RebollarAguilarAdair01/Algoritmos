#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num, i, k;
    
    
    printf("Cuantos elementos deseas agregar? \n");
    scanf("%i", &num);
    getchar(); 

    
    char cadena[num + 1]; 
    printf("Ingresa la cadena de caracteres:\n");
    fgets(cadena, num + 1, stdin);

    
    printf("Cadena comprimida: ");

    for (i = 0; i < num; i++) {
        k = 1; 

        while (i + 1 < num && cadena[i] == cadena[i + 1]) {
            k++;
            i++;
        }

        
        printf("%i%c", k, cadena[i]);
    }
    
    printf("\n");
    return 0;
}