#include "stdafx.h"
#include "ElementoPersona.h"


ElementoPersona::ElementoPersona(Persona * p) : persona(p){
}

ElementoPersona::~ElementoPersona(){
	delete persona;
}

int ElementoPersona::compareTo(Elemento * otro) {
	int cmp = 0;
	ElementoPersona * eInt = dynamic_cast<ElementoPersona *>(otro);
	if (eInt != 0) {
		cmp = this->persona->getID() < eInt->persona->getID() ? -1 : this->persona->getID() == eInt->persona->getID() ? 0 : 1;
	}
	return cmp;
}

void ElementoPersona::imprimir(ostream& out) const {
	out << this->persona->getID();
}