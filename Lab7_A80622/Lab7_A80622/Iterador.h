#pragma once
#include "Nodo.h"

template<class T>
class Iterador{
private:
	Nodo<T> * actual;

public:

	Iterador(Nodo<T> * actual){
		this->actual = actual;
	}

	~Iterador(){
	}

	// Preincremento
	Iterador<T>& operator++() {
		this->actual = this->actual->next;
		return *this;
	}

	// Posincremento
	Iterador<T> operator++(int) {
		Iterador<T> tmp(this->actual);
		++(*this);
		return tmp;
	}

	T operator*() {
		return actual->actual;
	}

	bool operator!=(Iterador<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(Iterador<T> & otro) {
		return this->actual == otro.actual;
	}

};