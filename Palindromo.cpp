#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct nodo{
    char c;
    nodo *sig;

	nodo(char car){
	c=car;
	sig=NULL;
	}
	nodo(){
	sig=NULL;
	}
};


class Pila{
private:
    nodo* cima;
public:
    Pila(){
       cima = NULL;}
    void insertar(char);
    char quitar();
    char cimaPila();
    bool pilaVacia();
    void limpiarPila();
    ~Pila(){
        limpiarPila();
        }
};

void Pila::insertar(char caract){
    nodo* nuevo;
    nuevo = new nodo(caract);
    nuevo -> sig = cima;
    cima = nuevo;
}

bool Pila::pilaVacia() {
return (cima == NULL);
}

char Pila::quitar(){
    if (pilaVacia())
        throw "Pila vacia, no se puede extraer.";
    char aux = cima -> c;
    cima = cima -> sig;
    return aux;
}

char Pila:: cimaPila(){
    if (pilaVacia())
    throw "Pila vacia";
    return cima -> c;
    }

void Pila:: limpiarPila(){
    nodo* n;
    while(!pilaVacia()){
    n = cima;
    cima = cima -> sig;
    delete n;
    }
}


int main(){

Pila pilaChar;   // crea pila vacia

bool esPal;
char pal[81];
cout << "Teclea la frase para verificar si es palindromo: ";
gets(pal);
for (int i = 0; i < strlen(pal); )
{
char c;
c = pal[i++];
if(c!=' ')
pilaChar.insertar(c);
}
// se comprueba si es palindromo
esPal = true;
for (int j = 0; esPal && !pilaChar.pilaVacia();j++ )
{
char c;
c = pilaChar.quitar();
if(pal[j]==' ') j++;
esPal = toupper(pal[j]) == toupper(c);
}
pilaChar.limpiarPila();
if (esPal)
cout << "La frase: " << pal << " ¡SI es un palindromo! \n";
else
cout << "La frase: " << pal << " ¡NO es un palindromo! \n";
return 0;
}
