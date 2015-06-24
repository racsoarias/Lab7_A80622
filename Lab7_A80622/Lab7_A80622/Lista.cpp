#include "stdafx.h"
#include "Lista.h"

Lista::Lista(){
	cabeza = NULL;
}

Lista::~Lista(){
	if (cabeza != NULL) {
		destruirRec(cabeza);
	}
}

void Lista::destruirRec(Elemento * nodo) {
	if (nodo->getProx() != NULL) {
		destruirRec(nodo->getProx());
	}
	// Primero se destruye el último y hasta llegar a la cabeza.
	delete nodo;
}

void Lista::insertarInicio(Elemento * elemento){
	if (cabeza == NULL){
		cabeza = elemento;
	}
	else{
		elemento->setProx(cabeza);
		cabeza = elemento;
	}
}

void Lista::insertarFinal(Elemento * elemento){
	Elemento *temp = cabeza;

	if (cabeza == NULL){
		cabeza = elemento;
	}
	else{
		while (temp->getProx() != NULL){
			temp = temp->getProx();
		}
		temp->setProx(elemento);
	}
}

void Lista::insertarPosEspecifica(int pos, Elemento * elemento){
	if (pos == 0){
		eliminarInicial();
	}
	else{
		Elemento * temp = cabeza;
		/*Si el tamaño de la lista es menor a la posición
		 *indicada, entonces se reasigna la posición para
		 *que se inserte al final */
		int tam = getListaTam();
		if (pos > tam){ pos = tam; }
		for (int i = 1; i < pos; i++){
			temp = temp->getProx();
		}
		elemento->setProx(temp->getProx());
		temp->setProx(elemento);
	}
}

void Lista::eliminarInicial(){
	Elemento * tmp = cabeza;
	if (cabeza != NULL){
		cabeza = cabeza->getProx();
	}
	delete tmp;
}

void Lista::eliminarFinal(){
	if (cabeza != NULL) {
		Elemento * anterior = cabeza;
		Elemento * actual = cabeza;
		while (actual->getProx() != NULL) {
			anterior = actual;
			actual = actual->getProx();
		}
		anterior->setProx(NULL);
		delete actual;
	}
}

void Lista::eliminarPosEspecifica(int pos){
	if (pos == 0){
		cabeza = cabeza->getProx();
	}
	else{
		Elemento *temp = cabeza;
		/*Si el tamaño de la lista es menor a la posición
		*indicada, entonces se reasigna la posición para
		*que se elimine el elemento final */
		int tam = getListaTam();
		if (pos > tam){ pos = tam; }

		for (int i = 1; i < pos; i++){
			temp = temp->getProx();
		}
		Elemento * tmp2 = temp->getProx();
		temp->setProx(temp->getProx()->getProx());
		delete tmp2;
	}
}

int Lista::getListaTam(){
	Elemento *temp = cabeza;
	int tam = 1;
	while (temp->getProx() != NULL){
		temp = temp->getProx();
		tam++;
	}
	return tam;
}

Elemento * Lista::getCabeza(){
	return this->cabeza;
}
ostream & operator<<(ostream & out, Lista & a) {
	a.imprimir(a.cabeza, out);
	return out;
}

void Lista::imprimir(Elemento* nodo, ostream& out) {
	if (nodo->getProx() != NULL) {
		out << *nodo << "->";
		imprimir(nodo->getProx(), out);
	}
}
