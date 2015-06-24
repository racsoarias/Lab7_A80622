#pragma once

using namespace std;

class Persona{

protected:
	int id;
	string nombre;

public:
	Persona(int, string);
	virtual ~Persona();
	int getID();
	string getNombre();	
	void setID(int);
	void setNombre(string);
};

