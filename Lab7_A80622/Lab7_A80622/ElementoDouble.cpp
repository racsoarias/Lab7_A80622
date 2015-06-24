#include "stdafx.h"
#include "ElementoDouble.h"


ElementoDouble::ElementoDouble(double d){
	this->d = d;
}


ElementoDouble::~ElementoDouble(){
}

int ElementoDouble::compareTo(Elemento * otro) {
	int cmp = 0;
	ElementoDouble * eInt = static_cast<ElementoDouble *>(otro);
	if (eInt != 0) {
		cmp = this->d < eInt->d ? -1 : this->d == eInt->d ? 0 : 1;
	}
	return cmp;
}

void ElementoDouble::imprimir(ostream& out) const {
	out << d;
}
