#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip.h>

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
//Palabra::Palabra(){};

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
    W.nL=nL+P.nL+1;
    W.text=new char[W.nL+1];
    for(i=0;i<nL;i++)
        W.text[i]=text[i];
    W.text[i+2]='#';
    for(i=nL+3;i<=W.nL;i++)
        W.text[i+1]=P.text[i-(nL-1)];
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
Palabra A,B;
A.leer();
B.leer();
A.imprimir();
B.imprimir();
return 0;
}
