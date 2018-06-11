#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};
int numNodos = 0;
typedef struct nodo *ABB;

ABB unirABB(ABB izq, ABB der){
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

ABB crearNodo(int x){
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(ABB &arbol,int x);
void mostrar(ABB arbol, int n);
void preOrden(ABB arbol);
void enOrden(ABB arbol);
void postOrden(ABB arbol);
void Borrar(ABB &arbol,int n);

int main(){
    ABB arbol = NULL;
    int opc;
    char Res;
    int x,n; 

    cout <<"*******ARBOL BINARIO DE BUSQUEDA********\n"<<endl;
do{
	
	cout<<"-----> ESCOJA UNA OPCION:"<<endl;
	cout<<"1.-INTRODUCIR DATOS"<<endl;
	cout<<"2.-MOSTRAR DATOS"<<endl;
	cout<<"3.-MOSTRAR EN PREORDEN"<<endl;
	cout<<"4.-MOSTRAR EN POSTORDEN"<<endl;
	cout<<"5.-MOSTRAR EN INORDEN"<<endl;
	cout<<"6.-BORRAR"<<endl;
	opc=getch();
	switch(opc){ 
		case '1': 
			cout<<"INTRODUCIR DATOS"<<endl;
    		do{
        		cout << "------>NUMERO DEL NODO"<< ": ";
        		cin >> x;
        		insertar( arbol, x);
        		Res=getch();
    		}
			while(Res=='S'|| Res=='s');
    		break;
		case '2': ;
			cout<<"----->MOSTRAR DATOS:"<<endl;
			mostrar( arbol, 0);
			cout<<"\n";
			
			break;
		
		case '3': 	
			cout<<"---->MOSTRADO EN PREORDEN:"<<endl;
			preOrden(arbol);
			cout<<"\n";
		
			break;
		case '4':	
			cout<<"----->MOSTRADO EN POSTORDEN:"<<endl;
			postOrden(arbol);
			cout<<"\n";
			
			break;
		case '5': 
			cout<<"------>MOSTRADO EN INORDEN:"<<endl;
			enOrden(arbol);
			cout<<"\n";
		
			break;
		case '6':
			cout<<"----->ELIMINAR UN NUMERO:"<<endl;
			cout<<"INGRESA EL NUMERO QUE DESEAS ELIMINAR::"<<endl;
			cin>>x;
			Borrar(arbol,x);
			cout<<"\n ELIMINADO<<"<<endl;
		
			break;
		}
	}
while(opc!='7');
  
    return 0;
}

void insertar(ABB &arbol, int x){
    if(arbol==NULL){
        arbol = crearNodo(x);
    }
    else 
		if(x < arbol->nro)
        	insertar(arbol->izq, x);
    	else 
			if(x > arbol->nro)
          		insertar(arbol->der, x);		
}

void preOrden(ABB arbol){
     if(arbol!=NULL){
        cout << arbol->nro <<" ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(ABB arbol){
    if(arbol!=NULL){
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}

void postOrden(ABB arbol){
    if(arbol!=NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}

void mostrar(ABB arbol, int n){
     if(arbol==NULL)
          return;
    	mostrar(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   "; 
	cout<< arbol->nro <<endl;
	mostrar(arbol->izq, n+1);
}

void Borrar(ABB &arbol, int x){
     if(arbol==NULL) return;
     if(x<arbol->nro)
        Borrar(arbol->izq, x);
    else if(x>arbol->nro)
        Borrar(arbol->der, x);
    else{
        ABB p = arbol;
        arbol = unirABB(arbol->izq, arbol->der);
        delete p;
    }
}
