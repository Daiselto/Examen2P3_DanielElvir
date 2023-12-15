#include <iostream>
#include <locale>
#include <fstream>
#include "Curso.h"
#include "Apunte.h"
using namespace std;

//variables que se usan en todo el programa
static vector<Curso*> cursos;
Curso* curso;
Apunte* apunte;

//Crea los cursos y los manda directamente al vector
void crearCursos() {
	cout << endl;
	string nombre;
	cout << "Bienvenido a la opción de crear cursos" << endl;
	cout << endl;
	cout << "Ingrese el nombre del curso que está llevando: ";
	cin.ignore();
	getline(cin, nombre);
	curso = new Curso(nombre);
	cursos.push_back(curso);
}

//lista los cursos dentro del vector
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

//elimina cursos dentro del vector
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

//El menu que sale a la hora de entrar a las operaciones de curso
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

//Crea los apuntes y los manda al vector de la clase Curso
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
			cin.ignore();
			getline(cin, titulo);
			cout << "Ingrese el contenido del apunte: ";
			getline(cin, contenido);
			cout << "Ingrese la fecha del apunte: ";
			getline(cin, fecha);
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

//lista los apuntes dependiendo del curso seleccionado
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

//elimina el apunte seleccionado dentro del curso seleccionado
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
			cout << "Eliminado exitosamente" << endl;
		}
	}
	else {
		cout << "Ese valor no existe entre los cursos" << endl;
	}
}

//agarra 2 apuntes de un curso y los vuelve uno solo, quitandolos del vector y agregando el nuevo
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
			Apunte* ap1 = cursos[indice]->getVector().at(apunte1);
			Apunte* ap2 = cursos[indice]->getVector().at(apunte2);
			cout << "Ingrese la fecha del apunte combinado: ";
			cin.ignore();
			getline(cin, nFecha);
			nTitulo=ap1->getTitulo() + " + " + ap2->getTitulo();
			nContenido=ap1->getContenido() + " + " + ap2->getContenido();
			Apunte* nApunte = new Apunte(nTitulo, nContenido, nFecha);
			if (apunte1 > apunte2) {
				cursos[indice]->agregarAlVector(nApunte);
				cursos[indice]->elimnarApunteEnClase(apunte1);
				cursos[indice]->elimnarApunteEnClase(apunte2);
			}
			else if (apunte2 > apunte1) {
				cursos[indice]->agregarAlVector(nApunte);
				cursos[indice]->elimnarApunteEnClase(apunte2);
				cursos[indice]->elimnarApunteEnClase(apunte1);
			}
				
			//cursos[indice]->elimnarApunteEnClase(apunte1);
			//cursos[indice]->elimnarApunteEnClase(apunte2);
		}
		else {
			cout << "Esos apuntes no existen en la clase" << endl;
		}
	}
	else {
		cout << "Ese curso no existe" << endl;
	}
}

//submenu que sale a la hora de escoger la operacion apuntes
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

//metodo para guardar archivos en el binario 
void guardarArchivo() {
	cout << "Guardar archivo" << endl;
	ofstream archivoGuardar("Apuntes.die", ios::binary);	
	if (archivoGuardar.is_open()) {
		size_t cantidad = cursos.size();
		archivoGuardar.write((char*)(&cantidad), sizeof(cursos.size()));
		for (int i = 0; i < cursos.size(); i++) {
			size_t nombre = cursos[i]->getNombre().size();			
			archivoGuardar.write((char*)(&nombre), sizeof(string));
			for (int j = 0; j < cursos[i]->getVector().size(); j++) {
				size_t titulo = cursos[i]->getVector().at(j)->getTitulo().size();
				size_t contenido = cursos[i]->getVector().at(j)->getContenido().size();
				size_t fecha = cursos[i]->getVector().at(j)->getFecha().size();
				archivoGuardar.write((char*)(&titulo), sizeof(string));
				archivoGuardar.write((char*)(&contenido), sizeof(string));
				archivoGuardar.write((char*)(&fecha), sizeof(string));
			}
		}
		cout << "Guardado exitosamente" << endl;
		cout << endl;
		archivoGuardar.close();
	}
	else {
		cerr << "No se pudo abrir el archivo para escritura." << endl;
	}
}

//lee los archivos y los manda al vector
void cargarArchivo() {
	/*ifstream archivoEntrada("Apuntes.die", ios::binary);
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
	}*/
	Curso* a;
	Apunte* n;
	cout << "Cargar Archivo" << endl;
	ifstream archivoGuardar("Apuntes.die", ios::binary);
	if (archivoGuardar.is_open()) {
		
		size_t cantidad = cursos.size();
		archivoGuardar.read((char*)(&cantidad), sizeof(cursos.size()));

		for (int i = 0; i < cursos.size(); i++) {
			size_t nombre = cursos[i]->getNombre().size();
			a->setNombre((string*)nombre);
			archivoGuardar.read((char*)(&nombre), sizeof(string));
			archivoGuardar.read((char*)(&a), sizeof(Curso));
			cursos.push_back(a);
			for (int j = 0; j < cursos[i]->getVector().size(); j++) {
				size_t titulo = cursos[i]->getVector().at(j)->getTitulo().size();
				size_t contenido = cursos[i]->getVector().at(j)->getContenido().size();
				size_t fecha = cursos[i]->getVector().at(j)->getFecha().size();
				archivoGuardar.read((char*)(&titulo), sizeof(string));
				archivoGuardar.read((char*)(&contenido), sizeof(string));
				archivoGuardar.read((char*)(&fecha), sizeof(string));
				archivoGuardar.read((char*)(&n), sizeof(Apunte));
				cursos.push_back(a);
			}
		}
		cout << "Cargado exitosamente (no)" << endl;
		cout << endl;
		archivoGuardar.close();
	}
	else {
		cerr << "No se pudo abrir el archivo para escritura." << endl;
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
			//guarda el archivo a la hora de salir por si acaso
			guardarArchivo();
			//borra memoria del vector
			for (int i = 0; i < cursos.size(); i++) {
				delete cursos[i];
			}
			//borra memoria de las variables generales
			delete curso;
			delete apunte;
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
	//para que salgan tildes en consola
	setlocale(LC_ALL, "spanish");
	//llamado a la funcion que tiene todo el programa
	menu();
}
