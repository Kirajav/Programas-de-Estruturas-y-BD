#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct nodo{
    int num;
    nodo *sig,*ant;

	nodo(int numero){
	num=numero;
	ant=NULL;
	sig=NULL;
	}
	nodo(){
	    ant=NULL;
	sig=NULL;
	}
};


class LDE{
private:
    nodo *inicio,*fin;
public:
    LDE(){
       inicio = NULL;
       fin=NULL;}
    void leer(int);
    void insertarF(int);
    int quitar(nodo*);
    void imprimir();
    int inicioLDE();
    bool LDEVacia();
    void buscaDup();
    void limpiarLDE();
    ~LDE(){
        limpiarLDE();
        }
};
void LDE::leer(int tam){
    int numero;
    cout<<"Dame los elementos de la lista: "<<endl;
    for(int i=1;i<=tam;i++){
    cout<<"Num "<<i<<": ";
    cin>>numero;
    insertarF(numero);}
}

void LDE::insertarF(int n){
    if(inicio==NULL){
        nodo* nuevo;
        nuevo = new nodo(n);
        inicio=nuevo;
        fin=nuevo;
        }
    else if(inicio==fin){
        nodo *nuevo;
        nuevo=new nodo(n);
        inicio->sig=nuevo;
        nuevo->ant=inicio;
        fin=nuevo;
    }
    else{
        nodo *nuevo;
        nuevo=new nodo(n);
        nuevo->ant=fin;
        fin->sig=nuevo;
        fin=nuevo;
        }
}


int LDE::quitar(nodo *dup){
    if (LDEVacia())
        throw "LDE vacia, no se puede extraer.";
    else if(dup==fin){
        int aux=dup->num;
        fin=fin->ant;
        fin->sig=NULL;
        dup->ant=NULL;
        delete dup;
        return aux;
    }
    else{
    int aux = dup -> num;
    nodo *enl=dup->ant;
    enl->sig=dup->sig;
    dup->sig->ant=enl;
    dup->ant=NULL;
    dup->sig=NULL;
    delete dup;
    return aux;
    }
}

void LDE::buscaDup(){

 for(nodo *pivote=inicio; pivote!=NULL;){
     for(nodo *comp=pivote->sig;comp!=NULL;){
     if(pivote->num==comp->num){
        cout<<"Se ha quitado el numero: "<<quitar(comp)<<endl;
        comp=pivote->sig;
     }
     else
    comp=comp->sig;
  }
    pivote=pivote->sig;
 }

}

void LDE::imprimir(){
    if (LDEVacia())
        throw "LDE vacia.";
    nodo *rec=inicio;
    while (rec!=NULL){
        cout<<rec->num<<endl;
        rec=rec->sig;
    }
}


bool LDE::LDEVacia(){
    return inicio==NULL;

}

int LDE::inicioLDE(){
    if (LDEVacia())
    throw "LDE vacia";
    return inicio -> num;
    }

void LDE:: limpiarLDE(){
    nodo* nod;
    while(!LDEVacia()){
    nod = inicio;
    inicio = inicio -> sig;
    delete nod;
    }
}


int main(){
int t;
LDE LDENum;   // crea LDE vacia
cout<<"Dame el tama–o de la lista de numeros: ";
cin>>t;
LDENum.leer(t);
cout<<"La lista de numeros original es: "<<endl;
LDENum.imprimir();
LDENum.buscaDup();
cout<<"La lista de numeros sin duplicados es: "<<endl;
LDENum.imprimir();

return 0;
}

