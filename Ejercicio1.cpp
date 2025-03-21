#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//Ejercicio 1 a)

vector<vector<int>> matriz (int n){
    vector<vector<int>> matriz(n,vector<int>(n));
    int valor = 1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            matriz[i][j] = valor;
            valor ++;
        }
    }

    return matriz;

}


//Ejercicio 1 b)

void imprimirmatriz(vector<vector<int>> matriz){
    int n = matriz.size();
    int numerocol;
    int numerofila;
    for (int i = n*n-1; i>=0; i--){
        numerofila = i/n;
        numerocol = i%n;
        cout << "[" << numerofila << "]" << "[" << numerocol << "] = " << matriz[numerofila][numerocol] << endl;
    }
    
}



int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;
    vector<vector<int>> Matrizprincipal = matriz(n);
    imprimirmatriz(Matrizprincipal);
    return 0 ;
}