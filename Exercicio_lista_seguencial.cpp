#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>


#define TAM 10

typedef struct{
	char aluno[TAM];
	int idade;
	int  ano_nasc ;
}Aluno;

typedef struct{
	Aluno alunos[TAM];
	int posicao;
}Turma;

void menu(Turma *ficha);
int  cadastrar(Turma *ficha);

main(){
	setlocale(LC_ALL,"portuguese");
	 Turma ficha;
	   menu(&ficha);
}

void menu(Turma *ficha){
	int menu;
	
	do{	
		printf("\n ======== Menu =========");
			printf("\n1- cadastrar Aluno ");
				printf("\n2- Listar todos os alunos ");
					printf("\n3- Excluir alunos ");
						printf("\n0- Sair ");
							printf("\n====>");
								scanf("%i",&menu);
											switch(menu){
												case 1 :
												cadastrar(ficha);
													break;
												case 2 :
													break;
												case 3 :
													break;
												case 0 :printf("\n vc ira sair do sistema.");
													break;	
											}
	}while(menu!=0);	
}
int cadastrar(Turma *ficha){
	Aluno ficha2;
	system("cls");
		printf("\n====== cadastrar aluno ==========");
			printf("\nDigite o seu nome :");
				printf("\n====>");
					fflush(stdin);
						gets(ficha2.aluno);
							system("cls");
	do{
		
		printf("\n Digite a idade do aluno:");
			printf("\n====>");
				scanf("%i",&ficha2.idade);
					system("cls");
						if(ficha2.idade<1){
						printf("\n tente novamente/idade invalida!!");
						}
	}while(ficha2.idade<1);
		do{
			
			printf("\n Digite a ano de nascimento do colaborador.");
				printf("\n===>");
					scanf("%i",&ficha2.ano_nasc);
						system("cls");
							if(ficha2.ano_nasc<0)printf("valor invalido!!!");
		}while(ficha2.ano_nasc<0);
		system("cls");
		ficha->alunos[ficha->posicao]=ficha2;
		ficha->posicao++;
		printf("\n Cadastrado com sucesso !!");
		
}
	







