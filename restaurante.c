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
	int id=0,e=0,id2;
	char aux[2],x;
	if(fp == NULL){
		fp = fopen("id.txt","w");
		fprintf(fp,"0");
		fclose(fp);
		fp = fopen("id.txt","r");	
	}
	while(fscanf(fp,"%c",&x)!=EOF){            	
		aux[e++]=x;
    }	
	fclose(fp);
	id = strtol(aux, NULL, 10);
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

