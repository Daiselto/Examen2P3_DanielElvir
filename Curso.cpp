#include "Curso.h"
#include <iostream>

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

vector<Apunte*> Curso::getVector()
{
	return this->apuntes;
}

void Curso::setNombre(string _nombre) {
	this->Nombre = _nombre;
}

void Curso::agregarAlVector(Apunte* _apunte) {
	apuntes.push_back(_apunte);
}

void Curso::listarEstosApuntes() {
	cout << endl;
	int i = 0;
	cout << "Apuntes guardados en el curso " << this->Nombre << endl;
	for (Apunte* uwu : apuntes) {
		cout << i << ". Titulo: " << uwu->getTitulo() << endl;
		cout << "Contenido: " << uwu->getContenido() << endl;
		cout << "Fecha: " << uwu->getFecha() << endl;
		i++;
	}
	cout << endl;
}

void Curso::elimnarApunteEnClase(int indice) {
	delete apuntes[indice];
	apuntes.erase(apuntes.begin() + indice);
	cout << "Eliminado exitosamente" << endl;
	cout << endl;
}
