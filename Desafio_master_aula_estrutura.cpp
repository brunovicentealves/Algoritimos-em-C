/*
	ESTRUTURA DE DADOS 2017/2
	Autores: Tiago Wolker Leite / Eduardo Moraes de Mello Alves / Bruno Vicente Alves
	Data: 01/10/2017
	�ltima atualiza��o: 01/10/2017
	Desafio de Programa��o Lista Encadeada
*/

// -- BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include<stdbool.h>
#include<time.h>
// -- CONSTANTES
#define MAX 100

// -- ESTRUTURAS
typedef struct {
	int ficha;
	char nome[30];
} Aluno;

typedef struct CirculoAlunos {
	Aluno aluno;
//	struct CirculoAlunos *anterior;
	struct CirculoAlunos *proximo;
} CirculoAlunos;

// -- PROT�TIPOS
int validar(CirculoAlunos ** circuloAlunos,int novaficha);
void entrarNoCirculo(CirculoAlunos **circuloAlunos);
void entrada_nome(Aluno * novoAluno );
void entrar(CirculoAlunos *circuloAlunos);

void imprimir(CirculoAlunos **circuloAlunos); // FUN��O DE TESTE - REMOVER ANTES DA ENTREGA

// -- PROGRAMA PRINCIPAL
main() {
	
	
	int op;
	CirculoAlunos *circuloAlunos = NULL; // Cria e inicializa o c�rculo (lista)
	
	// ENTRADA
	do {
		
		printf("\t===== [ PREPARAR A ATIVIDADE ] =====\n");
		printf("\n[ 1 ] - Entrar no circulo");
		printf("\n[ 2 ] - Iniciar atividade");
		printf("\n[ 3 ] - Imprimir dados (FUNCAO DE TESTE - REMOVER ANTES DA ENTREGA)"); // REMOVER ANTES DA ENTREGA
		printf("\n\nInforme sua opcao: ");
		scanf("%i", &op);
		system("cls");
		
		switch (op) {
			
			case 1: // ENTRAR NO C�RCULO
				entrarNoCirculo(&circuloAlunos);
				break;
			
			case 2: // INICIAR
				
				break;
				
			case 3:							// REMOVER ANTES DA ENTREGA
				imprimir(&circuloAlunos);	// REMOVER ANTES DA ENTREGA
				break; 						// REMOVER ANTES DA ENTREGA
			
			default: // OP��O INV�LIDA
				printf("Opcao invalida!\n");
				break;
			
		}
		
		system("pause");
		system("cls");
		
	} while (op != 2);
	
	// SA�DA
	
	// A fazer...
	
}

// -- FUN��ES

/*
	Fun��o para incluir um aluno no final do c�rculo (lista).
	
	@parametro **circuloAlunos ==> Posi��o do primeiro nodo do c�rculo.
*/
void entrarNoCirculo(CirculoAlunos **circuloAlunos) {
	
	CirculoAlunos *novoAlunoCirculo = (CirculoAlunos*) malloc (sizeof (CirculoAlunos));
	
	if (novoAlunoCirculo != NULL) {
		
		entrar(novoAlunoCirculo); // Fun��o para realizar a entrada dos dados
		novoAlunoCirculo->proximo = *circuloAlunos; // Define o proximo para o primeiro do c�rculo

		if (*circuloAlunos == NULL) { // Verifica se o c�rculo(lista) est� vazio.
			// Caso esteja vazio, define como o primeiro do c�rculo(lista) e faz com que o pr�ximo aponte para ele mesmo
			*circuloAlunos = novoAlunoCirculo;
			(*circuloAlunos)->proximo = *circuloAlunos;
		} else {
			CirculoAlunos *aux;
			aux = *circuloAlunos;
			
			// Percorre a lista encadeada para encontrar o �ltimo registro da lista
			while (aux->proximo != *circuloAlunos) {
				// Enquanto n�o encontrar o �ltimo registro, define o ponteiro auxiliar para o ponteiro que est� na posi��o atual da lista
				aux = aux->proximo;
			}
			
			aux->proximo = novoAlunoCirculo;
			
			printf("\nEntrou no circulo!\n");
			
		}
		
	} else {
		printf("Nao ha memoria suficiente para realizar a operacao!\n");
	}
	
}


