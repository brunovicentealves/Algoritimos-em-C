/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  xx   Criado por : Bruno vicente Alves                        xx
  xx   Data:02-09-17                                           xx
  xx   Objetivo : Aplicação para manipular lista de alunos.    xx
  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/





//bibliotecas
#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//defines
#define N_nome 100
#define VETOR 150




//structs
//struct com dados do aluno 
typedef struct{
	int codigo;
	char nome [N_nome];
	int idade;
	 float nota;
	char status;	
}Aluno;
//struct com conjunto de dados do aluno e cotrolador do vetor.
typedef struct{
	Aluno  turma[VETOR];
	int controlador;
}Sala;

//prototipos 

int menu( Sala *infos);
bool vetor_cheio(Sala *infos);
bool vetor_vazio (Sala *infos);
void cadastrar (Sala *infos);
void fichario(Aluno *ficha);
void listar (Sala *infos);
 void ordenar (Sala *infos);
void incluir_ordenado (Sala *infos);
int busca_binaria (Sala *infos);
void incluir_antes (Sala *infos);
void excluir_aluno(Sala *infos);


//função principal 
main(){
	setlocale(LC_ALL,"portuguese");
	Sala infos;
	infos.controlador=0;
	int menu_posicao;
	//chama a função menu e retorna um valor que é guarada numa variavel local (menu_posicao).
	
	do{
		menu_posicao=menu(&infos);
		switch(menu_posicao){
			case 1:
				cadastrar (&infos);
				break;
			case 2:
				incluir_antes (&infos);
				break;
			case 3:
				incluir_ordenado (&infos);
				break;
			case 4:
				 listar (&infos);
				break;
			case 5:
				busca_binaria (&infos);
				break;
			case 6:
				excluir_aluno(&infos);
				break;
			case 0: printf("\n voce saira do sistema");
				break;
			default:printf("\nopçã invalida!");
			
			
			
		}
		
	}while(menu_posicao!=0);
}


int menu( Sala *infos){
	int seleciona;
	printf("\n+_+_+_+_+_+_+_+_+_+_+[ MENU ]+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+");
	printf("\n(                1-Cadastrar Aluno.                         )");
	printf("\n(                2-incluir antes.                           )");
    printf("\n(                3-incluir ordenado.                        )");
	printf("\n(                4-Listar Todos.                            )");
	printf("\n(                5-Busca Binaria.                           )");
	printf("\n(                6-excluir Aluno.                           )");
	printf("\n(                0-sair do programa.                        )");
	printf("\n+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+__");
	//valida se é correta a opção se não for retorna para digitar a opção certa.
	do{
		printf("\n=========>");
		scanf("%i",&seleciona);
		//valida se é uma da opções que o usuario digitou .
		if(seleciona>6 || seleciona<0)printf("\nOpcção invalida!");
		
	}while(seleciona>6 || seleciona<0);
	
	return  seleciona;
}



//para cadastrar e acrescentar mais espaço no vetor
void cadastrar (Sala *infos){
	if(infos->controlador==VETOR){
		system("cls");
		printf("\n Já possuem numero maximo de cadastros no Programa");
		
	  }else{
		system("\n");
		Aluno ficha;
		fichario(&ficha);
		infos->turma[infos->controlador]=ficha;
		infos->controlador++;	
	}	
}

//para cadastar a ficha do aluno
void fichario(Aluno *ficha){
	do{
		system("cls");
		printf("\nDigite o Codigo do RA do aluno  :");
		scanf("%i",&ficha->codigo);
		if(ficha->codigo<0){
			system("cls");
			printf("\numero invalido!!");			
		}
	}while(ficha->codigo<0);
	system("cls");
	printf("\n Digite o nome do ALuno :");
	fflush(stdin);
	gets(ficha->nome);
	do{
		system("cls");
		printf("\n Digite a idade do Aluno :");
		scanf("%i",&ficha->idade);	
			if(ficha->idade<=0){
				system("cls");
				printf("\nopção ivalida");
			}
	}while(ficha->idade<=0);
	do{
		system("cls");
		printf("\n Digite a nota do Aluno :");
		scanf("%f",&ficha->nota);
			if(ficha->nota<0){
				system("cls");
				printf("\nopção invalida");	
			}
	}while(ficha->nota<0);
	if(ficha->nota>7){
		ficha->status='A';
	  }else{
		ficha->status='R';	
	}	
}
//lista todos alunos 
void listar (Sala *infos){
	if(infos->controlador<0){
		
		printf("\n não possue aluno cadastrado no sistema");
	 }else{
	 	system("cls");
		for(int x=0;x<infos->controlador;x++){
			system("cls");
			printf("\n========================================") ;
			printf("\n"); 
		    printf("\n     	NOME: %s",infos->turma[x].nome);
	        printf("\n     	IDADE : %i",infos->turma[x].idade);
			printf("\n 		NOTA : %.2f",infos->turma[x].nota);
			printf("\n		STATUS : %c",infos->turma[x].status);	
	        printf("\n");
			printf("\n========================================") ; 
        }		
			
   }	
}		

