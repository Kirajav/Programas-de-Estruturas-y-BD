#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#include "iostream"

using namespace std;

class Palabra{

private:
    char *text;
    int nL;
public:
    //void Palabra(){};
    void leer();
    void imprimir();
    int longitud(char *x);
    Palabra operator +(Palabra);
};

//Palabra::Palabra(){nL=0};

void Palabra::leer(){
    char A[105];
    cout<<"Teclee una palabra: ";
    cin>>A;
    nL=strlen(A);
    text=new char[nL+1];
    strcpy(text,A);
};

void Palabra::imprimir(){
    cout<<text;
}
Palabra Palabra::operator +(Palabra P){
    Palabra W;
    int i;
    W.nL=this->nL+P.nL+1;
    W.text=new char[W.nL];
    for(i=0;i<nL;i++)
        W.text[i]=this->text[i];
    W.text[this->nL]='#';
    for(i=this->nL+1;i<=W.nL;i++)
        W.text[i]=P.text[i-(nL+1)];
    return W;
}
int Palabra::longitud(char *x){
    int n=0;
    while(x!=NULL){
        n++;
        x++;
    }
    return n;
}

int main(void){
Palabra A,B,C;
A.leer();
B.leer();
A.imprimir();
cout<<endl;
B.imprimir();
cout<<endl;
C=A+B;
C.imprimir();
return 0;
}
