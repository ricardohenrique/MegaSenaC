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
        
        //limpa vari�veis setadas anteriormente
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
				jogar(jogos);
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
		printf("\n Numero[%.2d]: ", x); 		  		 
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
				//compara primeiro n�mero com os demais
                if (vetorOrdenado[0] == i && vetorOrdenado[1] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[2] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[3] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[0] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara segundo n�mero com os demais
                if (vetorOrdenado[1] == i && vetorOrdenado[2] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[1] == i && vetorOrdenado[3] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[1] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[1] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara terceiro n�mero com os demais
                if (vetorOrdenado[2] == i && vetorOrdenado[3] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[2] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[2] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara quarto n�mero com os demais
                if (vetorOrdenado[3] == i && vetorOrdenado[4] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                if (vetorOrdenado[3] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
                
                //compara quinto n�mero com os demais
                if (vetorOrdenado[4] == i && vetorOrdenado[5] == j) matrizCountDupla[i][j] = matrizCountDupla[i][j] + 1;
			}
		}
	}
	
	//SHOW DUPLAS
	for (i = 0; i < 61; i++) {
        for (j = 0; j < 61; j++) {
            if (matrizCountDupla[i][j] > 0){
                printf("\nDuplas %.2d e %.2d -> %.3d", i, j, matrizCountDupla[i][j]);
            }
        }
    }	
	getch();
}

void jogar(int jogos[countJogosLinha][countJogosColuna]){

    int i, j;
    int num;
    char jogadores[3][50];
    int jogadas[3][6];

	printf("\n");
	for(i = 0 ; i < 6 ; i++){
		printf(" | %d ", jogos[2999][i]);
	}
	printf("\n");
    for(i = 0 ; i < 3 ; i++){
        printf("Jogador %d: ", i + 1);
        scanf("%s", jogadores[i]);

        printf("\nInforme os 6 numeros\n");

        for(j = 0 ; j < 6 ; j++){
            scanf("%d", &jogadas[i][j]);
        }
    }
    
	system("cls");
    
	for(i = 0 ; i < 3 ; i++){
        printf("\nJogador %d %s\n", i + 1, jogadores[i]);
        for(j = 0 ; j < 6 ; j++){
			printf("%.2d ", jogadas[i][j]);
        }
    }
    
    getch();
	//--------------------------------------------------
	system("cls");
	
	int x, y, z, acertos[3][1];
			  		 
	acertos[0][1] = 0;
	acertos[1][1] = 0;		  		 
	acertos[2][1] = 0;
			  		 		  		 
    for(y = 0; y < countJogosColuna; y++){
		for(j = 0 ; j < 3 ; j++){
	        for(z = 0 ; z < 6 ; z++){
    			if(jogos[2999][y] == jogadas[j][z]){
    				acertos[j][1] = acertos[j][1] + 1;
				}
	        }
		}             
	}
	
	for(y = 0; y < 3; y++){
		printf("\nParabens %s, voce acertou %d numeros!", jogadores[y], acertos[y][1]);
	}   
	getch();
}


