#include "stdafx.h"
#include "Pila.h"

Pila::Pila(){
}

Pila::~Pila(){
}

void Pila::push(Elemento * elemento){
	this->insertarInicio(elemento);
}

Elemento * Pila::peek(){
	return getCabeza();
}

Elemento * Pila::pop(){
	Elemento * temp = getCabeza();
	this->eliminarInicial();
	return temp;
}

ostream & operator<<(ostream & out, Pila & a) {
	a.imprimir(a.getCabeza(), out);
	return out;
}

void Pila::imprimir(Elemento* nodo, ostream& out) {
	if (nodo->getProx() != NULL) {
		out << "\n^\n" << *nodo;
		imprimir(nodo->getProx(), out);
	}
}
