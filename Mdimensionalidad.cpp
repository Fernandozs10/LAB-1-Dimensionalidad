#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <fstream>
using namespace std;

//funcion para encontrar la distancia euclidiana entre 2 puntos
double euclidiana(const vector<double>& punto1, const vector<double>& punto2) {
    double distancia = 0.0;
    for (int i = 0; i < punto1.size(); ++i) {
        distancia += pow(punto1[i] - punto2[i], 2);
    }
    return sqrt(distancia);
}

int main() {
    //creamos el archivo donde se almacenaran los datos
    ofstream outputFile("datos10.txt");

    //elementos para generar los datos aleatorios entre 0 y 1.0
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1.0);
    
    //almacenamos el numero de dimensione (se tendra que cambiar manualmente)
    vector<int> dimensiones = { 10 };
    outputFile.is_open();

    for (int d : dimensiones) {

        vector<vector<double>> puntos(100, vector<double>(d));
        //almacena los numeros aleatorios en el vector
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < d; ++j) {
                puntos[i][j] = dis(gen);
            }
        }
        //saca las distancias entre los 2 puntos y los escribe en el txt
        for (int i = 0; i < 100; ++i) {
            for (int j = i + 1; j < 100; ++j) {
                double distancia = euclidiana(puntos[i], puntos[j]);
                outputFile << distancia << endl;
            }
        }
    }
    outputFile.close();

    return 0;
}
