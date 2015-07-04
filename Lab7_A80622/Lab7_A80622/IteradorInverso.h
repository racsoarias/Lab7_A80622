#pragma once
#include "Nodo.h"

template<class T>
class IteradorInverso{
private:
	Nodo<T> * actual;

public:

	IteradorInverso(Nodo<T> * actual){
		this->actual = actual;
	}

	~IteradorInverso(){
	}

	// Predecremento
	IteradorInverso<T>& operator--() {
		this->actual = this->actual->prev;
		return *this;
	}

	// Posdecremento
	IteradorInverso<T> operator--(int) {
		IteradorInverso<T> tmp(this->actual);
		--(*this);
		return tmp;
	}

	T operator*() {
		return actual->actual;
	}

	bool operator!=(IteradorInverso<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(IteradorInverso<T> & otro) {
		return this->actual == otro.actual;
	}

};