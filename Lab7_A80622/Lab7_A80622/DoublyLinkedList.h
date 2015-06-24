#pragma once
#include "stdafx.h"
#include "Elemento.h"

using namespace std;

class DoublyLinkedList{

	friend ostream & operator<<(ostream &, DoublyLinkedList &);

public:
	Elemento * head;
	Elemento * tail;

	DoublyLinkedList(){
		head = NULL;
		tail = NULL;
	}
	virtual ~DoublyLinkedList(){
	}

	void addLast(Elemento * nodo){
		if (head == NULL){
			head = nodo;
			nodo->setPrev(NULL);
		}
		else
		{
			Elemento * temp = head;
			while (temp->getNext() != NULL){
				temp = temp->getNext();
			}
			temp->setNext(nodo);
			nodo->setPrev(temp);
		}
	}

	void addFirst(Elemento * nodo){
		if (head == NULL){
			addLast(nodo);
		}
		else{
			head->setPrev(nodo);
			nodo->setNext(head);
			head = nodo;
		}
	}

	void DoublyLinkedList::imprimir(Elemento* nodo, ostream& out) {
		if (nodo->getNext() != NULL) {
			out << *nodo << "->";
			imprimir(nodo->getNext(), out);
		}
	}

};

ostream & operator<<(ostream &, DoublyLinkedList &);