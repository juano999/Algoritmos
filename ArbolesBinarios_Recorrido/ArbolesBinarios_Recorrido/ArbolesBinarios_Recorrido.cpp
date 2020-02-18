
#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* derecho;
    Nodo* izquierdo;
};

Nodo* crearNodoPadresHijos(int n);
Nodo* arbolbinario = NULL;

void InsertarNodosEnArbolBinario(Nodo*& arbolbinario, int n);
void mostrarArbolBinario(Nodo*& arbolbinario, int separador);
void preOrden(Nodo*& arbolbinario);
void inOrden(Nodo*& arbolbinario);
void postOrden(Nodo*& arbolbinario);

int main()
{
    int n;
    for (int i = 0; i < 7; i++) {
        cout << "INSERTAR NODOS: ";
        cin >> n;
        InsertarNodosEnArbolBinario(arbolbinario, n);
    }
    mostrarArbolBinario(arbolbinario, 0);
    cout << " PREORDEN: " << endl;
    preOrden(arbolbinario);
    cout << endl;
    cout << " INORDEN: " << endl;
    inOrden(arbolbinario);
    cout << endl;
    cout << "POSTORDEN: " << endl;
    postOrden(arbolbinario);
    cout << endl;
    return 0;
}

Nodo* crearNodoPadresHijos(int n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->derecho = NULL;
    nuevo->izquierdo = NULL;
    return nuevo;
}

void InsertarNodosEnArbolBinario(Nodo*& arbolbinario, int n) {
    if (arbolbinario == NULL) {
        Nodo* nuevo = crearNodoPadresHijos(n);
        arbolbinario = nuevo;
    }
    else {
        int datoRaiz = arbolbinario->dato;
        if (n < datoRaiz) {
            InsertarNodosEnArbolBinario(arbolbinario->izquierdo, n);
        }
        else {
            InsertarNodosEnArbolBinario(arbolbinario->derecho, n);
        }
    }
}

void mostrarArbolBinario(Nodo*& arbolbinario, int separador) {
    if (arbolbinario == NULL) {
        return;
    }
    else {
        mostrarArbolBinario(arbolbinario->derecho, separador + 1);
        
        for (int i = 0; i < separador; i++) {
            cout << " ";
        }
        cout << arbolbinario->dato << endl;
        mostrarArbolBinario(arbolbinario->izquierdo, separador + 1);
    }
}

void preOrden(Nodo*& arbolbinario) {
    if (arbolbinario == NULL) {
        return;
    }
    else {
        cout << arbolbinario->dato << " - ";
        preOrden(arbolbinario->izquierdo);
        preOrden(arbolbinario->derecho);
    }
}

void inOrden(Nodo*& arbolbinario) {
    if (arbolbinario == NULL) {
        return;
    }
    else {
        inOrden(arbolbinario->izquierdo);
        cout << arbolbinario->dato << " - ";
        inOrden(arbolbinario->derecho);
    }
}

void postOrden(Nodo*& arbolbinario) {
    if (arbolbinario == NULL) {
        return;
    }
    else {
        postOrden(arbolbinario->izquierdo);
        postOrden(arbolbinario->derecho);
        cout << arbolbinario->dato << " - ";
    }
}


