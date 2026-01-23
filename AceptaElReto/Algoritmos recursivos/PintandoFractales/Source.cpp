// Esquema de la entrada: fin de la entrada
#include <iostream>
using namespace std;

int recursion(int longitud, int suma_acu) {

    if (longitud == 1) return 4;
    else suma_acu = longitud * 4;

    suma_acu += 4 * recursion(longitud / 2, suma_acu);

    return suma_acu;
}

bool casoDePrueba() {

    int L;
    cin >> L;

    if (!cin)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        // Procesa un único caso.
        // Evita el uso de endl.
        cout << recursion(L, 0) << '\n';

        return true;
    }

} // casoDePrueba

int main() {

    while (casoDePrueba());

    return 0;

} // main
