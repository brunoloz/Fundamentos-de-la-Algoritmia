// Esquema de la entrada: número de casos
#include <iostream>
#include <string>
using namespace std;

void casoDePrueba() {

    string operacion;
    getline(cin, operacion);



} // casoDePrueba

int main() {

    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }

    return 0;

} // main
