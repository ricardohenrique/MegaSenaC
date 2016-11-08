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
	int countNumeroX[61][2];
	int x, y; 
    char op;
    
    while(1){

        system("cls");

		printf("-------------------------------------\n");
        printf("-------------Mega Sena---------------\n");
        printf("-------------1 Sortear---------------\n");
        printf("-------------2 Dados-----------------\n");
        printf("-------------3 Jogar-----------------\n");
        printf("-------------0 Sair------------------\n");
        printf("-------------------------------------\n");
        printf("Digite a opcao desejada: ");
        
        //limpa variáveis setadas anteriormente
        fflush(stdin);
		scanf("%c", &op);

        switch(op){

            case '1' : 
				popularJogos(jogos, countNumeroX);
				mostrarJogos(jogos);	
			break;
            case '2' : 
            	mostrarCountNumeros(countNumeroX);  
				duplasMaisSorteadas(jogos);         
			break;
            case '3' : 
				//jogada(sorteios);                
			break;
            case '0' : 
				printf("\nObrigado por jogar, volte sempre.\n");    
				exit(0);
            default  : 
				printf("\nOpcao nao encontrada, digite novamente\n");
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
	
	for(x = 0; x < 61; x++){
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
			
            for (j = 0; j < 61; j++) {
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
	getch();	
}

void mostrarCountNumeros(int countNumeroX[61][2]){
	int x;
	for(x = 1; x < 61; x++){
		printf("\n Numero [%.2d]: ", x); 		  		 
		printf("%.2d vezes", countNumeroX[x][1]); 	              
	}	
	getch();
}


void duplasMaisSorteadas(int jogos[countJogosLinha][countJogosColuna]){
	int x, y, i, j, vetorOrdenado[6], matrizCountDupla[61][61];
	
    for (i = 0; i < 61; i++) {
        for (j = 0; j < 61; j++) {
            matrizCountDupla[i][j] = 0;
        }
    }
    
	for(x = 0; x < countJogosLinha; x++){		  		 
	    for(y = 0; y < countJogosColuna; y++){	
	    	vetorOrdenado[y] = jogos[x][y];		              
        }   
		bubbleSort(vetorOrdenado, countJogosColuna);

        for (i = 0; i < 61; i++) {
            for (j = 0; j < 61; j++) {
				//compara primeiro número com os demais
                if (vetorOrdenado[0] == i && vetorOrdenado[1] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[2] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[3] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara segundo número com os demais
                if (vetorOrdenado[1] == i && vetorOrdenado[2] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[1] == i && vetorOrdenado[3] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[1] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[1] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara terceiro número com os demais
                if (vetorOrdenado[2] == i && vetorOrdenado[3] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[2] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[2] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara quarto número com os demais
                if (vetorOrdenado[3] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[3] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara quinto número com os demais
                if (vetorOrdenado[4] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
			}
		}
	}
	
	//SHOW DUPLAS
	for (i = 0; i < 61; i++) {
        for (j = 0; j < 61; j++) {
            if (matrizCountDupla[i][j] > 0){
                printf("\nDuplas %d e %d -> %d", i, j, matrizCountDupla[i][j]);
            }
        }
    }	
	getch();
}

