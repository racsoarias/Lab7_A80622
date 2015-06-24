#pragma once

using namespace std;

class Elemento {

	friend ostream & operator<<(ostream &, const Elemento &);

protected:
	Elemento();
	Elemento *hijoIzq, *hijoDer;
	Elemento *prox;
	Elemento *next, *prev;

public:

	Elemento * getHijoIzq();
	Elemento * getHijoDer();
	void setHijoIzq(Elemento *);
	void setHijoDer(Elemento *);
	Elemento * getProx();
	void setProx(Elemento *);
	Elemento * getNext();
	void setNext(Elemento *);
	Elemento * getPrev();
	void setPrev(Elemento *);

	virtual ~Elemento();
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;

	bool operator<(Elemento &);
	bool operator<=(Elemento &);
	bool operator>(Elemento &);
	bool operator>=(Elemento &);

};

ostream & operator<<(ostream &, const Elemento &);
