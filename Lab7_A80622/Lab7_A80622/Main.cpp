#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "Persona.h"

using namespace std;

template<class T>
void imprimir(DoublyLinkedList<T> lista);

int _tmain(int argc, _TCHAR* argv[]){
	
	DoublyLinkedList<int> a;
	for (int i = 0; i < 5; i++){
		a.addFirst(i+1);
		a.addLast((i+1) * 10);
	}	
	a.addAnyPos(100, 5);
	cout << "Lista Original:\n" << a << endl;

	a.removeFirst();
	a.removeLast();
	a.removeAnyPos(4);
	cout << "Lista modificada:\n" << a << endl;

	DoublyLinkedList<double> b;
	for (int i = 0; i < 5; i++){
		b.addFirst(i*2.3);
		b.addLast(i*20.3);
	}
	b.addAnyPos(125.5, 5);
	cout << "\nLista Original:\n" << b << endl;

	b.removeFirst();
	b.removeLast();
	b.removeAnyPos(4);
	cout << "Lista modificada:\n" << b << endl;

	DoublyLinkedList<char> c;
	for (int i = 0; i < 5; i++){
		c.addFirst(i + 97);
		c.addLast(i + 65);
	}
	c.addAnyPos('X', 5);
	cout << "\nLista Original:\n" << c << endl;

	c.removeFirst();
	c.removeLast();
	c.removeAnyPos(4);
	cout << "Lista modificada:\n" << c << endl;

	DoublyLinkedList<Persona> d;
	Persona p1("Andy", 1000);
	Persona p2("Faby", 2000);
	Persona p3("Hele", 3000);
	Persona p4("Lora", 3000);
	Persona p5("Joha", 3000);
	Persona p6("Cora", 3000);
	Persona p7("Zara", 3000);
	d.addFirst(p2); 
	d.addFirst(p6);
	d.addFirst(p7);
	d.addLast(p1);	
	d.addAnyPos(p3,2);
	d.addLast(p4);
	d.addAnyPos(p5,0);
	cout << "\nLista Original:\n" << d << endl;

	d.removeFirst();
	d.removeLast();
	d.removeAnyPos(3);
	cout << "Lista modificada:\n" << d << endl; 

	//Iteradores
	imprimir(a);
	imprimir(b);
	imprimir(c);
	imprimir(d);

	system("pause");
	return 0;
}

template<class T>
void imprimir(DoublyLinkedList<T> lista) {

	cout << "\n\nPreincremento" << endl;
	// Probar Iteradores preincremento
	Iterador<T> itA = lista.begin();
	while (itA != lista.end()) {
		cout << *itA << "->";
		++itA;
	}
	cout << endl;

	cout << "Posincremento" << endl;
	// Probar Iteradores posincremento
	Iterador<T> itB = lista.begin();
	while (itB != lista.end()) {
		cout << *(itB++) << "->";
	}
	cout << endl;

	cout << "Predecremento" << endl;
	// Probar Iteradores predecremento
	IteradorInverso<T> itC = lista.rBegin();
	while (itC != lista.rEnd()) {
		cout << *itC << "->";
		--itC;
	}
	cout << endl;

	cout << "Posdecremento" << endl;
	// Probar Iteradores posdecremento
	IteradorInverso<T> itD = lista.rBegin();
	while (itD != lista.rEnd()) {
		cout << *(itD--) << "->";
	}
	cout << endl;
}


