#include<stdlib.h>
#include<iostream>
#include<iomanip>

using namespace std;

struct nodo{
    int x, f, c;
    nodo *ant,*sig;
	nodo(){
        ant=NULL;
        sig=NULL;
	}
	nodo(int n){
        x=n;
        ant=NULL;
        sig=NULL;
	}
};

class MATRIX{

    friend istream& operator>>(istream&,MATRIX&);
    friend ostream& operator<<(ostream&,MATRIX&);
    friend MATRIX operator+(MATRIX&,MATRIX&);
    friend MATRIX operator-(MATRIX&,MATRIX&);
    friend MATRIX operator*(MATRIX&,MATRIX&);

private:
	int m,n;
    nodo *inicio,*fin;
public:
    void InsertarI(int);
    void InsertarF(int);
    void BorrarI();
    void BorrarF();
    int contar();
    //nodo *Buscar(int);
    int encuentra(int);
    void verificaOrden();
    void eliminaM();
    void generaM(int);
    void leer();
    void imprimir();
    void operator=(MATRIX);
	int datonodo(int,int);
    MATRIX(){
        inicio=NULL;
        fin=NULL;
        m=0;
        n=0;
    }
    MATRIX(int filas,int columnas,int relleno){
        inicio=fin=NULL;
        m=filas;
        n=columnas;
        verificaOrden();
        generaM(relleno);
    }
    MATRIX(int fil,int col){
        inicio=NULL;
        fin=NULL;
        m=fil;
        n=col;
        verificaOrden();
    }

};


void MATRIX::generaM(int val){
    // if (val!=NULL){
    for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
        InsertarF(val);
		fin->f=i;
        fin->c=j;
    }
}

void MATRIX::leer(){
    int nume;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cout << "Introduce [" << i << "][" << j << "]: ";
            cin>>nume;
			InsertarF(nume);
            fin->f=i;
            fin->c=j;

        }
}

void MATRIX::InsertarI(int x){
    if(inicio==NULL){
    	inicio=new nodo(x);
    	fin=inicio;
    }
    else {
    	nodo *nuevo=new nodo(x);
    	nuevo->sig=inicio;
    	inicio->ant=nuevo;
    	inicio=nuevo;
    }
};

void MATRIX::InsertarF(int x){
    if(inicio==NULL){
        nodo *aux=new nodo(x);
    	inicio=aux;
		fin=aux;

    }
    else {
    	nodo *nuevo=new nodo(x);
    	nuevo->ant=fin;
    	fin->sig=nuevo;
    	fin=nuevo;
    }
};

void MATRIX::imprimir(){
    nodo *aux= inicio;
    cout << "Mis filas son " << m << endl
    << "Mis columnas son " << n <<endl;
    if(inicio!=NULL){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout <<setw(5)<<aux->x ;
                aux=aux->sig;}
            cout << endl;
        }
    }
    else
        cout << "MATRIZ VACIA" << endl;
}

void MATRIX::BorrarF(){

    if(inicio==NULL){
    	cout<<"Lista vacia";

    }
    else if(inicio==fin){
    	delete inicio;
    	delete fin;
    }

    else{
    	nodo *aux=fin;
    	fin=fin->ant;
    	fin->sig=NULL;
    	aux->ant=NULL;
    	delete aux;
    	//m--;
        //n--;
    }

};

void MATRIX::BorrarI(){

    if(inicio==NULL){
    	cout<<"Lista vacia";

    }
    else if(inicio==fin){
    	free( inicio);
    	free( fin);
    }

    else{
    	nodo *aux=inicio;
    	inicio=inicio->sig;
    	inicio->ant= NULL;
    	aux->sig=NULL;
    	delete aux;
    }

};

int MATRIX::contar(){
	int tam=0;
	if(inicio==NULL)
		tam=0;
	else {
		nodo *aux=inicio;
		while (aux!=NULL) {
			tam++;
			aux=inicio->sig;
		}
	}
	return tam;
};

void MATRIX::verificaOrden(){
    if(m<0 || n<0 || (m!=0 && n==0) || (n!=0 && m==0)){
        eliminaM();
        cout << "Error de orden." << endl;
        exit(-1);
    }
}

void MATRIX::eliminaM(){
    while(inicio!=NULL){
        BorrarI();}
    m=0;
    n=0;
};

int MATRIX::datonodo(int fila, int columna){
	nodo *aux=inicio;
	while(fila!=aux->f || columna!=aux->c)
		aux=aux->sig;
	return aux->x;
};


void MATRIX::operator=(MATRIX X){
    eliminaM();
    if(X.m!=0){
        m=X.m;
        n=X.n;
		nodo *aux=X.inicio;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
				InsertarF(aux->x);
				aux=aux->sig;
}
    }
	};

MATRIX operator+(MATRIX& X,MATRIX& Y){
    MATRIX Z;
    if(X.m==Y.m && X.n==Y.n){
        Z.m=X.m;
        Z.n=X.n;
		nodo *aux1=X.inicio;
		nodo *aux2=Y.inicio;
       // Z.generaMatriz();
        for(int i=0;i<X.m;i++)
            for(int j=0;j<X.n;j++){
                Z.InsertarF(aux1->x+aux2->x);
				aux1=aux1->sig;
				aux2=aux2->sig;}
    }
    else
        cout << "Error de orden. No pueden sumarse las matrices." << endl;
    return Z;
};

MATRIX operator-(MATRIX& X,MATRIX& Y){
    MATRIX Z;
    if(X.m==Y.m && X.n==Y.n){
        Z.m=X.m;
        Z.n=X.n;
		nodo *aux1=X.inicio;
		nodo *aux2=Y.inicio;

        for(int i=0;i<X.m;i++)
            for(int j=0;j<X.n;j++){
                Z.InsertarF(aux1->x-aux2->x);
				aux1=aux1->sig;
				aux2=aux2->sig;}
    }
    else
        cout << "Error de orden. No pueden restarse las matrices." << endl;
    return Z;
};

MATRIX operator*(MATRIX& X,MATRIX& Y){
    MATRIX Z;
	int suma=0;
    if(X.n==Y.m){
        Z.m=X.m;
        Z.n=Y.n;
        for(int i=0;i<X.m;i++)
            for(int j=0;j<Y.n;j++){
                for(int k=0;k<X.n;k++){
					suma+=( X.datonodo(i,k) * Y.datonodo(k,j));
				}
		Z.InsertarF(suma);
				suma=0;}
		}
    else
        cout << "Error de orden. No pueden multiplicarse las matrices." << endl;
    return Z;
};

int main(){

    MATRIX A(2,3),B(2,3,2),C, D,E(3,2),F;
	cout<<"Programa de matrices"<<endl<<endl;
	cout<<"Ingrese valores para la matriz A:"<<endl<<endl;
	A.leer();
	cout<<endl<<"Ingrese valores para la matriz E:"<<endl<<endl;
	E.leer();
    cout<<endl<<"La Matriz A es:"<<endl;
    A.imprimir();
    cout<<endl<<"LA Matriz B es:"<<endl;
    B.imprimir();
    C=A+B;
	cout<<endl<<"La Matriz C=A+B es:"<<endl;
	C.imprimir();
	D=A-B;
	cout<<endl<<"La Matriz D=A-B es:"<<endl;
	D.imprimir();
	cout<<endl<<"La Matriz E es:"<<endl;
	E.imprimir();
	F=A*E;
	cout<<endl<<"La Matriz F=A*E es:"<<endl;
	F.imprimir();

    return 0;
}
