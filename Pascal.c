#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){


int numRows;

printf("Ingresa un numero del 1 al 30\n");
scanf("%i", &numRows);

if(numRows >= 1 && numRows <= 30){
int i, j;
int Pascal[numRows][numRows];

	for ( i = 0; i < numRows; i++) {
        for ( j = 0; j <= i; j++) {
            
            if (j == 0 || j == i) {
                Pascal[i][j] = 1; 
            } else {
                Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j]; 
            }
            printf("%i ", Pascal[i][j]); 
        }
        printf("\n"); 
    }
}else{
    printf("Numero no valido\n");
}



return 0;
}