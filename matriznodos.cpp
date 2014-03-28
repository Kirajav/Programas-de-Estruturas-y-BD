#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct nodo{
    int dato, m,n;
    nodo *ant,*sig;
};

class MATRIX{
private:
    nodo *inicio,*fin;
public:
    void InsertarI(int);
    void InsertarF(int);
    void BorrarI();
    void BorrarF();
    int contar();
    nodo *Buscar(int);
    int encuentra(int);
    void imprimir();
    MATRIX{ inicio=fin=NULL;}
};

void InsertarI(int x){
    f
};

int main(){
    Matrix A(3,4),B(5,2,0),C;
    A.leer();
    C=A+B;
    C.imprimir();
    C=A-B;
    C.imprimiir();
    C=A+B;
    C.imprimiir();
//    char c;
//    do {
//    c=getchar();
//    cout<<c;
//  } while (c != '.');
return 0;
}