// inclui ordenado no vetor 
void incluir_ordenado (Sala *infos){
	Aluno ficha;
    fichario(&ficha);
    
    int i= infos->controlador-1;                
             while( i >=0 && ficha.idade< infos->turma[i].idade ){
                   infos->turma[i+1]=infos->turma[i];
                    i--; 
             }       
             infos->turma[i+1]=ficha; 
             infos->controlador++;  
}


//ordena o vetor 
 void ordenar (Sala *infos){
 	Aluno guarda;

 	for (int x=0;x<infos->controlador;x++){
 		for(int y=x+1;y<infos->controlador;y++){
 			if(infos->turma[y].codigo <infos->turma[x].codigo){
 				guarda=infos->turma[x];
 				infos->turma[x]=infos->turma[y];
 				infos->turma[y]=guarda;
 					
			 }	
		 }		
	 }	
 }	
	
	
int busca_binaria (Sala *infos){
	ordenar (infos);
	if(infos->controlador==0){
		system("cls");
		printf("\nLista vazia!!");	
	}else{
	int codigo,inicio=0 ,meio,fim=infos->controlador-1;	
	system("cls");
	do{
		printf("\nDigite o numero Ra da pessoa que vocÊ procura  :");
		scanf("%i",&codigo);
		if(codigo<0){
			printf("\nopção invalida!!");
		}
	}while(codigo<0);
	do{
		
	meio=(int)(inicio+fim)/2.;
		if(codigo<infos->turma[meio].codigo){
			fim=-1;
		}else{
			fim=+1;
			
		}		
	}while(inicio<=fim && infos->turma[meio].codigo!=codigo);
	if(infos->turma[meio].codigo==codigo){
		system("cls");
		printf("\n========================================");
		printf("\n");
		printf("\n      NOME: %s",infos->turma[meio].nome);
	    printf("\n      IDADE : %i",infos->turma[meio].idade);
		printf("\n      NOTA : %.2f",infos->turma[meio].nota);
		printf("\n      STATUS : %c",infos->turma[meio].status);	
	   	printf("\n");
		printf("\n========================================") ;    
		
	}else{
		system("cls");
		printf("\nRegistro não encontrado!!");
	}
		return meio; 
  }		
	 	
}
	
void excluir_aluno(Sala *infos){
	int posicao;
	char escolha;
	if(infos->controlador==0){
		system("cls");
		printf("\nLista vazia!!");
	}else{
	  posicao=busca_binaria (infos);	
		  do{
		  	printf("\n você tem certeza que quer Exluir e ALuno? (S ou N)");
			fflush(stdin);
			scanf("%c",&escolha);
			system("cls");
		  }while(toupper(escolha)!='S'&& toupper(escolha) !='N');
		  if(escolha=='S'){
				  	for(int x=posicao;x<infos->controlador-1;x++){
				  		infos->turma[x]=infos->turma[x+1];	
					  }
				  infos->controlador--;
				  system("cls");
				  printf("\nExcluido com sucesso!!");
		  }else{
			  system("cls");	
			  printf("\nEscolha outra opção no menu!");  	
		  }
	 }	
}


void incluir_antes (Sala *infos){
	int posicao;
	Aluno ficha; 
	if(infos->controlador==VETOR){
		system("cls");
		printf("\nlista vazia!!");
	 }else{
	 	
	 	posicao= busca_binaria (infos);
	 	
		fichario(&ficha);
		
		for(int x=infos->controlador-1;x>=posicao;x--){
		infos->turma[x+1]=infos->turma[x];		
		}
		infos->turma[posicao]=ficha;
		infos->controlador++;
		system("cls");
		printf("Aluno inserido com sucesso antes da referencia .");
	}	
}
