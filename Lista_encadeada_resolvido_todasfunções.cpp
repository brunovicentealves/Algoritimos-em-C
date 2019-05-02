#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>



//struct
typedef struct {
	int codigo;
	char nome [50];		
}INFORMACAO ;


typedef struct 	LISTA {
	INFORMACAO info;
	struct LISTA* prox;	
}LISTA;


//protipos

 int menu ();
 LISTA* procura_nod(LISTA* p,int cod);
 void criar_lista(LISTA **l);
  void entrada_dados( LISTA* aux );
 void incluir_fim(LISTA**l);
void imprime_lista(LISTA * aux );
void incluir_inicio (LISTA** l);
void excluir_nodo(LISTA** l);
void conta_conta (LISTA *l);
void conta_conta (LISTA *aux);
void inserir_lis_order(LISTA ** l);
void imprime(LISTA * l);
void ordenar(LISTA**l);
 main(){
 setlocale(LC_ALL,"portuguese");	
	int seleciona;
	
	LISTA* l;
	while(1){
		
	seleciona=menu();
	switch(seleciona){
		case 1 : 
		criar_lista(&l);
		break;
		
		case 2 : 
		 incluir_fim(&l);
		break;
		
		case 3 : 
		incluir_inicio (&l);
		break;
		
		case 4 : 
		imprime_lista( l);
		break;
		
		case 5 :
		excluir_nodo(&l);
		break;
		
		case 6: 
		 inserir_lis_order(&l);
		break;
		
		case 7: 
		 conta_conta (l);
		break;
		
		case 8: 
		 imprime(l);
		break;
		
		case 9: 
		 ordenar(&l);
		break;
		
		case 0 : 
		exit(1);
		break;
		
		default:printf("\nopção invalida");
		
		
	}	
		
   }
	
}

 int menu (){
 	int seleciona;
 	printf("\n============[ menu ]============");
 	printf("\n 1- Criar Lista");
 	printf("\n 2- incluir no fim ");
 	printf("\n 3- incluir no inicio");
 	printf("\n 4- imprime lista");
 	printf("\n 5- exluir nodo");
 	printf("\n 6- ordenar nodo");
 	printf("\n 7- contar registros");
 	printf("\n 8-imprime cadastro.");
 	printf("\n 9-ordenar por codigo.");
 	printf("\n 0- sair");
 	printf("\n==================================");
 	printf("\n======>");
 	scanf("%i",&seleciona);
 	return seleciona;
 }
 
 void criar_lista(LISTA **l){
 	*l=NULL;
 	system("cls");
	 printf("\n Lista criada!!");	
 }
 
 
 void entrada_dados( LISTA* aux )
{ 
    printf( "\n\n Digite a codigo: " ); 
    fflush( stdin );     
    scanf("%i", &aux->info.codigo);

    printf( "\n Digite o nome: " );
    fflush( stdin );    
    gets( aux->info.nome );
  
    aux->prox = NULL;  

    
}
 
  void incluir_fim(LISTA**l){
  	LISTA* p;
  	
  	
  	LISTA* no =(LISTA*)malloc(sizeof(LISTA));
	  
	  if (no!=NULL){
	  
	  	entrada_dados(no);
	  	if(*l==NULL){
			*l=no;	  		
		  }else{
		  	p=*l;
		  	while(p->prox!=NULL){
		  		p=p->prox;
			  }
			  p->prox=no;
		  }	
		  system("cls");
		  printf("\n registro concluido!!");
	      } else{
	      	system("cls");
	  		printf("\n lista cheia!!");
	  } 	
  }
  
  
  void imprime_lista(LISTA * aux ){
  	if (aux==NULL){
  		system("cls");
	  printf("\nlista vazia!!");
	  }else{
	  	system("cls");
	  	printf("\n ========= [ Relatorio Geral]==============");
	  	while(aux!=NULL){
		printf("\nCodigo :%i",aux->info.codigo);	  		
	  	printf("\n\n nome : %s",aux->info.nome);
		printf("\n\n============================");	
	  	aux=aux->prox;	
	  		
		  }	
	  }	
  }
   
 void incluir_inicio (LISTA** l){
 	LISTA *p ;
 	
LISTA* no = (LISTA *)malloc(sizeof (LISTA));

 	if(no==NULL){
 		system("cls");
 		printf("\n Lista vazia!");
	 }else{
	 	entrada_dados(no);
	 	no->prox=*l;
	 	*l=no;	
	 }
 } 
 
 LISTA* procura_nod(LISTA* p,int cod){
 	while((p->prox!=NULL) &&  (cod!=p->info.codigo)){
 		p=p->prox;	
	 }
 	return p;
 }



 
 void excluir_nodo(LISTA** l){
 	LISTA *p,*no;
 	 int cod;
 	 do{
 	 	printf("\n Procure por codigo o cliente ,digite o  codigo :");
	  scanf("%i",&cod);
	  if(cod<0){
	  	system("cls");
	  	printf("\nopção invalida!!");
	    }
	  }while(cod<0);	
	  if(*l!=NULL){
	  	no=procura_nod(*l,cod);
	  	if((cod==no->info.codigo) && (no!=NULL)){
	  		p=*l;
	  		if(p==no){
	  			*l=p->prox;
			  }else{
			  while(p->prox!=no){
		  		p=p->prox;
			  }
			  p->prox=no->prox;
			  }
				free(no);
			  	system("cls");
			  	printf("\nRegistro excluido!!");	
			  
		  }else{
		  	system("cls");
	  		printf(" \n nodo não encontrado!!");	
	  }
	  }else{
	  	system("cls");
	  	printf("\n lista vazia!!");
	  }
 }
 
 void conta_conta (LISTA *aux){
 	
 	
 	int cont=0;
    
 	while(aux!=NULL){
 		aux=aux->prox;
 		cont++;	
	 }
 	system("cls");
 
 	printf("\n contem  %i cadastros no sistema!!",cont);
 }
 
 
 void imprime(LISTA * l){
 	int cod=0;
 	LISTA *no;
 		do{
 		system("cls");
 	 	printf("\n Procure por codigo o cliente ,digite o  codigo :");
	  scanf("%i",&cod);
	  if(cod<0){
	  	system("cls");
	  	printf("\nopção invalida!!");
	    }
	  }while(cod<0);
 		
 		no=procura_nod(l ,cod);
	 if(no->info.codigo==cod){
	 	system("cls");
	 	printf("\n=======[ relatorio ]===========");
	 	printf("\nCodigo :%i",no->info.codigo);	  		
	  	printf("\n nome : %s",no->info.nome);
		printf("\n\n============================");
	 		
	 }
 }
 
 void inserir_lis_order(LISTA ** l){
 	LISTA *p=*l;
 	LISTA* no;
 	LISTA *anterior = NULL;
 	no=(LISTA*)malloc(sizeof(LISTA));
	 	if(no!=NULL){
	 	entrada_dados(no);
	 	while((p != NULL)&& (p->info.codigo < no->info.codigo)){
	 		anterior=p;
	 		p=p->prox;
	 		
		   }	
		   
			if(*l==NULL){
				*l=no;
				no->prox=NULL;	
			}else{
				
			anterior->prox=no;
			no->prox=p;			
			}
		   printf("\n cadastro com sucesso!!");
		 }else{
		 	system("cls");
		 	printf("\n LIsta cheia !!!");	 	
	}	
 }
 
 
 
 void ordenar(LISTA**l){
 	if(*l==NULL){
 		printf("\nLista vazia!!");
	 }else{
	 	if((*l)->prox==NULL){
	 		printf("\n lista com apenas 1 elemento!!");
		 }else{
		 	INFORMACAO aux;
	 	LISTA * anterior = *l;
	 	LISTA *p = anterior->prox;
	 	while(anterior->prox!=NULL){
	 		while(p !=NULL){
	 			if(p->info.codigo<anterior->info.codigo){
	 				aux =p->info;
	 				p->info=anterior->info;
	 				anterior->info=aux;
	 				
	 				
				 }
	 			p=p->prox;
	 			
	 			
			 }	
			 
			 anterior=anterior->prox;
			 p=anterior->prox;
		 }
		 system("cls");
		 printf("\l ordenado com sucesso!!");	
	   }		 	
    }	
 }
