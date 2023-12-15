#include <iostream>
#include <locale>
#include <fstream>
#include "Curso.h"
#include "Apunte.h"
using namespace std;

static vector<Curso*> cursos;
Curso* curso;
Apunte* apunte;
Apunte* nApunte;

void crearCursos() {
	cout << endl;
	string nombre;
	cout << "Bienvenido a la opción de crear cursos" << endl;
	cout << endl;
	cout << "Ingrese el nombre del curso que está llevando: ";
	cin >> nombre;
	curso = new Curso(nombre);
	cursos.push_back(curso);
}

void listarCursos() {
	if (cursos.size()>0) {
		cout << endl;
		int i = 0;
		cout << "Cursos guardados" << endl;
		for (Curso* uwu : cursos) {
			cout << i << ". " << uwu->getNombre() << endl;
			i++;
		}
		cout << endl;
	} else {
		cout << "Tiene que crear un curso primero" << endl;
	}	
}

void eliminarCursos() {
	if (cursos.size()>0) {
		int indice;
		cout << endl;
		cout << "Elija un curso a eliminar" << endl;
		listarCursos();
		cout << "Escoja el curso que desea eliminar: ";
		cin >> indice;
		if (indice>=0&&indice<cursos.size()) {
			delete cursos[indice];
			cursos.erase(cursos.begin() + indice);
			cout << "Eliminado exitosamente" << endl;
			cout << endl;
		} else {
			cout << "Ese indice no existe" << endl;
			cout << endl;
		}
	} else {
		cout << "Tiene que crear un curso primero" << endl;
		cout << endl;
	}
}

void submenuCurso() {
	int opcion;
	bool seguir = true;
	while (seguir){
		cout << "---- MENU Curso ----" << endl;
		cout << "1. Crear Curso" << endl;
		cout << "2. Listar Cursos" << endl;
		cout << "3. Eliminar Cursos" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese una opcion valida: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			crearCursos();
			break;
		case 2:
			listarCursos();
			break;
		case 3:
			eliminarCursos();
			break;
		case 4:
			cout << "Volviendo al menu principal..." << endl;
			cout << endl;
			seguir = false;
			break;
		default:
			cout << "ERROR\nINGRESE UNA OPCION VALIDA" << endl;
			break;
		}
	}
		
		
}

void crearApunte() {
	if (cursos.size()>0) {
		int indice;
		string titulo;
		string contenido;
		string fecha;
		cout << endl;
		cout << "Crear Apunte" << endl;
		listarCursos();
		cout << "Ingrese la posición del curso para agregar el apunte: ";
		cin >> indice;
		if (indice >= 0 && indice < cursos.size()) {
			cout << "Ingrese el titulo del apunte: ";
			cin >> titulo;
			cout << "Ingrese el contenido del apunte: ";
			cin >> contenido;
			cout << "Ingrese la fecha del apunte: ";
			cin >> fecha;
			apunte = new Apunte(titulo, contenido, fecha);
			cursos[indice]->agregarAlVector(apunte);
			cout << "Apunte agragado correctamente en la clase " << cursos[indice]->getNombre() << endl;
			cout << endl;
		}
		else {
			cout << "ERROR" << endl;
			cout << "Ese curso no existe" << endl;
			cout << endl;
		}
	} else {
		cout << "Debe crear cursos primero" << endl;
		cout << endl;
	}
}

void listarApuntes() {
	int indice;
	listarCursos();
	cout << "Ingrese la posición del curso para listar los apuntes: ";
	cin >> indice;
	if (indice >= 0 && indice < cursos.size()) {
		cursos[indice]->listarEstosApuntes();
	}
	else {
		cout << "Ese valor no existe entre los cursos" << endl;
	}
}

void eliminarApuntes() {
	int indice;
	int indice1;
	listarCursos();
	cout << "Ingrese la posición del curso para eliminar los apuntes: ";
	cin >> indice;
	if (indice >= 0 && indice < cursos.size()) {
		cursos[indice]->listarEstosApuntes();
		cout << "Ingrese el apunte que desea eliminar: ";
		cin >> indice1;
		if (indice1>=0&&indice1<cursos[indice]->getVector().size()) {
			cursos[indice]->elimnarApunteEnClase(indice1);
		}
	}
	else {
		cout << "Ese valor no existe entre los cursos" << endl;
	}
}

