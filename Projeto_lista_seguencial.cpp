#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define TAM 100

typedef struct {
	int codigo;
	char aluno[TAM];
	int idade ;
	float nota;
		
}Aluno;


typedef struct{
 Aluno turma[TAM];
 int indice;
	
}Lista_aluno;


int menu (Lista_aluno * infos);
void cadastrar (Lista_aluno * infos);
void nota (Lista_aluno * infos);
void listar (Lista_aluno * infos);
void excluir (Lista_aluno * infos);
bool validar_cheio (Lista_aluno infos);
bool validar_vazio (Lista_aluno infos);
int procurar (Lista_aluno *infos);
main(){
	setlocale(LC_ALL,"portuguese");
	
	Lista_aluno infos;
	infos.indice=0;
	int ret_menu;
	do{
	ret_menu=menu(& infos);
		switch(ret_menu){
	case 1 : 
     cadastrar (&infos);
		break;
	case 2 :
	 nota (&infos); 
		break;
	case 3 : 
	 listar (&infos);
		break;
	case 4 : 
	excluir (&infos);
		break;
	case 0 : printf("\n você saira do sistema!!");
		break;
	default:printf("\n opção invalida!!!");		
	}
	}while(ret_menu!=0);
	
	
}

int menu (Lista_aluno * infos){
	int menu;
	printf("\n ======== Menu =========");
	printf("\n1- cadastrar Aluno ");
	printf("\n2- lançar nota ");
	printf("\n3- Listar todos os alunos ");
	printf("\n4- Excluir alunos ");
	printf("\n0- Sair ");
	printf("\n====>");
	scanf("%i",&menu);
	
	return menu;
	
}

void cadastrar (Lista_aluno * infos){
	Aluno ficha;
	system("cls");
	if(validar_cheio(*infos)){
		printf("\n não é possivel cadastrar mais alunos.");
	}else{
			printf("\n Digite o nome do aluno:");
			fflush(stdin);
			gets(ficha.aluno);
			system("cls");
				do{
					printf("\n Digite a idade do aluno: ");	
					scanf("\n %i",&ficha.idade );
						if(ficha.idade<1){
							system("cls");
							printf("numero invalido.");
						}
				}while(ficha.idade<1);
				ficha.codigo=infos->indice+1;
				infos->turma[infos->indice]=ficha;
				infos->indice++;	
	}
	system("cls");	
	printf("\nCadastrado com sucesso !");
}
void nota (Lista_aluno * infos){
	int posicao_for=0;
	int ver_codigo;
	float nota1=0;
	 do{
		 	printf("\n Digite o Ra do Aluno: ");
			scanf("\n%i",&ver_codigo);
		if(ver_codigo<1){
			system("cls");
			printf("\n opção invalida!");
		}
	 }while(ver_codigo<1);
	
	for(int x=0;x<infos->indice; x++){
	if(infos->turma[x].codigo==ver_codigo )	{
		posicao_for=x;

	 }else{
	 	posicao_for--;
	 	
	 }
	} 
	do{
		  	printf("\n Digite a nota do aluno: ");
		  	fflush(stdin);
			scanf("%f",&nota1);
		nota1=1;
		if(nota1<1){
			system("cls");
			printf("\n opção invalida!");
		}
       }while(nota1<1);
       if(posicao_for==-1){
       	system("cls");
	        printf("\n não existe Ra associado a esse aluno .");
	   }else{
	   	printf("\nCadastrado com sucesso !");
	    	printf("\n%i",&nota1);
	   	
	   }

}
void listar (Lista_aluno * infos){
		if(validar_vazio(*infos)){
		system("cls");
		printf("\n Aluno não cadastrado ainda para lançar nota!");
	}else{system("cls");
	for( int x=0; x<infos->indice;x++){
		printf("\n===============================");
		printf("\n Codigo :%i",infos->turma[x].codigo);
		printf("\n Nome   :%s",infos->turma[x].aluno);
		printf("\n Idade  :%i",infos->turma[x].idade);
		if(infos->turma[x].nota>0){
		printf("\n nota   :%.2f",infos->turma[x].nota);
		}
		printf("\n================================");
	}	
  }	
}
void excluir (Lista_aluno * infos){
	system("cls");
	if(validar_vazio(*infos)){
		system("cls");
		printf("\nopcao invalida!!");
		
	}else{
		
	int ver;
	 int posicao;
	do{
		 	printf("\n Digite o Ra do Aluno: ");
			scanf("\n%i",&ver);
		if(ver<1){
			system("cls");
			printf("\n opção invalida!");
		}
	 }while(ver<1);
	 	
	for(int x=0;x<infos->indice; x++){
		
		if(infos->turma[infos->indice].codigo==ver){
			posicao=x;
			break;
	}
   }
   for(int x=0;x<infos->indice; x++){
   	if(posicao==x){
   		strcpy(infos->turma[posicao].aluno,infos->turma[posicao+1].aluno);
   		infos->turma[posicao].codigo=infos->turma[posicao+1].codigo;
   		infos->turma[posicao].idade=infos->turma[posicao+1].idade;
   		infos->turma[posicao].nota=infos->turma[posicao+1].nota;
   		
   		
	 }
	 if(x==infos->indice){
	 	strcpy(infos->turma[posicao].aluno,infos->turma[posicao+1].aluno);
   		infos->turma[posicao].codigo=infos->turma[posicao+1].codigo;
   		infos->turma[posicao].idade=infos->turma[posicao+1].idade;
   		infos->turma[posicao].nota=infos->turma[posicao+1].nota;
   	
	 }
   }
   infos->indice--;						
  }
}

bool validar_cheio (Lista_aluno infos){
	if(infos.indice==TAM){
		return true;
	}
	return false;	
}

bool validar_vazio (Lista_aluno infos){
	if(infos.indice<=0){
		return true;
	}
	return false;	
}


