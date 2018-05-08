/*
Calculadora de MATRIZES E VETORES:
Universidade Estadual do Ceara - UECE

Por :
Vitor Monteiro de Novaes Menezes
Vitor Wilker
Gabriel Bibiano

Professor : Dr. Leonardo
Introducao a computacao : Linguagem C
2017.1


Versao 1.1
*/

#include <stdio.h>
#include <stdlib.h>

struct aux{ // matrizes
	float **m1; //[A]
	float **m2; //[B]
}aux;

///////////////////////////////////////////////////////////////////////////// MATRIZES:
void LerMatrizes(int i1, int j1, int i2, int j2 ){
	int i,j; //variaveis contadoras

	// preenche matriz 1
	printf("\n\tMATRIZ [A] ----------------------------------\n");
	aux.m1 = (float **) malloc(i1 *sizeof(float));
	for (i = 0; i < i1 ; i++){ //linhas
		aux.m1[i] = (float *) malloc(j1 *sizeof(float));
		for(j = 0; j < j1 ; j++){ //colunas
			printf("\t\t|Digite o elemento A[%d][%d] : ",i+1,j+1);
			scanf("%f",&aux.m1[i][j]);
		}
	}

	//preenche matriz 2
	printf("\n\tMATRIZ [B] ----------------------------------\n");
	aux.m2 = (float **) malloc(i2 *sizeof(float));
	for(i = 0;i < i2; i++){
		aux.m2[i] = (float *) malloc(j2 *sizeof(float));
		for(j = 0; j < j2; j++){
			printf("\t\t|Digite o elemento B[%d][%d] : ",i+1,j+1);
			scanf("%f",&aux.m2[i][j]);
		}
	}
	putchar('\n');

	// caso nao aloque
	if(aux.m1 == NULL || aux.m2 == NULL){
		printf("\t!! Memoria nao suficiente para a execulcao da operacao !!");
	}
}

void ImprimirMatrizes(int i1, int j1, int i2, int j2){
	int i,j; // variaveis contadoras

		printf("\n\tMATRIZ [A] : \n");
		for(i = 0; i < i1; i++){
			printf("\t|");
				for(j = 0; j < j1; j++){
					printf(" %5.1f",aux.m1[i][j]);
				}
			printf("\n");
		}

		printf("\n\n\tMATRIZ [B] : \n");
		for(i = 0; i < i2; i++){
			printf("\t|");
				for(j = 0; j < j2; j++){
					printf(" %5.1f",aux.m2[i][j]);
				}
			printf("\n");
		}
		printf("\n");
}

void SomaMatrizes(int i1, int j1, int i2, int j2){
	//variaveis contadoras : 
	int i,j; 
	// matriz resultante :
	float **mSUM;

	if(i1 != i2 || j1 != j2){
		// condicao de existencia da soma :
		printf("\n\n\tOperacao invalida para as MATRIZES [A] e [B] :\n");
		printf("\tA MATRIZ [A]:%d x %d eh diferente da dimensao da MATRIZ [B]:%d x %d\n\n",i1,j1,i2,j2);
	}else{
		ImprimirMatrizes(i1,j1,i2,j2);
		
		// operacao da soma:
		mSUM = (float **) malloc(i1 *sizeof(float));
		for(i = 0; i < i1; i++){
			mSUM[i] = (float *) malloc(j1 *sizeof(float));
			for(j = 0; j < j1; j++){
				mSUM[i][j] = aux.m1[i][j] + aux.m2[i][j];
			}
		}
		
		// imprimi matriz resultante :
		printf("\tMATRIZ Resultante [A] + [B] :\n\t");
		for(i = 0; i < i1; i++){
			printf("|");
			for(j = 0; j < j1; j++){
				printf(" %5.2f ",mSUM[i][j]);
			}
			printf("\n\t");
		}
		free(mSUM);
	}
	printf("\n");
}

