#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "restaurante.h"

int main(){
	int escolha=3;
	while(escolha != 0){
		printf("****MENU RESTAURANTE****\n");
		printf("1: Adicionar pedido\n");
		printf("2: Listar Pedidos\n");
		printf("3: Remover Antigo\n");
		printf("0: Sair!\n");
		scanf("%d",&escolha);
		fflush(stdin);
		switch(escolha){
			case 1:{
				Pedido *a = lePedido();
				//addPedido(a);
			}
			default:{
				fflush(stdin);
				if(escolha > 3)		
					printf("****Opcao Invalida, tentar novamente****\n");
			}
		}
	}
return 0;
}


