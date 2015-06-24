#pragma once
#include "Lista.h"

using namespace std;

class Pila: protected Lista {

	friend ostream & operator<<(ostream &, Pila &);

public:
	Pila();
	virtual ~Pila();
	void push(Elemento *);
	Elemento * peek();
	Elemento * pop();

private:
	void imprimir(Elemento *, ostream &);
};

ostream & operator<<(ostream &, Pila &);