// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

int numPaseos(int n, bool turno) {

    //Casos base
    if (n <= 0) return 0;
    if (n == 1) return 1;

    if (turno)
        if(n % 2 == 0)
            return numPaseos(n - 2, false) + 1;
        else return numPaseos(n - 1, false) + 1;
    else
        return numPaseos(n - 1, true) + 1;


}

bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int N;
    cin >> N;

        if (N == 0)
            return false;
        else {
            // CÓDIGO PRINCIPAL AQUÍ
            // Procesa un único caso.
            // Evita el uso de endl.
            cout << numPaseos(N, false) << '\n';

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba());

    return 0;

} // main
