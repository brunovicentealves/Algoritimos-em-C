#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


typedef struct ELEMENTO{ // Elemento unico que estara na lista
	int codigo;
	char nome[100];
	int valor;
	
	ELEMENTO *proximoElemento;
}ELEMENTO;

typedef struct GLOBAL{ // Estrutura para levar como parametro para todas as funcoes
	ELEMENTO *primeiroElemento; // Ponteiro para apontar para o primeiro elemento da lista
} GLOBAL;

// Prototipos
void menuPrincipal(GLOBAL *dados);

void lista_inserirInicio(GLOBAL *dados);
void lista_inserirFim(GLOBAL *dados);

void lista_mostrar(GLOBAL dados);

void lista_inverter(GLOBAL *dados);

int main (void){
	
	setlocale(LC_ALL, "");
	
	// Instanciando estrutura para guardar o inicio da lista
	GLOBAL dados;
	dados.primeiroElemento = NULL; // Inicializando a lista vazia
		
	menuPrincipal(&dados);
	
	return 0;
}

void menuPrincipal(GLOBAL *dados){
	char escolhaMenuPrincipal;
	system("cls");
	
	printf (" == MENU PRINCIPAL == \n");
	printf (" 1 - Inserir no Início \n");
	printf (" 2 - Inserir no Fim \n");
	printf (" 3 - Exibir \n");
	printf (" 4 - Inverter \n");
	printf (" S - Limpar lista e Sair \n");
	printf (" Escolha: ");
	
	fflush(stdin);
	scanf("%c", &escolhaMenuPrincipal);
	
	switch(escolhaMenuPrincipal){
		case '1':
			printf(" == Inserir no Início == \n");
			lista_inserirInicio(dados);
			break;
		case '2':
			printf(" == Inserir no Fim == \n");
			lista_inserirFim(dados);
			break;
		case '3':
			printf(" == Exibir Lista == \n");
			lista_mostrar(*dados);
			system("pause");
			break;
		case '4':
			printf(" == Inverter Lista == \n");
			lista_inverter(dados);
			system("pause");
			break;
		case 's':
			printf (" [ SAINDO DO SISTEMA ] \n");
//			lista_limpar(dados);
			exit(0);
			break;
		default:
			printf(" [ ESCOLHA INVÁLIDA ] \n");
			break;
	}
	
	return menuPrincipal(dados);
}

void lista_inserirInicio(GLOBAL *dados){

	// Precisa
		// Lista - OK
		// Novo Elemento - Ok
	
	// Alocar memoria para o novo elemento
	ELEMENTO *novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
	
	if(novoElemento == NULL){
		printf (" Não há memória! \n");
		return;
	}

	// Preencher os atributos do elemento
	novoElemento->proximoElemento = NULL;
	printf (" Informe o nome do Elemento: ");
	fflush(stdin);
	gets(novoElemento->nome);
	printf (" Informe o valor do Elemento: ");
	scanf("%d", &novoElemento->valor);

	// Atrelando na lista no inicio
	novoElemento->proximoElemento = dados->primeiroElemento;
	dados->primeiroElemento = novoElemento;
}

void lista_inserirFim(GLOBAL *dados){
	
	// Precisa
		// Lista - OK
		// Novo Elemento - Ok
	
	// Alocar memoria para o novo elemento
	ELEMENTO *novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
	
	if(novoElemento == NULL){
		printf (" Não há memória! \n");
		return;
	}
	
	// Preencher os atributos do elemento
	novoElemento->proximoElemento = NULL;
	printf (" Informe o nome do Elemento: ");
	fflush(stdin);
	gets(novoElemento->nome);
	printf (" Informe o valor do Elemento: ");
	scanf("%d", &novoElemento->valor);
	
	// Atrelando na lista no fim
	if(dados->primeiroElemento == NULL){
		dados->primeiroElemento = novoElemento;
	}
	else{
		ELEMENTO *elementoAtual = dados->primeiroElemento;
		while(elementoAtual->proximoElemento != NULL){
			elementoAtual = elementoAtual->proximoElemento;
		}
		elementoAtual->proximoElemento = novoElemento;
	}
	
	system("pause");
}

void lista_mostrar(GLOBAL dados){
	// Verificar se lista e vazia
	if (dados.primeiroElemento == NULL){
		printf (" Lista vazia! \n");
		return;
	}
	
	// Anda na lista mostrando cada elemento
	ELEMENTO *elementoAtual = dados.primeiroElemento;
	
	while(elementoAtual != NULL){
		printf("\n Nome: %s \n", elementoAtual->nome);
		printf(" Valor: %d \n", elementoAtual->valor);
		
		elementoAtual = elementoAtual->proximoElemento;
	}
}

void lista_inverter (GLOBAL *dados){
	
	
	if(!dados->primeiroElemento){
		printf (" Nada para inverter! ");
		return;
	}
	
	// Começar o andar do loop com o segundo elemento da lista
	ELEMENTO *elementoAtual = dados->primeiroElemento;
	
	ELEMENTO *primeiroSegundaLista = NULL;
	
	while (elementoAtual != NULL){
		// Inserir elemento atual no inicio da segunda lista
		// Alocar memoria para o novo elemento
		ELEMENTO *novoElemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
		
		if(novoElemento == NULL){
			printf (" Não há memória! \n");
			return;
		}
	
		// Preencher os atributos do elemento
		novoElemento->proximoElemento = NULL;
		strcpy(novoElemento->nome, elementoAtual->nome);
		novoElemento->valor = elementoAtual->valor;
	
		// Atrelando na lista no inicio
		novoElemento->proximoElemento = primeiroSegundaLista;
		primeiroSegundaLista = novoElemento;
	
		elementoAtual = elementoAtual->proximoElemento;	
	}
	
	
	printf(" Mostrando lista normal \n");
	lista_mostrar(*dados);
	
	printf (" Mostrando a lsita invertida: \n");
	ELEMENTO *andarNaInvertida = primeiroSegundaLista;
	while (andarNaInvertida != NULL){
			printf(" == \n");
			printf("%s \n", andarNaInvertida->nome);
			printf("%d \n", andarNaInvertida->valor);
			andarNaInvertida = andarNaInvertida->proximoElemento;
			printf(" == \n");
	}
	
	// Acima esta printando a lista invertida porem nao esta passando para a original
	// devem apenas aponstar o PRIMEIRO ELEMENTO (dados->primeiroElemento)
	// para o primeiro elemento da segunda lista (primeiroSegundaLista)
	
	// lista_limpar(dados);
	
	// dados->primeiroElemento = primeiroSegundaLista;
	
	
}


