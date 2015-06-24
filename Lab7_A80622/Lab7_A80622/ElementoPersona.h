#pragma once
#include "Elemento.h"
#include "Persona.h"

using namespace std;

class ElementoPersona : public Elemento {

private:
	Persona * persona;

public:
	ElementoPersona(Persona *);
	virtual ~ElementoPersona();
	virtual int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
};

