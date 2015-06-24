#pragma once
#include "Elemento.h"

using namespace std;

class ArbolBinario {

	friend ostream & operator<<(ostream &, ArbolBinario &);

private:
	Elemento * raiz;

public:
	ArbolBinario();
	virtual ~ArbolBinario();
	void insertarElemento(Elemento *);

private:
	void insertarElementoRec(Elemento *, Elemento *);
	void imprimir(Elemento *, ostream &, int);
	void destruirRec(Elemento *);
};

ostream & operator<<(ostream &, ArbolBinario &);
