#include <iostream>

#include <fstream>
#include <string>
using namespace std;

string nombre, apellido;

int edad;

void anadircontactos();
void mostrarcontactos();
void menu();

int main()
{
	int opcion;
	ofstream archivo;
	archivo.open("contactos.txt", ios::out);
	menu();
	cin >> opcion;
	while (opcion != 0)
	{
		switch (opcion) {
		case 1:
		{
			anadircontactos();
			break;
		}

		case 2:
		{
			mostrarcontactos();
			break;
		}

		}

		menu();
		cin >> opcion;
		cout << endl;
	}

}

void anadircontactos()
{
	int edad;
	ofstream archivo;
	string eleccion;
	cin.ignore();
	do
	{
		cout << "Ingrese el nombre: " << endl;
		getline(cin, nombre);
		cout << "Ingrese el apellido: " << endl;
		getline(cin, apellido);
		cout << "Ingrese la edad: " << endl;
		cin >> edad;
		cout << endl;
		archivo << nombre << " " << apellido << " " << edad << endl;
		cout << "Desea ingresar otro contacto (s/n): ";
		cin >> eleccion;
		cin.ignore();
	} while (eleccion == "s");
	archivo.close();
}
