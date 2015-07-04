#pragma once
#include "stdafx.h"
#include "Iterador.h"
#include "IteradorInverso.h"
#include "Nodo.h"

using namespace std;

template<class T>
class DoublyLinkedList{

	template<class T>
	friend ostream & operator<<(ostream &, DoublyLinkedList<T> &);

public:
	Nodo<T> * head;
	Nodo<T> * tail;

	DoublyLinkedList(){
		head = NULL;
		tail = NULL;
	}
	virtual ~DoublyLinkedList(){
	}

	void addLast(T elemento){
		Nodo<T> * nodo = new Nodo<T>(elemento);
		if (head == NULL){
			head = nodo;
			tail = nodo;
		}
		else{
			tail->next = nodo;
			nodo->prev = tail;
			tail = nodo;
		}
	}


	void addFirst(T elemento){
		Nodo<T> * nodo = new Nodo<T>(elemento);
		if (head == NULL){
			head = nodo;
			tail = nodo;
		}
		else{
			head->prev = nodo;
			nodo->next = head;
			head = nodo;
		}
	}

	void addAnyPos(T elemento, int pos){
		Nodo<T> * nodo = new Nodo<T>(elemento);
		if (head == NULL || pos == 0){
			addFirst(elemento);
		}
		else if (pos >= sizeLinkedList()){
			if (pos > sizeLinkedList()){
				cout << "Position is outside the range, adding as last" << endl;
			}
			addLast(elemento);
		}
		else{
			Nodo<T> * temp = head;
			for (int i = 0; i < pos; i++){
				temp = temp->next;
			}
			nodo->next = temp;
			nodo->prev = temp->prev;
			nodo->prev->next = nodo;
			temp->prev = nodo;
		}
	}

	int sizeLinkedList(){
		int size = 1;
		Nodo<T> * temp = head;
		while (temp->next != NULL){
			temp = temp->next;
			size++;
		}
		//delete temp;
		return size;
	}

	void removeFirst(){
		Nodo<T> * tmp = head;
		if (head != NULL){
			head = head->next;
			head->prev = NULL;
		}
		delete tmp;
	}

	void removeLast(){
		Nodo<T> * temp = tail;
		if (tail != NULL) {
			tail = tail->prev;
			tail->next = NULL;
		}
		delete temp;
	}

	void removeAnyPos(int pos){
		if (pos == 0){
			removeFirst();
		}
		else if (pos >= sizeLinkedList()){
			if (pos > sizeLinkedList()){
				cout << "Position is outside the range, removing the last" << endl;
			}
			removeLast();
		}
		else{
			Nodo<T> * temp = head;
			for (int i = 1; i < pos; i++){
				temp = temp->next;
			}
			Nodo<T> * tmp2 = temp->next;
			temp->next = temp->next->next;
			temp->next->prev = temp;
			delete tmp2;
		}
	}


	void imprimir(Nodo<T>* nodo, ostream& out) {
		if (nodo != NULL) {
			out << nodo->actual;
			if (nodo->next != NULL){
				out << "->";
			}			
			imprimir(nodo->next, out);
		}
	}

	Iterador<T> begin() {
		return Iterador<T>(head);
	}

	Iterador<T> end() {
		return Iterador<T>(NULL);
	}

	IteradorInverso<T> rBegin() {
		return IteradorInverso<T>(tail);
	}

	IteradorInverso<T> rEnd() {
		return IteradorInverso<T>(NULL);
	}

};

template<class T>
ostream & operator<<(ostream & out, DoublyLinkedList<T> & a) {
	a.imprimir(a.head, out);
	return out;
}