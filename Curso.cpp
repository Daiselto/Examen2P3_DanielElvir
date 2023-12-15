#include "Curso.h"

Curso::Curso()
{
}

Curso::Curso(string _nombre) {
	this->Nombre = _nombre;
}

Curso::~Curso()
{
}

string Curso::getNombre() {
	return this->Nombre;
}

void Curso::setNombre(string _nombre) {
	this->Nombre = _nombre;
}

void Curso::agregarAlVector(Apunte* _apunte) {
	apuntes.push_back(_apunte);
}