void SubtrairMatrizes(int i1, int j1, int i2, int j2){
	int i,j; // variaveis contadoras
	//matriz resultante :
	float mSUB[i1][j1];
	// matrizes para realizar operacao sem alterar aux.m1,aux.m2 :
	float mSUB1[i1][j1], mSUB2[i2][j2]; 
	// tratamento de erro da escolha
	char escolha[10];
	int esc;

	// Condicao para existencia da subtracao :
	if(i1 != i2 || j1 != j2){
		printf("\n\n\tOperacao invalida para as MATRIZES [A] e [B] :\n");
		printf("\tA MATRIZ [A]:%d x %d eh diferente da dimensao da MATRIZ [B]:%d x %d\n\n",i1,j1,i2,j2);
	}else{
		// FOR's que copiam os elementos do aux.m1, aux.m2 para Matrizes da operacao de subtracao :
		for(i = 0;i < i1; i++){
			for(j = 0; j < j1; j++){
				mSUB1[i][j] = aux.m1[i][j];
			}
		}
		for(i = 0;i < i2; i++){
			for(j = 0; j < j2; j++){
				mSUB2[i][j] = aux.m2[i][j];
			}
		}

		ImprimirMatrizes(i1,j1,i2,j2);
		do{ // ordem da operacao :
			printf("\n\t( MATRIZ [A] - MATRIZ [B] ) - - - 1 -\n");
			printf("\t( MATRIZ [B] - MATRIZ [A] ) - - - 2 -\n");
			printf("\n\t Escolha a ordem da operacao : ");
			scanf("%s",escolha);
			esc = atoi(escolha);
			setbuf(stdin,NULL);

			if(esc == 1){
				// inversao de m2 :
				for(i = 0; i < i2; i++){
					for(j = 0; j < j2; j++ ){
						mSUB2[i][j] = mSUB2[i][j] *(-1);
					}
				}
				// Realizacao da operecao :
				for(i = 0; i < i2; i++){
					for(j = 0; j < j2; j++){
						mSUB[i][j] = mSUB1[i][j] + mSUB2[i][j];
					}
				}
			}else{
				if(esc == 2){
					// invercao de m1
					for(i = 0; i < i1; i++){
						for(j = 0; j < j1; j++ ){
							mSUB1[i][j] = mSUB1[i][j] *(-1);
						}
					}
					// Realizacao da operacao :
					for(i = 0; i < i1; i++){
						for(j = 0; j < j1; j++){
							mSUB[i][j] = mSUB2[i][j] + mSUB1[i][j];
						}
					}
				}else{
					// caso nenhuma das opcoes :
					printf("\n\t\tDigite a opcao valida\n\n");
				}
			}
		}while(esc!=1 && esc!=2); // LOOP de erro

		// Resultado da subtracao ::
		printf("\n\tMATRIZ Resultante da subtracao : \n");
		for(i = 0; i < i1; i++){
			printf("\t|");
			for(j = 0; j < j1; j++){
				printf(" %5.1f",mSUB[i][j]);
			}
			putchar('\n');
		}	
		putchar('\n');	
	}
}

void MultiplicarMatrizReal(int i1, int j1, int i2, int j2){
	int i,j; // variaveis contadoras
	float escalar;
	// tratamento de erro :
	char escolhaMatrizS[10];
	int escolhaMatriz;

	printf("\n\t Informe um numero pra realizar a operacao : ");
	scanf(" %f",&escalar);

	ImprimirMatrizes(i1,j1,i2,j2);
	do{
		// ordem da operacao :
		printf("\n\tMATRIZ [A] %d x %d - - - - - - - - - - - - 1 -",i1,j1);
		printf("\n\tMATRIZ [B] %d x %d - - - - - - - - - - - - 2 -",i2,j2);
		printf("\n\tEscolha a MATRIZ para realizar a operacao : ");
		scanf("%s",escolhaMatrizS);
		escolhaMatriz = atoi(escolhaMatrizS);
		setbuf(stdin,NULL);

		if(escolhaMatriz == 1){
			// operacao com a matriz [A]:
			printf("\n\n\tMATRIZ [A] x %.2f : \n",escalar);
			for(i = 0; i < i1; i++){
				printf("\t|");
				for(j = 0; j < j1; j++){
					printf(" %5.2f ",aux.m1[i][j] * escalar);
				}
				printf("\n");
			}
			printf("\n");
		}else{
			if(escolhaMatriz == 2){
				// operacao com a matriz [B] :
				printf("\n\n\tMATRIZ [B] x %.2f : \n",escalar);
				for(i = 0; i < i2; i++){
					printf("\t|");
					for(j = 0; j < j2; j++){
						printf(" %5.2f ",aux.m2[i][j] * escalar);
					}
					printf("\n");
				}
				printf("\n");
			}else{
				//caso opcao invalida :
				printf("\n\t\tDigite a opcao valida\n\n");
			}
		}
	}while(escolhaMatriz!=1 && escolhaMatriz!=2); // loop caso nao digite 1 ou 2
}

