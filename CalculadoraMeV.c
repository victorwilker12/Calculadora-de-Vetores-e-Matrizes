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

//////////////////////////////////////////////////////////// PROGRAMA //////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fvet.h"
#include "fmat.h"


void MenuVetor(); //OK
void MenuMatriz();//OK
void MenuPrincipal();//OK

// struct de vetores :
struct vetor{	// n = tamanho do vetor
	int n1;
	int n2;
	float *v1;
	float *v2;
}vetor;

//struct da dimensao matrizes :
struct matriz{	// i = linhas // j = colunas
	int i1;
	int j1;
	int i2;
	int j2;
}matriz;

//////////////////////////////////////////////////// menu vetor :
void MenuVetor(){
	//variaveis do menu (switch) com tratamento de erro :
	long int CodMenuVetor;
	char escolha1[10];
	//variaveis do tamanho vetor e da confirmacao, com tratamento de erro :
	int ask; //confirmacao
	char askErro[10]; //confirmacao
	char tamanhoVetor[10];

	printf("\n---------------- OPERACAO COM VETORES ----------------\n");
	do{ //digitar o tamanho dos vetores
		// Tamanho do vetor 1 :
		printf("\n\tDIGITE O TAMANHO DO VETOR [1] :");
		scanf("%s",tamanhoVetor);
       	vetor.n1 = atoi(tamanhoVetor); //struct vetor.n1
		setbuf(stdin,NULL);// limpar buffer

		//Tamanho do vetor 2 :
		printf("\n\tDIGITE O TAMANHO DO VETOR [2] :");
		scanf("%s",tamanhoVetor);
        vetor.n2 = atoi(tamanhoVetor);// struct vetor.n2
		setbuf(stdin,NULL);

		//confirmar com o usuario o tamanho dos vetores :
		printf("\n\tTamanho do VETOR [1] = %d\n\tTamanho do VETOR [2] = %d\n\n",vetor.n1,vetor.n2);
		printf("\tConfirmar ?\n");
		printf("\t\tSIM - - - - - - 1 -\n");
		printf("\t\tNAO - - - - - - 2 -\n");
		printf("\t\tVOLTAR MENU - - 3 -\n");
		printf("\t\t\t\t");
		scanf("%s",askErro);
		ask = atoi(askErro);//confirmacao
		setbuf(stdin,NULL);//limpa o buffer da string digitada 

			// condicoes da confirmacao do usuario :
			if(ask!=2 && ask!=1 && ask!=3){
				// caso nenhuma das opcoes :
				printf("\t\tDigite a opcao valida\n"); 
			}else{
				if(ask == 3){
					MenuPrincipal();//chama o menu principal 
				}else{
					if(vetor.n1<=0 || vetor.n2<=0){
						// caso tamanho de um dos vetores invalidos :
						printf("\n\tTamanho de VETOR invalida para operacoes :\n");
						printf("\tVETORES : [1] = %d / [2] = %d\n\n",vetor.n1,vetor.n2);
						ask = 2;
					}
				}
			}
	}while(ask!=1); // loop caso o usuario nao digite 1

	// alocamento dinamico do tamanho dos vetores
	vetor.v1 = (float *) malloc(vetor.n1 *sizeof(int));
	vetor.v2 = (float *) malloc(vetor.n2 *sizeof(int));

	//retorna mensagem caso memoria insuficiente
	if(vetor.v1==NULL || vetor.v2==NULL){
		printf("\t!! Memoria nao suficiente para a execulcao da operacao !!");
	}else{
		LerVetores(vetor.v1,vetor.v2,vetor.n1,vetor.n2);
		ImprimirVetores(vetor.v1,vetor.v2,vetor.n1,vetor.n2);
	}

	do{ 
	    printf("LER VETORES NOVAMENTE  - - - - - - - - - 1 -\n");
	    printf("SOMAR DOIS VETORES - - - - - - - - - - - 2 -\n");
		printf("SUBTRACAO DE VETORES - - - - - - - - - - 3 -\n");
		printf("MULTIPLICAR VETORES POR ESCALAR  - - - - 4 -\n");
		printf("MULTIPLICAR DOIS VETORES - - - - - - - - 5 -\n");
		printf("VOLTAR AO MENU PRINCIPAL - - - - - - - - 6 -\n");
		printf("DIGITE O NUMERO DA OPERACAO DESEJADA : ");

		scanf("%s",escolha1);
		CodMenuVetor = atoi(escolha1); // transforma uma string em int
		setbuf(stdin,NULL);//limpa o buffer da string digitada 

		switch(CodMenuVetor){
			case 1: // Ler vetores novamente
					do{ //digitar o tamanho dos vetores
						// Tamanho do vetor 1 :
						printf("\n\tDIGITE O TAMANHO DO VETOR [1] :");
						scanf("%s",tamanhoVetor);
       					vetor.n1 = atoi(tamanhoVetor); //struct vetor.n1
						setbuf(stdin,NULL);// limpar buffer

						//Tamanho do vetor 2 :
						printf("\n\tDIGITE O TAMANHO DO VETOR [2] :");
						scanf("%s",tamanhoVetor);
        				vetor.n2 = atoi(tamanhoVetor);// struct vetor.n2
						setbuf(stdin,NULL);

						//confirmar com o usuario o tamanho dos vetores :
						printf("\n\tTamanho do VETOR [1] = %d\n\tTamanho do VETOR [2] = %d\n\n",vetor.n1,vetor.n2);
						printf("\tConfirmar ?\n");
						printf("\t\tSIM - - - - - - 1 -\n");
						printf("\t\tNAO - - - - - - 2 -\n");
						printf("\t\t\t\t");
						scanf("%s",askErro);
						ask = atoi(askErro);
						setbuf(stdin,NULL);

							if(ask!=2 && ask!=1 && ask!=3){
								// caso nehuma das opcoes :
								printf("\t\tDigite a opcao valida\n");
							}else{
								if(vetor.n1<=0 || vetor.n2<=0){
									// caso tamanho do vetor invalido :
									printf("\n\tTamanho de VETOR invalida para operacoes :\n");
									printf("\tVETORES : [1] = %d / [2] = %d\n\n",vetor.n1,vetor.n2);
									ask = 2;
								}else{
									continue;
								}
							}
					}while(ask!=1); // loop caso o usuario nao digite 1

					// alocamento dinamico do tamanho dos vetores
					vetor.v1 = (float *) malloc(vetor.n1 *sizeof(float));
					vetor.v2 = (float *) malloc(vetor.n2 *sizeof(float));

					//retorna mensagem caso memoria insuficiente
					if(vetor.v1==NULL || vetor.v2==NULL){
						printf("\t!! Memoria nao suficiente para a execulcao da operacao !!");
					}else{
						LerVetores(vetor.v1,vetor.v2,vetor.n1,vetor.n2);
						ImprimirVetores(vetor.v1,vetor.v2,vetor.n1,vetor.n2);
					}
					break;
			case 2: // Somar vetores
					printf("\n\t------------ SOMA DE VETORES -----------\n\n");
					SomaVetores(vetor.v1, vetor.v2, vetor.n1,vetor.n2);
				 	break;
			case 3: // Subtracao de vetores
					printf("\n\t------------ SUBTRACAO DE VETORES -----------\n\n");
					SubtracaoVetores(vetor.v1,vetor.v2,vetor.n1,vetor.n2);
					break;
			case 4: // Multiplicacao de vetor por escalar
					printf("\n\t------------ MULTIPLICACAO POR ESCALAR -----------\n\n");
					MultiplicarVetoresEsc(vetor.v1,vetor.v2,vetor.n1,vetor.n2);
					break;
			case 5: // multiplicar dois vetores
					printf("\n\t------------ MULTIPLICACAO DE VETORES -----------\n\n");
					MultiplicarVetores(vetor.v1,vetor.v2,vetor.n1,vetor.n2);
					break;
			case 6: // voltar pro menu
					printf("\n\n====================== MENU PRINCIPAL ==========================\n");
					free (vetor.v1);//libera a memoria alocada dos vetores
					free (vetor.v2);//
					MenuPrincipal();//volta ao menu principal
					break;
			default:// caso codigo invalido
					printf("\n\n-----------------------ERRO 404---------------------------------\n");
					printf("Codigo invalido !\nPor Favor digite o numero da operacao correspondente:\n\n");
		}
	}while(CodMenuVetor!=6); //MENU VETOR
}

