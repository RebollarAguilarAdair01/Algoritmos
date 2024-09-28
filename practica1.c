#include<stdio.h>

int main (int argc, char *argv[]){

	int numeros[9]={ 1, 1, 2, 2, 3, 3, 4, 5, 5};

	int i,j, k, nums;
	nums =0;

	for(i =0; i<=8; i++){
		if (numeros[i] == numeros[i+1]){
			for(j=i; j<=7; j++){
				numeros[j]=numeros[j+1];
			}
		}
		if(numeros[i] != numeros[i+1]){
			nums++;
		}
	}

	printf("\nNumero de valores unicos: %i\n", nums);
	for(k=0; k<nums; k++){
		printf("\n%i", numeros[k]);
	}

	return 0;
}