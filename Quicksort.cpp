#include <iostream>
#include<fstream>

using namespace std;

const int N = 100;
typedef int a[N];

typedef struct {
	a elementos;
	int cont;
} tLista;

void ingresar(tLista& lista);
int mitad(tLista& lista, int pinicial, int pfinal);
void ordenar(tLista& lista, int pinicial, int pfinal);
void mostrar(tLista& lista);
void guardar(tLista& lista, tLista &aux);

int main()
{
	tLista lista;
	tLista aux;
	ingresar(lista);
	cout << "ARREGLO ORIGINAL ES: " << endl;
	mostrar(lista);
	for (int i = 0; i < lista.cont; i++) {
		aux.elementos[i] = lista.elementos[i];
	}
	cout << endl;
	ordenar(lista, 0, lista.cont);
	cout << "ARREGLO ORDENADO ES: " << endl;
	mostrar(lista);
	guardar(lista, aux);
	return 0;
}

void ingresar(tLista& lista) {
	cout << "DIGITE EL TAMAÑO DEL ARREGLO: ";
	cin >> lista.cont;
	cout << "INGRESE LOS ELEMENTOS DEL ARREGLO: ";
	for (int i = 0; i < lista.cont; i++) {
		cin >> lista.elementos[i];
	}
}


int mitad(tLista& lista, int pinicial, int pfinal) {
	return lista.elementos[(pinicial + pfinal) / 2];
}

void ordenar(tLista& lista, int pinicial, int pfinal) {
	int i = pinicial;
	int j = pfinal;
	int temp;
	int piv = mitad(lista, pinicial, pfinal);

	do {
		while (lista.elementos[i] < piv) {
			i++;
		}
		while (lista.elementos[j] > piv) {
			j--;
		}
		if (i <= j) {
			temp = lista.elementos[i];
			lista.elementos[i] = lista.elementos[j];
			lista.elementos[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (pinicial < j) {
		ordenar(lista, pinicial, j);
	}
	if (i < pfinal) {
		ordenar(lista, i, pfinal);
	}

}

void mostrar(tLista& lista) {
	for (int i = 0; i < lista.cont; i++) {
		cout << "|" << lista.elementos[i] << "|";
	}
}

void guardar(tLista& lista, tLista &aux) {
	ofstream archivo;
	archivo.open("Ordenamiento.txt");
	archivo << "ARREGLO ORIGINAL ES: " << endl;
	for (int i = 0; i < lista.cont; i++) {
		archivo << aux.elementos[i] << " ";
	}
	archivo << endl;
	archivo << "ARREGLO ORDENADO ES: " << endl;
	for (int i = 0; i < lista.cont; i++) {
		archivo << lista.elementos[i] << " ";
	}
	archivo << endl;
	archivo.close();
}