// menu matrizes:
void MenuMatriz(){
	// variaveis do menu matriz
	int CodMenuMatriz;
	char escolha2[10];
	// variaveis do numero de colunas e linhas das matrizes
	char linhaA[10],colunaA[10],linhaB[10],colunaB[10];
	// tratamento de erro do usuario
	int ask;
	char askErro[10];

	printf("\n---------------- OPERACAO COM MATRIZES ----------------\n");

	do{
		// matriz A
		printf("\n\tMATRIZ [A] ----------------------------------\n");
		printf("\n\t|Digite o numero de linhas [i] : ");
		scanf("%s",linhaA);
		matriz.i1 = atoi (linhaA);//tratamento de erro de string
		setbuf(stdin,NULL);/////////////////////////////////////
		printf("\t|Digite o numero de colunas [j] : ");
		scanf("%s",colunaA);
		matriz.j1 = atoi (colunaA);//tratamento de erro de string
		setbuf(stdin,NULL);//////////////////////////////////////

		// matriz B
		printf("\n\tMATRIZ [B] ----------------------------------\n");
		printf("\n\t|Digite o numero de linhas [i] : ");
		scanf("%s",linhaB);
		matriz.i2 = atoi(linhaB);
		printf("\t|Digite o numero de colunas [j] : ");
		scanf("%s",colunaB);
		matriz.j2 = atoi(colunaB);

		//confirmar com o usuario o tamanho das matrizes // tratamento de erro do usuario
		printf("\n\t|Dimensao da MATRIZ [A] : %d x %d\n\n",matriz.i1,matriz.j1);
		printf("\t|Dimensao da MATRIZ [B] : %d x %d\n\n",matriz.i2,matriz.j2);
		printf("\tConfirmar ?\n");
		printf("\t\tSIM - - - - - - 1 -\n");
		printf("\t\tNAO - - - - - - 2 -\n");
		printf("\t\tVOLTAR MENU - - 3 -\n");
		printf("\t\t\t\t");
		scanf("%s",askErro);
		ask = atoi(askErro);
		setbuf(stdin,NULL);

			if(ask!=2 && ask!=1 && ask!=3){
				// caso nenhuma das opcoes validas :
				printf("\t\tDigite a opcao valida\n");
			}else{
				if(ask == 3){
					MenuPrincipal();
				}else{
					if(matriz.i1<=0 || matriz.j1<=0 || matriz.i2<=0 || matriz.j2<=0){
						// tamanho da matriz invalida :
						printf("\n\tTamanho de MATRIZ invalida para operacoes :\n");
						printf("\n\t|Dimensao da MATRIZ [A] : %d x %d\n\n",matriz.i1,matriz.j1);
						printf("\t|Dimensao da MATRIZ [B] : %d x %d\n\n",matriz.i2,matriz.j2);
						ask = 2;
					}
				}

			}
	}while(ask!=1); // LOOP caso nao digite 1

	LerMatrizes(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
	ImprimirMatrizes(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
	
	do{
		printf("LER MATRIZES NOVAMENTE  - - - - - - - - - - 1 -\n");
		printf("SOMA DE DUAS MATRIZES - - - - - - - - - - - 2 -\n");
		printf("SUBTRACAO DE MATRIZES - - - - - - - - - - - 3 -\n");
		printf("MULTIPLICAR UMA MATRIZ POR UM NUMERO- - - - 4 -\n");
		printf("MULTIPLICAO DE DUAS MATRIZES  - - - - - - - 5 -\n");
		printf("TRANSPOSTA DE UMA MATRIZ  - - - - - - - - - 6 -\n");
		printf("CALCULAR A DETERMINANTE DE UMA MATRIZ - - - 7 -\n");
		printf("VERIFICAR A SIMETRIA DE UMA MATRIZ  - - - - 8 -\n");
		printf("VOLTAR AO MENU PRINCIPAL  - - - - - - - - - 9 -\n");
		printf("DIGITE O NUMERO DA OPERACAO DESEJADA : ");

		scanf("%s",escolha2);
		CodMenuMatriz = atoi(escolha2); // string para int
		setbuf(stdin,NULL);	// limpar buffer

		switch(CodMenuMatriz){
			case 1: // ler matriz
					do{
						// matriz A
						printf("\n\tMATRIZ [A] ----------------------------------\n");
						printf("\n\t|Digite o numero de linhas [i] : ");
						scanf("%s",linhaA);
						matriz.i1 = atoi (linhaA);
						setbuf(stdin,NULL);
						printf("\t|Digite o numero de colunas [j] : ");
						scanf("%s",colunaA);
						matriz.j1 = atoi (colunaA);
						setbuf(stdin,NULL);

						// matriz B
						printf("\n\tMATRIZ [B] ----------------------------------\n");
						printf("\n\t|Digite o numero de linhas [i] : ");
						scanf("%s",linhaB);
						matriz.i2 = atoi(linhaB);
						printf("\t|Digite o numero de colunas [j] : ");
						scanf("%s",colunaB);
						matriz.j2 = atoi(colunaB);

						//confirmar com o usuario o tamanho das matrizes // tratamento de erro do usuario
						printf("\n\t|Dimensao da MATRIZ [A] : %d x %d\n\n",matriz.i1,matriz.j1);
						printf("\t|Dimensao da MATRIZ [B] : %d x %d\n\n",matriz.i2,matriz.j2);
						printf("\tConfirmar ?\n");
						printf("\t\tSIM - - - - - - 1 -\n");
						printf("\t\tNAO - - - - - - 2 -\n");
						printf("\t\t\t\t");
						scanf("%s",askErro);
						ask = atoi(askErro);
						setbuf(stdin,NULL);

							if(ask!=2 && ask!=1 && ask!=3){
								// caso nehuma das opcoes
								printf("\t\tDigite a opcao valida\n");
							}else{
								if(matriz.i1<=0 || matriz.j1<=0 || matriz.i2<=0 || matriz.j2<=0){
									// caso tamanho da matriz invalida
									printf("\n\tTamanho de MATRIZ invalida para operacoes :\n");
									printf("\n\t|Dimensao da MATRIZ [A] : %d x %d\n\n",matriz.i1,matriz.j1);
									printf("\t|Dimensao da MATRIZ [B] : %d x %d\n\n",matriz.i2,matriz.j2);
									ask = 2;
								}else{
									continue;
								}
							}
					}while(ask!=1);

					LerMatrizes(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					ImprimirMatrizes(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 2: // somar matrizes
					printf("\n\t------------ SOMA DE MATRIZES -----------\n\n");
					SomaMatrizes(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 3: // subtracao de matrizes
					printf("\n\t------------ SUBTRACAO MATRIZES -----------\n\n");
					SubtrairMatrizes(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 4: // multiplicar uma matriz por um nuemro qualquer
					printf("\n\t------------ MULTIPLICAR UMA MATRIZ POR UM NUMERO -----------\n\n");
					MultiplicarMatrizReal(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 5: // multiplicar matrizes
					printf("\n\t------------ MULTIPLICACAO DE MATRIZES -----------\n\n");
					MultiplicarMatrizes(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 6: // transposta de uma matriz
					printf("\n\t------------ TRANSPOSTA DE UMA MATRIZ -----------\n\n");
					TranspostaMatriz(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 7: // determinante de uma matriz
					printf("\n\t------------ DETERMINANTE DE UMA MATRIZ -----------\n\n");
					DeterminanteMatriz(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 8: // simetria de matriz
					printf("\n\t------------ SIMETRIA DE UMA MATRIZ -----------\n\n");
					SimetriaMatriz(matriz.i1,matriz.j1,matriz.i2,matriz.j2);
					break;
			case 9: // menu principal
					printf("\n\n====================== MENU PRINCIPAL ==========================\n");
					free(aux.m1);
					free(aux.m2);
					MenuPrincipal();
					break;
			default:// caso invalido
					printf("\n\n---------------------------ERRO 404 -------------------------------\n");
					printf("Codigo invalido !\nPor Favor digite o numero da operacao correspondente:\n\n");
		}
	}while(CodMenuMatriz!=9); // SUB MENU MATRIZ
}

void MenuPrincipal(){
	// variaveis de escolha
	long int CodMenu;
	char escolha[10];
	
	do{
		printf("\nOPERACAO COM VETORES - - - - - - - 1 -\n");
		printf("OPERACAO COM MATRIZES - - - - - -  2 -\n");
		printf("SAIR DA CALCULADORA- - - - - - - - 3 -\n");
		printf("DIGITE O NUMERO DA OPERACAO DESEJADA : ");

		scanf("%s",escolha);
		CodMenu = atoi(escolha);// string em int
		setbuf(stdin,NULL); // limpar buffer
		switch(CodMenu){
			case 1: // ir vetor :
					MenuVetor();
					break;
			case 2: // ir matriz :
					MenuMatriz();
					break;
			case 3: // sair da calc
					printf("\n\n -----------------------------------------------\n");
					printf("|\tCalculadora de Matrizes e Vetores 	|\n");
					printf("|\tTodos os direitos reservados      	|\n");
					printf("|\tEncerrando [. . .]               	|\n");
					printf(" -----------------------------------------------\n\n");
					exit(0);
					break;
			default : // caso invalido
					printf("\n\n-------------------------ERRO 404---------------------------------\n");
					printf("Codigo invalido !\nPor Favor digite o numero da operacao correspondente:\n\n");
		}
	}while(CodMenu!=3);
}
////////////////////////////////////////////////////// main:
int main(){
	// Instrucoes basicas para usuario :
	printf("\n\n| OBS 1 : Programa adaptado para\n| receber SISTEMA NUMERICO de acordo com a lingua padrao \n| do seu sitema operacional\n");
	printf("| OBS 2 : NAO INSIRA NUMEROS FRACIONARIOS - \n| Calc MeV aceita apenas numeros INTEIROS E DECIMAIS ! \n\n");
	// Uso da lingua padrão do sistema operacional :
	setlocale(LC_ALL,"");
	printf("\nCALC MeV Versao 1.1  \n");
	printf("=================================================================\n");
	printf("               - CALCULADORA DE MATRIZ E VETORES -               \n");
	printf("=================================================================\n");

	MenuPrincipal();

	return 0;
}


////////////////////////////////////////////////////// VERSÕES /////////////////////////////////////////////////////////////////////
/*
- VERSOES ALFA TESTES/DESENVOLVIMENTO :
1.0.0 = INICIO/MENUS;
1.1.01 = CORRECAO DE IMPRESSAO E SEGUIMENTOS; 02/11/2017
1.2.01 = USO DE LONG INT NAS OPCOES DE MENU; 08/11/2017
1.3.01 = DESENVOLVIMENTO DO MENU VETOR CASE 1/ CORRECAO DE SEMANTICA; 09/11/2017
1.4.01 = DESENVOLVIMENTO DO MENU MATRIZ CASE 1/CORRECAO DE SEMANTICA; 15/11/2017
2.4.01 = DESENVOLVIMENTO DO MENU VETOR CASE 1/CORRECAO DOS BUGS 1,2 E 4/CORRECAO DO MENU PRINCIPAL; 15/11/2017
2.4.02 = #include "funcoes.h" / CORRECAO DE SEMANTICA E COESAO; 17/11/2017
2.5.02 = PROBLEMAS COM PARAMETROS DE VETORES / APLICACAO DA STRUCT; 17/11/2017
3.5.02 = TODAS AS OPERACOES DE VETORES / RESOLUCAO DE TODOS OS BUGS E ERROS; 18/11/2017
3.6.02 = STRUCT E ALOCAMENTO DINAMICO DE MATRIZES; 20/11/2017
3.6.03 = CORRECAO DO BUG 6 E 7/ CORRECAO DAS BIBLIOTECAS DE FUNCOES; 22/11/2017
3.7.03 = DESENVOLVIMENTO DAS OPERACOES COM MATRIZES CASES: 2, 3, 4 E 5; 23/11/2017
4.7.03 = DESENVOLVIMENTO DAS CASES DE MATRIZES 6,7 E 8; 24/11/2017
- VERSAO PRE BETA :
	1.1 - PBE
	1.2 - VETORES OK/ MATRIZES OK/ DESENVOLVIMENTO USER EXPERIENCE(UX); 25/11/2017
-VERSAO BETA :
	2.3 - TESTES; 26/11/2017
----- VERSAO FINAL :
		1.0 - CORRECAO/ UX ; 28/11/2017
		1.1 - REDUCAO ; 29/11/2017
*/


//////////////////////////////////////////////////////// ERROS/BUGS ////////////////////////////////////////////////////////////////
/*
- 1 BUG : Digitar uma letra nos MENUS, ele entra em loop. CORRIGIDO

- 2 BUG : ao entrar no menuvetor e digitar novamente o vetor, quando sair e ir para o menu principal e escolher para encerrar o programa
,ele nao encerra e executa a funcao, menuvetor CORRIGIDO

- 3 ERRO : Erro ao somar Vetores CORRIGIDO

- 4 ERRO : Nao sai da funcao BackMenu(); caso seja 3 ... CORRIGIDO

- 5 BUG : ALOCAMENTO DE TODOS OS VETORES NA POSICAO 3 incorretos CORRIGIDO

- 6 BUG : FUNCAO LER MATRIZES : CORRIGIDO

- 7 CRASH : AO NAVEGAR E REALIZAR OPERACOES DE IDA E VOLTA ... CORRIGIDO

- NOTA : VETORES E MATRIZES TAMANHO >= 1; <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PBE CORRIGIDO

- 8 BUG : A PRIMEIRA VEZ DA OPRACAO DE MULTIPLICAR MATRIZES , DA ERRO DE ALOCACAO , NAS OUTRAS FUNCIONAM  <<<<<<<<< PBE CORRIGIDO

- 9 PRINTAR VETORES E MATRIZES NAS OPERAÇÕES CORRIGIDO

- 10 INT/FLOAT CORRIGIDO

- 11 ERRO = CALCULO DE SIMETRIA DE MATRIZ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PBE CORRIGIDO

- NOTA : USAR UX <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PBE CORRIGIDO
*/