void MultiplicarMatrizes(int i1, int j1, int i2, int j2){
	//variaveis contadoras e variavel auxiliar da multiplicacao :
	int i,j,im,jm,auxiliar = 0;
	
	float mMULT1[i1][j2]; // Matriz resultante da [A] x [B]
	float mMULT2[i2][j1]; // Matriz resultante da [B] x [A]
	
	// tratamento de erro :
	char escolha[10];
	int esc;

	if((j1 != i2) && (j2 != i1)){
		printf("\n\n\tOperacao invalida para as MATRIZES [A] e [B] :\n");
		printf("\tA MATRIZ [A]:%d x %d eh diferente da dimensao da MATRIZ [B]:%d x %d\n\n",i1,j1,i2,j2);
	}else{
		ImprimirMatrizes(i1,j1,i2,j2);
		do{
			printf("\n\t( MATRIZ [A] x MATRIZ [B] ) - - - 1 -\n");
			printf("\t( MATRIZ [B] x MATRIZ [A] ) - - - 2 -\n");
			printf("\n\t Escolha a ordem da operacao : ");
			scanf("%s",escolha);
			esc = atoi(escolha);
			setbuf(stdin,NULL);

			if(esc == 1){

				// condicao de existencia da multiplicacao [A]x[B]
				if(j1 == i2){
					// mMULT1[i1][j2] como resultante :
					// ZERA elementos da matriz auxiliar :
					for(i=0;i<i1;i++){
						for(j=0;j<j2;j++){
							mMULT1[i][j] = 0;
						}
					}
					// operacao de multiplicacao [A] x [B] = mMULT1[i1][j2] :
					// linha da resultante : i1
					for(i=0;i<i1;i++){ 
						// coluna da resultante : j2
						for(j=0;j<j2;j++){
							// [A] i1 x jm >>> 'i1' da operacao sera fixa , 'jm' percorre os elementos da linha 
							// [B] im x j2 >>> 'j2' sera fixo, 'im' percorre os elementos da coluna
							for(im=0,jm=0; (im<i2) && (jm<j1); jm++,im++){
								auxiliar = (aux.m1[i][jm] * aux.m2[im][j]);
								mMULT1[i][j] = mMULT1[i][j] + auxiliar;
							}
						}
					}
					// Imprimi Resultado [A] x [B] :
					printf("\n\tMATRIZ [A] x [B] :\n");
					for(i = 0; i < i1; i++){
						printf("\t|");
						for(j = 0; j < j2; j++){
							printf(" %5.2f ",mMULT1[i][j]);
						}
						printf("\n");
					}
					printf("\n");
				}else{
					// caso a condicao da multiplicao seja invalida
					printf("\n\n\tOperacao invalida [A] x [B] :\n");
					printf("\t O numero de colunas da MATRIZ [A]: %d \n\t eh diferente \n\t do numero de linhas da MATRIZ [B]: %d \n\n",j1,i2);
				}

			}else{
				if(esc == 2){
					
					// condicao de existencia da multiplicacao [B]x[A]
					if(j2 == i1){
						// mMULT2[i2][j1] como resultante :
						// ZERA todos os elementos matriz auxiliar
						for(i=0;i<i2;i++){
							for(j=0;j<j1;j++){
								mMULT2[i][j] = 0;
							}
						}

						// operacao de multiplicacao [B] x [A]
						// linha da resultante : i2
						for(i=0;i<i2;i++){
							// coluna da resultante : j1
							for(j=0;j<j1;j++){
								// [B] i2 x jm >>> 'i2' da operacao sera fixa , 'jm' percorre os elementos da linha 
								// [A] im x j1 >>> 'j1' sera fixo, 'im' percorre os elementos da coluna
								for(im=0,jm=0; (im<i1) && (jm<j2); jm++,im++){
									auxiliar = (aux.m2[i][jm] * aux.m1[im][j] );
									mMULT2[i][j] = mMULT2[i][j] + auxiliar;
								}
							}
						}
						// Imprimi Resultado [B] x [A] :
						printf("\n\tMATRIZ [B] x [A] :\n");
						for(i = 0; i < i2; i++){
							printf("\t|");
							for(j = 0; j < j1; j++){
								printf(" %5.2f ",mMULT2[i][j]);
							}
							printf("\n");
						}
						printf("\n");
					}else{
						// caso a operacao seja invalida :
						printf("\n\n\tOperacao invalida para a operacao [B] x [A] :\n");
						printf("\t O numero de colunas da MATRIZ [B]: %d \n\t eh diferente \n\t do numero de linhas da MATRIZ [A]: %d \n\n",j2,i1);
					}

				}else{
					// caso opcao do menu seja invalida :
					printf("\n\t\t! Digite a opcao valida !\n\n");
				}
			}
		}while(esc!=1 && esc!= 2); // LOOP caso nao digite 1 ou 2
	}	
} 

