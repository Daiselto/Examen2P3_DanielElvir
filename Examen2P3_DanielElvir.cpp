#include <iostream>
#include <locale>
#include "Curso.h"
#include "Apunte.h"
using namespace std;

static vector<Curso*> cursos;
Curso* curso;

void crearCursos() {
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
		int i = 0;
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

void submenuApuntes() {
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
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
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

			break;
		case 4:
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
