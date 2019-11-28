#include <iostream>
using namespace std;
void agregar(int a[], int n);
void imprimir(int a[], int n);
void ordenar(int a[], int n);
int main()
{
    int tamanio;


    cout<< "ingrese el tamanio: ";
    cin >> tamanio;
    int arreglo[tamanio];
    agregar(arreglo, tamanio);
    ordenar(arreglo, tamanio);
    cout << endl;
    imprimir(arreglo, tamanio);


    return 0;
}
void agregar(int a[], int n){
    cout << "Ingrese los numeros para ordenar: ";
    for (int i=0 ; i<n ;i++){

        cin >> a[i];
    }

}
void imprimir(int a[], int n){
    for (int i=0 ; i<n ;i++){
        cout << a[i];
    }
}
void ordenar(int arreglo[], int n){
    int aux, minimo;

    for (int i=0; i<n; i++)
    {
        minimo=i;
        for(int j=i+1; j<n; j++){
            if(arreglo[j]<arreglo[minimo]){
                minimo=j;
            }
        }
        aux=arreglo[i];
        arreglo[i]=arreglo[minimo];
        arreglo[minimo]=aux;
    }
}
