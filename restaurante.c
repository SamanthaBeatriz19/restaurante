//restaurante.c
#include <stdlib.h>
#include <time.h>
#include "restaurante.h"
#include <string.h>
#include <stdio.h>


Pedido *newPedido(char*texto, int mesa){
	//controle de ID	
	FILE *fp;
	fp = fopen("id.txt","r");
	int id=0,e=0;
	int aux[2],x;
	if(fp == NULL){
		fp = fopen("id.txt","w");
		fprintf(fp,"0");
		fclose(fp);
		fp = fopen("id.txt","r");	
	}
	
	fscanf(fp,"%d",&id);
	fclose(fp);
	id += 1;
	fp = fopen("id.txt","w");
				
	printf("id atual:%d\n",id);
	fprintf(fp,"%d",id);
		
	fclose(fp);
	Pedido * auxa = (Pedido *)malloc(sizeof(Pedido));
	auxa->ID = id;
	strcpy(auxa->texto, texto);
	auxa->mesa = mesa;
	auxa->timestamp = (int)time(NULL);
	return auxa;
}

Pedido *lePedido(){
	char texto[1000];
	printf("digite o pedido\n");
	fgets(texto, 1000, stdin);
	fgets(texto, 1000, stdin);
	int mesa;
	printf("digite a mesa\n");
	scanf("%d",&mesa);
	Pedido *salva = newPedido(texto,mesa);
	return salva;
}
void addPedido(Pedido*p){
	
	FILE * fp = fopen("dados.txt", "a+");
	fprintf(fp,"%d\n",p->timestamp);	
	fprintf(fp,"%d\n",p->mesa);
	fprintf(fp,"%d\n",p->ID);
	fprintf(fp,"%s",p->texto);
	fclose(fp);
}
//como?
Pedidos*listaPedidos(){
	char x;
	FILE *fp = fopen("dados.txt", "r");
	while(fscanf(fp,"%c", &x)!=EOF){	
		printf("%c", x);
	}
	printf("\n");
	fclose(fp);
//devolve todos os pedidos que ainda nao foram processados.
}
Pedido *removeMaisAntigo(){
	FILE * qtd = fopen("qtd.txt", "r");
	int quant;
	fscanf(qtd,"%d",&quant); 
	FILE * fp = fopen("dados.txt", "r");
	Pedidos a;
	for(int i=0;i<quant;i++){
		Pedido * aux = (Pedido *)malloc(sizeof(Pedido));
		fscanf(fp,"%d\n",&aux->timestamp);	
		fscanf(fp,"%d\n",&aux->mesa);
		fscanf(fp,"%d\n",&aux->ID);
		fscanf(fp,"%s",aux->texto);
		a.p[i]=aux;
	}
	fclose(fp);
	 fp = fopen("dados.txt", "w");	
	printf("EXCLUINDO PEDIDO ANTIGO\n");
	printf("tempo: %d\n",a.p[0]->timestamp);
	printf("mesa: %d\n",a.p[0]->mesa);
	printf("id: %d\n",a.p[0]->ID);
	printf("texto: %s\n",a.p[0]->texto);
	for(int i=1;i<quant;i++){
		fprintf(fp,"%d\n",a.p[i]->timestamp);	
		fprintf(fp,"%d\n",a.p[i]->mesa);
		fprintf(fp,"%d\n",a.p[i]->ID);
		fprintf(fp,"%s",a.p[i]->texto);
	}
	fclose(fp);
	return NULL;
}
