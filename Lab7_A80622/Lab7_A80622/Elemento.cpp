
#include "stdafx.h"
#include "Elemento.h"

Elemento::Elemento() {
	hijoIzq = NULL;
	hijoDer = NULL;
	prox = NULL;
	next = NULL;
	prev = NULL;
}

Elemento::~Elemento() {
}

Elemento * Elemento::getHijoIzq() {
	return hijoIzq;
}

Elemento * Elemento::getHijoDer() {
	return hijoDer;
}

Elemento * Elemento::getProx() {
	return prox;
}
Elemento * Elemento::getNext() {
	return next;
}
Elemento * Elemento::getPrev() {
	return prev;
}

void Elemento::setHijoIzq(Elemento * e) {
	this->hijoIzq = e;
}

void Elemento::setHijoDer(Elemento * e) {
	this->hijoDer = e;
}

void Elemento::setProx(Elemento * e) {
	this->prox = e;
}

void Elemento::setNext(Elemento * e) {
	this->next = e;
}

void Elemento::setPrev(Elemento * e) {
	this->prev = e;
}

ostream & operator<<(ostream & out, const Elemento & e) {
	e.imprimir(out);
	return out;
}

bool Elemento::operator <(Elemento& otro) {
	return this->compareTo(&otro) < 0;
}

bool Elemento::operator <=(Elemento& otro) {
	return this->compareTo(&otro) <= 0;
}

bool Elemento::operator >(Elemento& otro) {
	return this->compareTo(&otro) > 0;
}

bool Elemento::operator >=(Elemento& otro) {
	return this->compareTo(&otro) >= 0;
}
