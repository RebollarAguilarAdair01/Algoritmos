#include<stdio.h>
#include<time.h>

int main(int argc, char *argv[]){
	int m, n, i, j,k, num, z, h;
	int par;
	float mediana;

	clock_t comienzo;

   	comienzo = clock();

	printf("¿Cuantos elementos quieres agregar en el arreglo 1?\n");
	scanf("%i", &m);

	printf("¿Cuantos elementos quieres agregar en el arreglo 2?\n");
	scanf("%i", &n);

	printf("\nIngresa los elemos de menor a mayor: ");
	printf("\nArreglo 1: ");

	int arrUno[m];
	int arrDos[n];

	for(i=0; i <m; i++){
		printf("\n %i: ", i+1);
		scanf("%i", &num);
		arrUno[i] = num;
	}

	printf("\nArreglo 2: ");

	for(j=0; j <n; j++){
		printf("\n %i: ", j+1);
		scanf("%i", &num);
		arrDos[j] = num;
	}

	z = n+m;

	int arr3[z];
	i=0;
	j=0;

	for(k=0; k<z; k++){

		if(i==m && j<n){
			arr3[k] = arrDos[j];
			if(j<n){
				j++; 
			}
		}
		if(j==n && i<m){
			arr3[k] = arrUno[i];
			if(i<m){
				i++;
			}
		}
		
		if(arrUno[i] < arrDos[j] && i!=m && j!=n){
			arr3[k] = arrUno[i];
			if(i<m){
				i++;
			}
		}else{
			if(arrUno[i] > arrDos[j] && i!=m && j!=n){
			arr3[k] = arrDos[j];
					if(j<n){
						j++;
					}
				}
				else{
					if(arrUno[i] == arrDos[j] && i!=m && j!=n){
					arr3[k] = arrUno[i];
							if(i<m){
								i++;
							}
						}
				}
		}
		

	}

 	par = z % 2; 
 	
 	if(par!=0){
 		k = (z--) / 2;
 		printf("\n La mediana es: %i ", arr3[k]);
 	}else{
 		mediana = (arr3[z/2] + arr3[(z/2) -1 ])/2;
 		printf("\n La mediana es: %.2f ", mediana);
 	}

  	printf("\nNumero de segundos transcurridos desde el comienzo del programa: %f s\n", (clock()-comienzo)/(double)CLOCKS_PER_SEC );
	return 0;
}