void TranspostaMatriz(int i1, int j1, int i2, int j2){
	int i,j; // variaveis contadoras
	// tratamento de erro
	char escolhaMatrizS[10];
	int escolhaMatriz;

	ImprimirMatrizes(i1,j1,i2,j2);
	do{
		printf("\n\t MATRIZ [A] %d x %d - - - - - - - - - - - - 1 -",i1,j1);
		printf("\n\t MATRIZ [B] %d x %d - - - - - - - - - - - - 2 -",i2,j2);
		printf("\n\t Escolha a MATRIZ para realizar a operacao : ");
		scanf("%s",escolhaMatrizS);
		escolhaMatriz = atoi(escolhaMatrizS);
		setbuf(stdin,NULL);

		if(escolhaMatriz == 1){
			// transposta de A : inverte linha e coluna :
			printf("\n\tMATRIZ [A\'] : \n");
			for(i = 0; i < j1; i++){
				printf("\t|");
				for(j = 0; j < i1; j++){
					printf(" %5.1f",aux.m1[j][i]);
				}
				printf("\n");
			}
			printf("\n");
		}else{
			if(escolhaMatriz == 2){
				// transposta de B : inverte linha e coluna :
				printf("\n\tMATRIZ [B\'] : \n");
				for(i = 0; i < j2; i++){
					printf("\t|");
					for(j = 0; j < i2; j++){
						printf(" %5.1f",aux.m2[j][i]);
					}
					printf("\n");
				}
				printf("\n");
			}else{
				printf("\n\t\tDigite a opcao valida\n\n");
			}
		}
	}while(escolhaMatriz!=1 && escolhaMatriz!=2);
}

