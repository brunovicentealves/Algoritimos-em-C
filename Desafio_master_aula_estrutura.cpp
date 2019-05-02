/*
	ESTRUTURA DE DADOS 2017/2
	Autores: Tiago Wolker Leite / Eduardo Moraes de Mello Alves / Bruno Vicente Alves
	Data: 01/10/2017
	Última atualização: 01/10/2017
	Desafio de Programação Lista Encadeada
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

// -- PROTÓTIPOS
int validar(CirculoAlunos ** circuloAlunos,int novaficha);
void entrarNoCirculo(CirculoAlunos **circuloAlunos);
void entrada_nome(Aluno * novoAluno );
void entrar(CirculoAlunos *circuloAlunos);

void imprimir(CirculoAlunos **circuloAlunos); // FUNÇÃO DE TESTE - REMOVER ANTES DA ENTREGA

// -- PROGRAMA PRINCIPAL
main() {
	
	
	int op;
	CirculoAlunos *circuloAlunos = NULL; // Cria e inicializa o círculo (lista)
	
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
			
			case 1: // ENTRAR NO CÍRCULO
				entrarNoCirculo(&circuloAlunos);
				break;
			
			case 2: // INICIAR
				
				break;
				
			case 3:							// REMOVER ANTES DA ENTREGA
				imprimir(&circuloAlunos);	// REMOVER ANTES DA ENTREGA
				break; 						// REMOVER ANTES DA ENTREGA
			
			default: // OPÇÃO INVÁLIDA
				printf("Opcao invalida!\n");
				break;
			
		}
		
		system("pause");
		system("cls");
		
	} while (op != 2);
	
	// SAÍDA
	
	// A fazer...
	
}

// -- FUNÇÕES

/*
	Função para incluir um aluno no final do círculo (lista).
	
	@parametro **circuloAlunos ==> Posição do primeiro nodo do círculo.
*/
void entrarNoCirculo(CirculoAlunos **circuloAlunos) {
	
	CirculoAlunos *novoAlunoCirculo = (CirculoAlunos*) malloc (sizeof (CirculoAlunos));
	
	if (novoAlunoCirculo != NULL) {
		
		entrar(novoAlunoCirculo); // Função para realizar a entrada dos dados
		novoAlunoCirculo->proximo = *circuloAlunos; // Define o proximo para o primeiro do círculo

		if (*circuloAlunos == NULL) { // Verifica se o círculo(lista) está vazio.
			// Caso esteja vazio, define como o primeiro do círculo(lista) e faz com que o próximo aponte para ele mesmo
			*circuloAlunos = novoAlunoCirculo;
			(*circuloAlunos)->proximo = *circuloAlunos;
		} else {
			CirculoAlunos *aux;
			aux = *circuloAlunos;
			
			// Percorre a lista encadeada para encontrar o último registro da lista
			while (aux->proximo != *circuloAlunos) {
				// Enquanto não encontrar o último registro, define o ponteiro auxiliar para o ponteiro que está na posição atual da lista
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
	Função para inserir os dados do aluno que está entrando no círulo.
	
	@parametro *novoAlunoCirculo ==> Nodo a ser inserido ao círculo.
*/
void entrar(CirculoAlunos *novoAlunoCirculo) {
	Aluno novoAluno; // Aluno que a entrar no círculo
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
	FUNÇÃO DE TESTE - REMOVER ANTES DA ENTREGA
	Imprime os alunos que estão no círculo.
	
	@parametro **circuloAlunos ==> Posição do primeiro nodo do círculo.
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
				for(int i=0;i<tamanho;i++){//percorre a cada posição da minha string
				if(isalpha(novoAluno->nome[i])==false){//verfica se é letra do alfabeto.
				cont++;//se não for  contabiliza
				
				}
			}
			system("cls");//limpar tela
		 if (cont>0)printf("\n voce Digitou caracteres especiai ou numero !!");	//measagem de erro para dizer que eontrou caracteres especiais e numero na string.
	   }else{
		system("cls");
		printf("\n Você Excedeu o Espaço !!");//printa a mensagem quando excede o tamanho da string.
	  }
	}while(tamanho>=30 || cont>0 );//se a sentença for verdadeira repete tudo de novo .
}




 
