#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <time.h>
int main () {
  /* FILE *fp;

   fp = fopen("file.txt","w+");
   fputs("This is tutorialspoint.com", fp);
  //ele começa a escrever a partir da posiçao do 7
   fseek( fp, 7, SEEK_SET );
   fputs(" C Programming Language", fp);
   fclose(fp);*/
 	FILE *fp;
	fp = fopen("id.txt","r");
	int id=1,e=0;
	if(fp == NULL){
		fp = fopen("id.txt","w");
		fprintf(fp,"0");
		fclose(fp);
		fp = fopen("id.txt","r");	
	}
	char aux[2],x;
		while(fscanf(fp,"%c",&x)!=EOF){            	
			aux[e++]=x;
        }	
		fclose(fp);
		id = strtol(aux, NULL, 10);
		id += 1;
	fp = fopen("id.txt","w");
				
		printf("%d\n",id);
		fprintf(fp,"%d",id);
		//nao ta salvando no arquivo 
		fclose(fp);
	printf("Timestamp: %d\n",(int)time(NULL));
	char texto[1000];
	printf("digite o pedido\n");
	fgets(texto, 1000, stdin);
	printf("digite a mesa\n");
	int mesa;
	scanf("%d",&mesa);
   return 0;
}
