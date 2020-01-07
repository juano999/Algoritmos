#include <iostream>

using namespace std;
#include <fstream>
void anadir(int a[], int &dato, int longitud);
void imprimir(int a[], int longitud);
void buscar(int a[], int dato, int longitud);
void almacenar(int a[],int dato, int longitud);
int main()
{

    int dato;

    int longitud;
    cout << "Ingrese el numero de elementos que desea : ";
    cin>>longitud;
    int arreglo1[longitud];
    anadir(arreglo1, dato, longitud);
    imprimir(arreglo1, longitud);
    buscar(arreglo1, dato, longitud);

    almacenar(arreglo1,dato, longitud);

}
void anadir(int a[], int &dato, int longitud){
    cout << "Ingrese los elementos del arreglo: "<<endl;
    for (int i=0; i<longitud; i++){
        cout << "elemento "<< i+1<< ": ";
        cin >> a[i];
    }
    cout << endl;
    cout << "Ingrese el dato a buscar: ";
    cin >> dato;
}
void buscar(int a[], int dato, int longitud){
    bool c=false;
    for(int i=0; i<longitud; i++){
        if(a[i]==dato){
            cout << "elemento encontrado en la posicion "<<i+1<<endl;
            c=true;
        }
    }
    if(c==false){
        cout << "Elemento no encontrado";
    }
}
void imprimir(int a[], int longitud){
    cout << "El arreglo es: "<<endl;
    for(int i=0; i<longitud; i++){
        cout <<a[i]<< " - ";
    }
    cout << endl;
}
void almacenar(int a[], int dato, int longitud){

    ofstream archivo;
    archivo.open("Busqueda.txt");
    archivo << "El arreglo es: "<< endl;
    for(int i=0; i<longitud; i++){
        archivo <<a[i]<<" " ;
    }
    archivo<<endl;
    bool c=false;
    for(int i=0; i<longitud; i++){
        if(a[i]==dato){
            archivo << "elemento encontrado en la posicion "<<i+1<<endl;
            c=true;
        }
    }
    if(c==false){
        archivo<< "Elemento no encontrado";
    }
    archivo.close();
}
