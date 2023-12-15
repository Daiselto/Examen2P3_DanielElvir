#pragma once
#include <string>
using namespace std;
class Apunte {
	string titulo;
	string contenido;
	string fecha;
public:
	Apunte();
	Apunte(string _titulo, string _contenido, string _fecha);
	~Apunte();
	string getTitulo();
	void setTitulo(string _titulo);
	string getContenido();
	void setContenido(string _contenido);
	string getFecha();
	void setFecha(string _fecha);
};

