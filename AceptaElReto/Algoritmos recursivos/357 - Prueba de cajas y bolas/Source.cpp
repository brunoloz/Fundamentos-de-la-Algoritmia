// Esquema de la entrada: fin de la entrada
#include <iostream>
using namespace std;


int resolver(int n){

    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return 1 + resolver(n / 2);

}

bool casoDePrueba() {

    int n;
    cin >> n;

    if (!cin)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        // Procesa un único caso.
        // Evita el uso de endl.

        int sol = resolver(n);
        cout << sol << '\n';

        return true;
    }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main