void DeterminanteMatriz(int i1, int j1, int i2, int j2){
	int i,j;// variaveis contadoras
	// tratamento de erro
	char escolhaMatrizS[10];
	int escolhaMatriz;
	// armazenar valor da determinante de matriz terceira ordem :
	float det;

	if((i1 != j1) && (i2 != j2)){
		// condicao de existencia invalida tanto pra A quanto pra B :
		printf("\n\n\tNao eh possivel realizar a operacao para as MATRIZES [A] e [B] :\n");
		printf("\tMATRIZ [A]: %d x %d  \n\tMATRIZ [B]: %d x %d \n\n",i1,j1,i2,j2);
	}else{
		if((i1 >= 4 && j1 >= 4) && (i2 >= 4 && j2 >= 4)){
			// caso superior a ordem 3 :
			printf("\n\n\tNao eh possivel realizar a operacao para as MATRIZES [A] e [B] :\n");
			printf("\tMATRIZ [A]: %d x %d  \n\tMATRIZ [B]: %d x %d \n\tMATRIZES superiores a 3° ordem\n\n",i1,j1,i2,j2);
		}else{
			ImprimirMatrizes(i1,j1,i2,j2);
			do{
				printf("\n\t MATRIZ [A] %d x %d - - - - - - - - - - - - 1 -",i1,j1);
				printf("\n\t MATRIZ [B] %d x %d - - - - - - - - - - - - 2 -",i2,j2);
				printf("\n\t Escolha a MATRIZ para realizar a operacao : ");
				scanf("%s",escolhaMatrizS);
				escolhaMatriz = atoi(escolhaMatrizS);
				setbuf(stdin,NULL);

				if(escolhaMatriz == 1){
				
					if(i1 != j1){	
						// caso invalido somente para matriz A
						printf("\n\n\tOperacao invalida para a MATRIZ [A]:\n");
						printf("\tMATRIZ [A]:%d x %d \n\n",i1,j1);
					}else{
						if(i1 == 1){
							// caso matriz de tamanho 1x1
							printf("\n\tDeterminante da MATRIZ [A] = %.1f\n\n",aux.m1[0][0]);
						}else{
							if(i1 == 2){
								// caso matriz de tamanho 2x2
								printf("\n\tDeterminante da MATRIZ [A] = %.2f \n\n",(aux.m1[0][0] * aux.m1[1][1]) - (aux.m1[0][1] * aux.m1[1][0]) );
							}else{
								if(i1 == 3){
									// caso matriz 3x3
									det = 	(aux.m1[0][0] * aux.m1[1][1] * aux.m1[2][2]) + // diagonal principal
											(aux.m1[2][0] * aux.m1[0][1] * aux.m1[1][2]) +	// paralelas
											(aux.m1[1][0] * aux.m1[2][1] * aux.m1[0][2]) +	// paralelas
											((aux.m1[2][0] * aux.m1[1][1] * aux.m1[0][2])*(-1)) + // diagonal secundaria
											((aux.m1[0][0] * aux.m1[2][1] * aux.m1[1][2])*(-1)) + // paralelas
											((aux.m1[1][0] * aux.m1[0][1] * aux.m1[2][2])*(-1)); // paralelas
									printf("\n\tDeterminante da MATRIZ [A] = %.2f \n\n", det);
								}else{
									if(i1 >= 4){
										// caso superior a ordem 3
										printf("\n\n\tOperacao invalida para a MATRIZ [A]:\n");
										printf("\tMATRIZ [A]: %d x %d \n\tMATRIZ de ordem superior a 3\n\n",i1,j1);
									}
								}							
							}
						}
					}
		
				}else{
					
					if(escolhaMatriz == 2){
						if(i2 != j2){
							// caso so a matriz B invalida
							printf("\n\n\tOperacao invalida para a MATRIZ [B] :\n");
							printf("\tMATRIZ [B]: %d x %d \n\n",i2,j2);
						}else{
							if(i2 == 1){
								// caso matriz de tamanho 1x1
								printf("\n\tDeterminante da MATRIZ [B] = %.1f\n\n",aux.m2[0][0]);
							}else{
								if(i2 == 2){
									// caso matriz de tamanho 2x2
									printf("\n\tDeterminante da MATRIZ [B] = %.2f \n\n",(aux.m2[0][0] * aux.m2[1][1]) - (aux.m2[0][1] * aux.m2[1][0]) );
								}else{
									if(i2 == 3){
										// caso matriz 3x3
										det = 	(aux.m2[0][0] * aux.m2[1][1] * aux.m2[2][2]) + // diagonal principal (i==j)
												(aux.m2[2][0] * aux.m2[0][1] * aux.m2[1][2]) +	// paralelas 
												(aux.m2[1][0] * aux.m2[2][1] * aux.m2[0][2]) +	// paralelas
												((aux.m2[2][0] * aux.m2[1][1] * aux.m2[0][2])*(-1)) + // diagonal secundaria
												((aux.m2[0][0] * aux.m2[2][1] * aux.m2[1][2])*(-1)) + // paralelas
												((aux.m2[1][0] * aux.m2[0][1] * aux.m2[2][2])*(-1)); // paralelas
										printf("\n\tDeterminante da MATRIZ [B] = %.2f \n\n", det);
									}else{
										if(i2 >= 4){
											// caso superior a ordem 3
											printf("\n\n\tOperacao invalida para a MATRIZ [B]:\n");
											printf("\tMATRIZ [B]: %d x %d \n\tMATRIZ de ordem superior a 3\n\n",i1,j1);
										}
									}
								}
							}
						}
					
					}else{
						// caso opcao invalida no menu
						printf("\n\t\tDigite a opcao valida !\n\n");
					}
				}
			}while(escolhaMatriz!=1 && escolhaMatriz!=2); // loop caso nao digite 1 ou 2 
		
		}	
	}
}

