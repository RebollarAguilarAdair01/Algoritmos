#include <stdio.h>

#define N 3  

void combinacion(int arr1[], int arr2[], int arr3[], int result[], int n) {
    int i = 0, j = 0, k = 0, l = 0;
   
    while (i < n && j < n) {
        if (arr1[i] < arr2[j]) {
            result[l++] = arr1[i++];
        } else {
            result[l++] = arr2[j++];
        }
    }
    
    while (i < n) {
        result[l++] = arr1[i++];
    }
        
    while (j < n) {
        result[l++] = arr2[j++];
    }
   
    int tempResult[l];
    for (int m = 0; m < l; m++) {
        tempResult[m] = result[m];
    }
    
    i = 0;  
    j = 0;  
    l = 0;  
    
    while (i < 2 * n && j < n) {
        if (tempResult[i] < arr3[j]) {
            result[l++] = tempResult[i++];
        } else {
            result[l++] = arr3[j++];
        }
    }
      
    while (i < 2 * n) {
        result[l++] = tempResult[i++];
    }
       
    while (j < n) {
        result[l++] = arr3[j++];
    }
}

int main(int argc, char *argv[]) {
    int arr1[N], arr2[N], arr3[N];
    int result[3 * N];  
    
    printf("Introduce 3 elementos ordenados del primer arreglo: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Introduce 3 elementos ordenados del segundo arreglo: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Introduce 3 elementos ordenados del tercer arreglo: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr3[i]);
    }
   
    combinacion(arr1, arr2, arr3, result, N);
   
    printf("Arreglo combinado ordenado: ");
    for (int i = 0; i < 3 * N; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
