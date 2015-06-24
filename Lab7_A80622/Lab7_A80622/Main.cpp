#include "stdafx.h"
#include "ArbolBinario.h"
#include "Lista.h"
#include "Pila.h"
#include "Elemento.h"
#include "ElementoInt.h"
#include "ElementoIntInt.h"
#include "ElementoDouble.h"
#include "ElementoPersona.h"
#include "DoublyLinkedList.h"

int _tmain(int argc, _TCHAR* argv[]){

	DoublyLinkedList a;

	for (int i = 0; i < 10; i++){
		a.addLast(new ElementoInt(i));
		a.addFirst(new ElementoInt((i+10)));
	}
	cout << a << endl;

	system("pause");
	return 0;
}