void SimetriaMatriz(int i1, int j1, int i2, int j2){
	int i,j,ic,jc,cont = 0; // variaveis contadoras 
	// tratamento de erro :
	char escolhaMatrizS[10];
	int escolhaMatriz;
						
		if((i1 != j1) && (i2 != j2)){
			// caso nehuma seja simetrica :
			printf("\n\n\tAs MATRIZES [A] e [B] nao sao simetricas ! \n\n");
		}else{
			ImprimirMatrizes(i1,j1,i2,j2);
			do{
				printf("\n\tMATRIZ [A] %d x %d - - - - - - - - - - - - 1 -",i1,j1);
				printf("\n\tMATRIZ [B] %d x %d - - - - - - - - - - - - 2 -",i2,j2);
				printf("\n\tEscolha a MATRIZ para realizar a operacao : ");
				scanf("%s",escolhaMatrizS);
				escolhaMatriz = atoi(escolhaMatrizS);
				setbuf(stdin,NULL);
				
				if(escolhaMatriz == 1){
					
					if(i1 == j1){
						// transposta de A // matriz A
						for(i = 0,ic = 0; (i < j1) && (ic < i1); i++,ic++){
							for(j = 0,jc = 0; (j < i1) && (jc < j1); j++,jc++){
								if(aux.m1[j][i] == aux.m1[ic][jc]){
									// contar quantas vezes a condicao eh verdadeira :
									cont = cont + 1;	
								}else{
									continue;
								}		
							}
						}
						// verifica a simetria :
						if(cont == (i1*j1)){ // total de elementos :
							printf("\n\n\tA MATRIZ [A] eh simetrica :\n");
							printf("\tMATRIZ [A]:%d x %d \n\n",i1,j1);
						}else{
							printf("\n\n\tA MATRIZ [A] NAO eh simetrica :\n");
							printf("\tMATRIZ [A]:%d x %d \n\n",i1,j1);
						}
					}else{
						printf("\n\n\tA MATRIZ [A] NAO eh simetrica :\n");
						printf("\tMATRIZ [A]:%d x %d \n\n",i1,j1);
					}
				
				}else{
					if(escolhaMatriz == 2){
						
						if(i2 == j2){
							// Transposta de B // Matriz B :
							for(i = 0,ic = 0; (i < j2) && (ic < i2); i++,ic++){
								for(j = 0,jc = 0; (j < i2) && (jc < j2); j++,jc++){
									// contar quantas vezes a condicao eh verdadeira :
									if(aux.m2[j][i] == aux.m2[ic][jc]){
										cont = cont + 1;		
									}else{
										continue;
									}		
								}
							}		
							// verifica a simetria :
							if(cont == (i2*j2)){
								printf("\n\n\tA matriz [B] eh simetrica :\n");
								printf("\tMATRIZ [B]:%d x %d \n\n",i2,j2);
							}else{
								printf("\n\n\tA MATRIZ [B] NAO eh simetrica :\n");
								printf("\tMATRIZ [B]:%d x %d \n\n",i2,j2);
							}
						}else{
							printf("\n\n\tA MATRIZ [B] NAO eh simetrica :\n");
							printf("\tMATRIZ [B]:%d x %d \n\n",i2,j2);
						}
					
					}else{
						// caso opcao invalida no menu :
						printf("\n\t\tDigite a opcao valida\n\n");
					}
				}
			}while(escolhaMatriz!=1 && escolhaMatriz!=2); // loop caso nao digite 1 ou 2 :
		}
} 