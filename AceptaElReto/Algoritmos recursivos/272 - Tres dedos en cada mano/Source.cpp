// Esquema de la entrada: número de casos
#include <iostream>
using namespace std;

int baseseis(int numero) {

    if (numero < 6) return numero;

    return baseseis(numero / 6)* 10 + numero % 6;

}

void casoDePrueba() {

    int numero;
    cin >> numero;
    cout << baseseis(numero);
    cout << '\n';

} // casoDePrueba

int main() {

    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }

    return 0;

} // main
