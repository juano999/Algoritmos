

#include <iostream>
using namespace std;
const int TAM = 5;

int main()
{
    int lista[TAM] = { 54,34,2,6,16 };
    int temp,j;
    for (int i = 1; i < TAM; i++) {
        temp = lista[i];
        j = i - 1;
        while ((lista[j] > temp) && (j >= 0)) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = temp;
    }

    for (int i = 0;i < TAM;i++) {
        cout << lista[i] << "  ";
    }
}

