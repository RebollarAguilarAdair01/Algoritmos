#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;                
    int right = heightSize - 1;   
    int max_area = 0;             

    while (left < right) {
        
        int min_height = height[left] < height[right] ? height[left] : height[right];
        
       
        int current_area = min_height * (right - left);
        
        
        if (current_area > max_area) {
            max_area = current_area;
        }
        
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main(int argc, char *argv[]) {
    int n;

    
    printf("Ingresa el tamano del arreglo: ");
    scanf("%i", &n);

  
    if (n < 2) {
        printf("El tamano del arreglo debe ser al menos 2.\n");
        return 1;
    }

    int height[n];

    
    printf("Ingresa los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %i: ", i + 1);
        scanf("%i", &height[i]);
    }

   
    int result = maxArea(height, n);
    printf("La maxima cantidad de agua que se puede contener es: %i\n", result);

    return 0;
}