void combinarApuntes() {
	int indice;
	int apunte1;
	int apunte2;
	string nFecha;
	string nTitulo;
	string nContenido;
	listarCursos();
	cout << "Selecciona el curso (posicion): ";
	cin >> indice;
	if (indice >= 0 && indice < cursos.size()) {
		cursos[indice]->listarEstosApuntes();
		cout << "Seleccione el primer apunte: ";
		cin >> apunte1;
		cout << "Seleccione el segundo apunte: ";
		cin >> apunte2;
		if ((apunte1>=0&&apunte1< cursos[indice]->getVector().size())&&(apunte2 >= 0 && apunte2 < cursos[indice]->getVector().size())) {
			cout << "Ingrese la fecha del apunte combinado: ";
			cin >> nFecha;
			nTitulo = cursos[indice]->getVector()[apunte1]->getTitulo() + " + " + cursos[indice]->getVector()[apunte2]->getTitulo();
			nContenido = cursos[indice]->getVector()[apunte1]->getContenido() + " + " + cursos[indice]->getVector()[apunte2]->getContenido();
			nApunte = new Apunte(nTitulo, nContenido, nFecha);
			cursos[indice]->agregarAlVector(nApunte);
			cursos[indice]->elimnarApunteEnClase(apunte1);
			cursos[indice]->elimnarApunteEnClase(apunte2);
		}
	}
}

void submenuApuntes() {
	if (cursos.size() > 0) {
		int opcion;
		bool seguir = true;
		while (seguir) {
			cout << "---- MENU Apunte ----" << endl;
			cout << "1. Crear Apunte" << endl;
			cout << "2. Listar Apuntes" << endl;
			cout << "3. Eliminar Apuntes" << endl;
			cout << "4. Combinar Apuntes" << endl;
			cout << "5. Salir" << endl;
			cout << "Ingrese una opcion valida: ";
			cin >> opcion;
			switch (opcion) {
			case 1:
				crearApunte();
				break;
			case 2:
				listarApuntes();
				break;
			case 3:
				eliminarApuntes();
				break;
			case 4:
				combinarApuntes();
				break;
			case 5:
				cout << "Volviendo al menu principal..." << endl;
				cout << endl;
				seguir = false;
				break;
			default:
				cout << "ERROR\nINGRESE UNA OPCION VALIDA" << endl;
				break;
			}
		}
	}
	else {
		cout << "Tiene que agregar cursos primero" << endl;
	}			
}

void guardarArchivo() {
	ofstream archivoGuardar("Apuntes.die", ios::binary);
	if (archivoGuardar.is_open()) {
		for (const Curso* cur : cursos) {
			archivoGuardar.write(reinterpret_cast<const char*>(&cur), sizeof(Curso));
		}
		archivoGuardar.close();
	}
	else {
		cerr << "No se pudo abrir el archivo para escritura." << endl;
	}
}

void cargarArchivo() {
	ifstream archivoEntrada("Apuntes.die", ios::binary);
	if (archivoEntrada.is_open()) {
		while (!archivoEntrada.eof()) {
			Curso* man;
			archivoEntrada.read(reinterpret_cast<char*>(&man), sizeof(Curso));
			if (!archivoEntrada.eof()) {
				cursos.push_back(man);
			}
		}
		archivoEntrada.close();
	}
	else {
		cerr << "No se pudo abrir el archivo para lectura." << endl;
	}
}

void menu() {
	bool seguir=true;
	int opcion;
	do {
		cout << "---- MENU ----" << endl;
		cout << "1. Operaciones Curso" << endl;
		cout << "2. Operaciones Apuntes" << endl;
		cout << "3. Guardar Archivo" << endl;
		cout << "4. Cargar Archivo" << endl;
		cout << "5. Salir" << endl;
		cout << "Ingrese una opción valida: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			submenuCurso();
			break;
		case 2:
			submenuApuntes();
			break;
		case 3:
			guardarArchivo();
			break;
		case 4:
			cargarArchivo();
			break;
		case 5:
			cout << "Saliendo..." << endl;
			cout << endl;
			seguir = false;
			break;
		default:
			cout << "ERROR" << endl;
			cout << "Ingrese un valor correcto" << endl;
			cout << endl;
			break;
		}
	} while (seguir);
	

}

int main() {
	setlocale(LC_ALL, "spanish");
	menu();
}
