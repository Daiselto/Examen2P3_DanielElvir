#pragma once
#include <string>
#include <vector>
#include "Apunte.h"
using namespace std;
class Curso {
	string Nombre;
	vector<Apunte*> apuntes;
public:
	Curso();
	Curso(string _nombre);
	~Curso();
	string getNombre();
	void setNombre(string _nombre);
	void agregarAlVector(Apunte* _apunte);
};

