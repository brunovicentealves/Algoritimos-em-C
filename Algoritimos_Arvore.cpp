/***********************************************/ 
/* Árvores Binárias                            */
/* objetivo: registro de códigos               */
/* programador: Daniela Bagatini               */
/* criado em: 11/05/2017                       */
/* data da ultima alteracao: 14/05/2017        */
/***********************************************/ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


#define FALSE   0      // constante falsa
#define TRUE   !FALSE  // constante verdadeira


/***********************************************/ 
/* Definição dos Registros                     */
/***********************************************/ 
typedef struct {          // registro 
       int  codigo;
} INFORMACAO;
       
typedef struct arvore {
       INFORMACAO info;      // dados do registro
       struct arvore* subd;  // ponteiro para o nodo da direita
       struct arvore* sube;  // ponteiro para o nodo da esquerda
} ARVORE; 



/***********************************************/ 
/* Definição das Funções                       */
/***********************************************/
void    entrada_dados ( ARVORE* aux ); // leitura dos dados de entrada
void    imprime_ARVORE( ARVORE* aux ); // visualizacao da lista em tela
void    cria_ARVORE   ( ARVORE** r );  // inicializa arvore com NULL
void    insere        ( ARVORE** r );  // inclui um novo registro na arvore
int     busca         ( int matricula, ARVORE** a, ARVORE** p ); // procura na arvore por uma matricula
void    sucessor      ( ARVORE* p, ARVORE** q, ARVORE** b );
void    antecessor    ( ARVORE* p, ARVORE** q, ARVORE** b );
void    remove        ( ARVORE** r );  // exclui um regitro por matricula


       
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    char op;   // opcao do menu                               
    ARVORE* r; // declaracao da ARVORE // variavel do tipo ARVORE = ARVORE de ponteiros

    r= NULL;
    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registros - Menu                         " );
         printf( "\n [1] Cria ARVORE                                      " );
         printf( "\n [2] Insere                                           " );
         printf( "\n [3] Remove                                           " );
         printf( "\n [4] Imprime                                          " );         
         printf( "\n [5] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche(); // tecla de opcao do menu

        switch( op ) {
           case '1':   // rotina cria ARVORE       
                   cria_ARVORE( &r );
                   break;
                                
           case '2':  // rotina inclui nodo no final da ARVORE
                   insere( &r );    
                   break;
                      
           case '3':  // rotina exclui nodo da ARVORE
                   remove( &r );
                   break;
           
           case '4':  // rotina exclui nodo da ARVORE
                   imprime_ARVORE( r );
                   break;                   
                                                         
           case '5': // término do programa                                                 
                   exit( 1 ); 
                   break;
                
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        
        printf( "\n" );
     } // fim do while( 1 )
     
 return 0;
} // fim do programa principal



/************************************************ 
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saída   : nodo com dados                      *
 ************************************************/
void entrada_dados( ARVORE* aux )
{ 
   printf("\n Digite o munero :");
   scanf("%i",&aux->info.codigo);
 
    aux->subd = NULL;    // não aponta
    aux->sube = NULL;    // não aponta

}



/*************************************************
 * imprime_ARVORE                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                               *
 * saída   : nenhuma                             *
 *************************************************/ 
void imprime_ARVORE( ARVORE* p )
{    
     
    if( p != NULL ){ // verifica se a raiz e diferente de vazio
        
         printf( "\n codigo: %i", p->info.codigo );
        imprime_ARVORE( p->sube );
        imprime_ARVORE( p->subd );
    }
    else
       printf("\n Arvore vazia!");
}



/************************************************
 * cria_ARVORE                                   *
 * objetivo: rotina para inicializar a ARVORE    *
 * entrada : nenhuma                             *
 * saída   : NULL (inicializa ARVORE)            *
 ************************************************/ 
void cria_ARVORE( ARVORE** r )
{
    *r = NULL; // arvore criada, raiz nao aponta
}



/************************************************* 
 * insere                                        *
 * objetivo: rotina para inserir no fim da ARVORE*
 * entrada : ARVORE                              *
 * saída   : ARVORE com mais um registro         *
 *************************************************/ 
void insere( ARVORE** r ){
	ARVORE *novo=(ARVORE*)malloc(sizeof (ARVORE));
	if(novo==NULL){
		system("cls");
		printf("\n não há espaço na memoria!");	
		
	}else{
		if(*r==NULL){
			entrada_dados(novo);
			*r=novo;
			
		}else{
				ARVORE *p =*r;
				ARVORE  *ant;
				entrada_dados(novo);
				while(p!=NULL){
						ant =p;
						
						if(novo->info.codigo==p->info.codigo){
							
							free(novo);
							
							return;
							
						}	
						
						if(novo->info.codigo> p->info.codigo){
							
							p=p->subd;
							
							
						}
						
						if(novo->info.codigo<p->info.codigo){
							
							p=p->sube;
							
							
						}
							
					
					
				}
				
				
				if(novo->info.codigo>ant->info.codigo){
					ant->subd=novo;
					
				}else{
					
					ant->sube=novo;
						
				}
				
		}	
	}
}



/************************************************ 
 * busca                                        *
 * objetivo: achar nodo                         *
 * entrada : ARVORE e código a ser excluido     *
 * saída   : posicao ou NULL (não encontrou)    *
 ************************************************/ 
int busca( int cod, ARVORE** a, ARVORE** p )
{
 
}



/*************************************************** 
 * remove                                          *
 * objetivo: rotina para excluir nodo da ARVORE    *
 * entrada : ARVORE                                *
 * saída   : ARVORE                                *
 ***************************************************/ 
void remove( ARVORE** r )
{
 
}


/*************************************************** 
 * sucessor                                        *
 * objetivo: rotina para descobrir nodos filhos    *
 * entrada : ARVORE, ponteiros auxiliares q e b    *
 * saída   : ponteiros auxiliares q e b            *
 ***************************************************/ 
void sucessor( ARVORE* p, ARVORE** q, ARVORE** b )
{

}
 
 
 
/*************************************************** 
 * antecessor                                      *
 * objetivo: rotina para descobrir nodos filhos    *
 * entrada : ARVORE, ponteiros auxiliares q e b    *
 * saída   : ponteiros auxiliares q e b            *
 ***************************************************/ 
void antecessor( ARVORE* p, ARVORE** q, ARVORE** b )
{
 
}         
