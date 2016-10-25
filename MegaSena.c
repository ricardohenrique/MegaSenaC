#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define countJogosLinha	  3000
#define countJogosColuna  6

void bubbleSort(int vet[], int tam){
    int i, j;
    int aux;
    
    for (i=1; i<tam;i++){
        for (j=0;j<tam-i;j++){
              if (vet[j] > vet[j+1]){
                     aux = vet[j];
                     vet[j] = vet[j+1];
                     vet[j+1] = aux;
              }
         }
      }
}

void popularJogos(int jogos[3000][6], int countNumeroX[60][2]){
	int x, j, i;
	int status;
	int VALIDO = 1, INVALIDO = 0; 
	
	for(x = 0; x < 60; x++){
        countNumeroX[x][0] = x;
        countNumeroX[x][1] = 0;
	}
	
	srand(time(NULL));
	
	for(x = 0; x < countJogosLinha; x++){	 
		for (i = 0; i < countJogosColuna; ++i) {
			do {
				jogos[x][i] = 1+(rand() % 61);
				status = VALIDO;
				
				for (j = 0; j < i; ++j){
					if (jogos[x][i] == jogos[x][j]){
						status = INVALIDO;
					}
				}
			} while (status == INVALIDO);  
			
            for (j = 0; j < 60; j++) {
                if(countNumeroX[j][0] == jogos[x][i]) {
                    countNumeroX[j][1] = countNumeroX[j][1] + 1;
                }
            }
			
		}
	}
		
}

void mostrarJogos(int jogos[countJogosLinha][countJogosColuna]){
	int x, y, vetorOrdenado[6];
	
	for(x = 0; x < countJogosLinha; x++){
		printf("\nSorteio [%.2d]: ", (x + 1)); 		  		 
	    for(y = 0; y < countJogosColuna; y++){	
	    	vetorOrdenado[y] = jogos[x][y];
			printf("%.2d ", jogos[x][y]); 		              
        }   
		bubbleSort(vetorOrdenado, countJogosColuna);
		printf("[ ");
		for(y = 0; y < countJogosColuna; y++){	
			printf("%.2d ", vetorOrdenado[y]); 		              
        }  
        printf("]");
	}	
}

void mostrarCountNumeros(int countNumeroX[60][2]){
	int x;
	for(x = 1; x < 60; x++){
		printf("\n Numero [%.2d]: ", x); 		  		 
		printf("%.2d vezes", countNumeroX[x][1]); 	              
	}	
}

int main(){	
	int jogos[countJogosLinha][countJogosColuna];
	int countNumeroX[60][2];
	int x, y; 
	
	popularJogos(jogos, countNumeroX);
	mostrarJogos(jogos);	
	mostrarCountNumeros(countNumeroX);
}


