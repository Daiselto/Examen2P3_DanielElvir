#include "Apunte.h"

Apunte::Apunte()
{
}

Apunte::Apunte(string _titulo, string _contenido, string _fecha) {
	this->titulo = _titulo;
	this->contenido = _contenido;
	this->fecha = _fecha;
}

Apunte::~Apunte()
{
}

string Apunte::getTitulo() {
	return this->titulo;
}

void Apunte::setTitulo(string _titulo) {
	this->titulo = _titulo;
}

string Apunte::getContenido() {
	return this->contenido;
}

void Apunte::setContenido(string _contenido) {
	this->contenido = _contenido;
}

string Apunte::getFecha() {
	return this->fecha;
}

void Apunte::setFecha(string _fecha) {
	this->fecha = _fecha;
}
