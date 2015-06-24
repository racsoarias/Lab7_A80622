#include "stdafx.h"
#include "DoublyLinkedList.h"

ostream & operator<<(ostream & out, DoublyLinkedList & a) {
	a.imprimir(a.head, out);
	return out;
}