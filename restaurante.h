//restaurante.h
typedef struct Pedido{
    int ID;
	char texto[1000];
	int mesa;
	int timestamp;
}Pedido;
typedef struct Pedidos{
    Pedido *p[1000];
    int top;
}Pedidos;
	
Pedido *newPedido(char*texto, int mesa);

Pedido *lePedido();

void addPedido(Pedido*p);

//função rodiculamente irreal 
Pedidos *listaPedidos(); 

Pedido *removeMaisAntigo();


