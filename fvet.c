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

void LerVetores(float *v1,float *v2 ,int n1, int n2){
	int c;  // c = variável contadora

	// ler vetores 1 e 2 :
	printf("\n\t------------ VETOR [1] -----------\n");
	for(c=0;c<n1;c++){
		printf("\tDigite o %d° termo : ",c+1);
		scanf("%f",&v1[c]);
	}
	printf("\n\t------------ VETOR [2] ------------\n");
	for(c=0;c<n2;c++){
		printf("\tDigite o %d° termo : ",c+1);
		scanf("%f",&v2[c]);
	}
 	putchar('\n');
}

void ImprimirVetores(float *v1, float *v2, int n1, int n2){
	int c; // variavel contadora

	// vetor 1
	printf("\t VETOR [1] = ");
	printf("(");
	for(c=0;c<n1;c++){
		printf(" %.1f;",v1[c]);
	}
	printf(")");

	//vetor 2
	printf("\n\t VETOR [2] = ");
	printf("(");
	for(c=0;c<n2;c++){
		printf(" %.1f;",v2[c]);
	}
	printf(")\n\n");
}

void SomaVetores(float *v1, float *v2, int n1, int n2){
	int c; // c = variavel contadora
	float *vS; // vetor resultante da soma

	if(n1!=n2){
		printf("\n\tTamanho do VETOR [1] = %d eh diferente do tamanho do VETOR [2] = %d\n\n",n1,n2);
	}else{
		//realiza a soma e o alocamento dinamico:
		vS = (float *) malloc(n1 *sizeof(float));
			for(c=0;c<n1;c++){
				vS[c]=v1[c]+v2[c];
			}

		ImprimirVetores(v1,v2,n1,n2);
		//imprimi o resultado
		printf("\t VETOR [1] + VETOR [2] = ");
		putchar('(');
		for(c=0;c<n1;c++){
			printf(" %.2f;",vS[c]);
		}
		printf(")\n\n");
		free (vS);
	}
}

void SubtracaoVetores(float *v1, float *v2 ,int n1, int n2){
	// variavel contadora :
	int c; 
	// Ordem da operacao :
	int OrdemOp;
	char OrdemOpS[10];
	// vetor resultante da subtracao :
	float *vSUB;

	// condicao de existencia da subtracao :
	if(n1!=n2){
		printf("\n\tTamanho do VETOR [1] = %d eh diferente do tamanho do VETOR [2] = %d\n\n",n1,n2);
	}else{
		vSUB = (float *) malloc (n1 *sizeof(float));
		ImprimirVetores(v1,v2,n1,n2);
	
		do{	// escolha da ordem :
			printf("\n\t( VETOR [1] - VETOR [2] )- - - - - - - - 1 - \n");
			printf("\t( VETOR [2] - VETOR [1] )- - - - - - - - 2 - \n");
			printf("\tInforme a ordem da subtracao de vetores : ");
			scanf("%s",OrdemOpS);
			OrdemOp = atoi (OrdemOpS);
			setbuf(stdin,NULL);

			if(OrdemOp == 1){
				// vetor [1] - vetor [2] :
				for(c=0;c<n1;c++){
					vSUB[c] = v1[c] - v2[c];
				}
			}else{
				if(OrdemOp == 2){
					// vetor[2] - vetor[1] :
					for(c=0;c<n1;c++){
						vSUB[c] = v2[c] - v1[c];
					}
				}else{
					printf("\n\tOpcao invalida !! informe o codigo correspondente a operacao\n");
				}
			}
		}while(OrdemOp!=1 && OrdemOp!=2 ); // LOOP de erro

		// imprimi vetor resultante :
		printf("\n\tVETOR resultante = (");
		for(c=0;c<n1;c++){
			printf(" %.f;",vSUB[c]);
		}
		printf(")\n\n");
		free (vSUB);
	}
}

void MultiplicarVetoresEsc(float *v1, float *v2, int n1, int n2){
	int c; //variavel contadora
	float escalar; // variavel da multiplicacao escalar
	float aux = 0;

	if(n1!=n2){
		printf("\n\tTamanho do VETOR [1] = %d eh diferente do tamanho do VETOR [2] = %d\n\n",n1,n2);
	}else{
		// operacao :
		for(c=0;c<n1;c++){
			aux = v1[c] * v2[c];
			escalar += aux;
		}
		
		ImprimirVetores(v1,v2,n1,n2);
		printf("\n\t Multiplicacao Escalar : VETOR [1] x  VETOR [2] = %.2f\n\n",escalar);
	}
}

void MultiplicarVetores(float *v1, float *v2, int n1, int n2){
	int c; // variavel contadora
	float *vM; // vetor resultante

	if(n1!=n2){
		printf("\n\tTamanho do VETOR [1] = %d eh diferente do tamanho do VETOR [2] = %d\n\n",n1,n2);
	}else{
		ImprimirVetores(v1,v2,n1,n2);
		// operacao :
		vM = (float *) malloc(n1 *sizeof(float));
			for(c=0;c<n1;c++){
				vM[c] = v1[c] * v2[c];
			}
			// imprimi vetor resultante
			printf("\n\t VETOR [1] x  VETOR [2] = (");
			for(c=0;c<n1;c++){
				printf(" %.2f;",vM[c]);
			}
			printf(")\n\n");
		free (vM);
	}	
}

