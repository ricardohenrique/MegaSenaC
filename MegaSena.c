#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define countJogosLinha	  3000
#define countJogosColuna  6

int main(){	
	menu();
}


void menu(void){
	int jogos[countJogosLinha][countJogosColuna];
	int countNumeroX[60][2];
	int x, y; 
    char op;
    while(1){

        system("cls");

		printf("-------------------------------------\n");
        printf("-------------Mega Sena---------------\n");
        printf("-------------1 Sortear---------------\n");
        printf("-------------2 Estatistica-----------\n");
        printf("-------------3 Jogar-----------------\n");
        printf("-------------0 Sair------------------\n");
        printf("-------------------------------------\n");
        printf("Digite a opcão desejada: ");
        scanf("%c", &op);

        switch(op){

            case '1' : 
				popularJogos(jogos, countNumeroX);
				mostrarJogos(jogos);	
			break;
            case '2' : 
            	mostrarCountNumeros(countNumeroX);           
			break;
            case '3' : 
				//jogada(sorteios);                
			break;
            case '0' : 
				printf("\nVolte sempre!!\n");    
				exit(0);
            default  : 
				printf("\nOpção não existe!!\n");
                getch();                        
			break;
        }
    }
}


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



