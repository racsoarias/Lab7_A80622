#pragma once

using namespace std;

class Persona {

	friend ostream & operator<<(ostream &, Persona &);

	template <class T>
	friend class Nodo;

private:
	string nombre;
	int id;
	Persona();

public:
	Persona(string, int);
	~Persona();

	bool operator<(Persona &);
	bool operator>(Persona &);

};

ostream & operator<<(ostream &, Persona &);