/*
	Fun��o para inserir os dados do aluno que est� entrando no c�rulo.
	
	@parametro *novoAlunoCirculo ==> Nodo a ser inserido ao c�rculo.
*/
void entrar(CirculoAlunos *novoAlunoCirculo) {
	Aluno novoAluno; // Aluno que a entrar no c�rculo
	entrada_nome( &novoAluno );
	    int ff;
		int novaficha;
	 	 
	 	 
	 	srand(time(NULL));
	 	printf("Ficha : %d \n", novaficha =rand() % MAX +1);
	 	
	 
	 	
	 	
	 	
 	novoAluno.ficha=novaficha;
	
	
	novoAlunoCirculo->aluno = novoAluno;
}


int validar(CirculoAlunos ** circuloAlunos,int novaficha){
	CirculoAlunos *aux=*circuloAlunos;
	
	while(aux!=*circuloAlunos){
		if(novaficha==aux->aluno.ficha){
			
		return 1;	
			
			
		}
	}
		
}


/*
	FUN��O DE TESTE - REMOVER ANTES DA ENTREGA
	Imprime os alunos que est�o no c�rculo.
	
	@parametro **circuloAlunos ==> Posi��o do primeiro nodo do c�rculo.
*/
void imprimir(CirculoAlunos **circuloAlunos) {
	
	if (*circuloAlunos == NULL) {
		printf("\nNao ha registros\n");
	} else {
		
		CirculoAlunos *aux = *circuloAlunos;
		
		printf("\n\t====== [ IMPRIMIR (FUNCAO DE TESTE - REMOVER ANTES DA ENTREGA) ] ======\n");
		printf("\n------------------------------");
		
		do {
			
			printf("\nNome: %s", aux->aluno.nome);
			printf("\nFicha: %i", aux->aluno.ficha);
			printf("\nNome do proximo: %s", aux->proximo->aluno.nome);
			printf("\nFicha do proximo: %i", aux->proximo->aluno.ficha);
			printf("\n------------------------------\n");
			
			aux = aux->proximo;
		} while (aux != *circuloAlunos);
		
	}
	
}

void entrada_nome(Aluno * novoAluno ){
	int cont;//contabliza o quanto de caracteres espediais ele encontrou e numeros
	int tamanho;//guarda o tamanho do meu vetor.
	printf("\t=====  [ DADOS DO ALUNO ] =====\n");
	// NOME
	do{
	
	printf("\nInforme o nome do aluno que esta entrando: ");
	fflush(stdin);
	scanf("%s",&novoAluno->nome);//cata o que o usuario digitou .
	cont=0;
    tamanho=strlen(novoAluno->nome);// conta meu tamamho da minha string.
    
    	if(tamanho<=30){//verfica se  tamanho da minha string maior que 30 .
				for(int i=0;i<tamanho;i++){//percorre a cada posi��o da minha string
				if(isalpha(novoAluno->nome[i])==false){//verfica se � letra do alfabeto.
				cont++;//se n�o for  contabiliza
				
				}
			}
			system("cls");//limpar tela
		 if (cont>0)printf("\n voce Digitou caracteres especiai ou numero !!");	//measagem de erro para dizer que eontrou caracteres especiais e numero na string.
	   }else{
		system("cls");
		printf("\n Voc� Excedeu o Espa�o !!");//printa a mensagem quando excede o tamanho da string.
	  }
	}while(tamanho>=30 || cont>0 );//se a senten�a for verdadeira repete tudo de novo .
}




 
