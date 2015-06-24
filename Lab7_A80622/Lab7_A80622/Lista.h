#pragma once
#include "Elemento.h"

using namespace std;

class Lista{

	friend ostream & operator<<(ostream &, Lista &);

private:
	Elemento * cabeza;
	int getListaTam();

public:
	Lista();
	virtual ~Lista();
	void insertarInicio(Elemento *);
	void insertarFinal(Elemento *);
	void insertarPosEspecifica(int, Elemento *);
	void eliminarInicial();
	void eliminarFinal();
	void eliminarPosEspecifica(int);
	Elemento * getCabeza();

private:
	void imprimir(Elemento *, ostream &);
	void destruirRec(Elemento *);
};

ostream & operator<<(ostream &, Lista &);
