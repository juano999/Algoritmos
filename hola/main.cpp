#include <iostream>

using namespace std;
void ingresar(int a[], int n);
void borbujar(int a[], int n);
void imprimir(int a[], int n);
int main()
{
   //int i=0;

    int arreglo[5];
    ingresar(arreglo, 5);
    borbujar(arreglo, 5);
    imprimir(arreglo, 5);




    return 0;
}
void ingresar(int a[], int n){
    for(int i=0; i<n ;i++){
        cin>> a[i];
    }
}

void borbujar(int a[], int n){
    for(int i=0; i<n ;i++){
        for(int j=i+1; j<=n-1; j++){
            if(a[i]>a[j]){
            int aux= a[i];
            a[i]=a[j];
            a[j]=aux;
            }

        }
    }
}
void imprimir(int a[], int n){
    for(int i=0; i<n ;i++){
        cout << a[i];
    }
}
