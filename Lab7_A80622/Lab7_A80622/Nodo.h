#pragma once

template<class T>
class Nodo {

	template <class T>
	friend class DoublyLinkedList;
	
	template <class T>
	friend class Iterador;
	
	template <class T>
	friend class IteradorInverso;
	
private:
	T actual;
	Nodo<T> *next, *prev;

public:
	Nodo(T elemento) {
		this->actual = elemento;
		next = NULL;
		prev = NULL;
	}

	~Nodo() {
	}
};
