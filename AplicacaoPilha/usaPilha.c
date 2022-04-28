// nome: usaPilha.c  

// Autor: Matheus Gomes Santos - RGM:26136805
// Turma: 3/N1   
    
#include "Pilha.h"

#include <stdio.h>

Pilha* CopiaInvertida(Pilha* p);

int main (void) {
	
  /* declara variáveis para acessar pilha */
  Pilha *p, *copia;
  float n;           
  char op;
  
  p = pilha_cria();   /* inicia pilha vazia */
  
  do{
  fflush(stdin);
  printf("\n Informe um numero real: ");
  scanf("%f", &n);
  
  pilha_push(p, n); /* insere na pilha o elemento n*/
  
  fflush(stdin);
  printf("\n\n Digite N para sair, qualquer tecla para repetir: ");
  scanf("%c", &op);
  
}while(op != 'N');			
  
  copia = CopiaInvertida(p);
  
  printf("\n Pilha Original \n");
  while (!pilha_vazia(p)){
    printf ("%f \n", pilha_pop(p)); 
  }

  printf("\n Pilha Invertida \n");
  while (!pilha_vazia(copia)){
    printf ("%f \n", pilha_pop(copia)); 
  }
  
  /* insere na pilha o elemento 4.5 */
  pilha_push(p, 4.5);
  
  pilha_libera(p);
  pilha_libera(copia);
  
  return 0;
}

Pilha* CopiaInvertida(Pilha* p){
	
	//	Declaração de variáveis para acessar as pilhas;
	Pilha *pilhaAuxiliar, *pilhaResposta;  
	
	float v;
	
	pilhaAuxiliar = pilha_cria();
	pilhaResposta = pilha_cria();
	
	while(!pilha_vazia(p)){
		
		v = pilha_pop(p);
		
		pilha_push(pilhaAuxiliar, v);
		pilha_push(pilhaResposta, v);
	}
	
	while(!pilha_vazia(pilhaAuxiliar)){
		
		v = pilha_pop(pilhaAuxiliar);
		
		pilha_push(p, v);	
	}
	
	pilha_libera(pilhaAuxiliar);
	
	return pilhaResposta;
}
