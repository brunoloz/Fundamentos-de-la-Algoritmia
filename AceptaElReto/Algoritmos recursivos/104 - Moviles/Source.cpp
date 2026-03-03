// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

bool balanceado(int suma_izq, int suma_der) {

    int pi, di, pd, dd;
    cin >> pi >> di >> pd >> dd;

    if (pi == 0 && di == 0 && pd == 0 && dd == 0) return false;

    if (suma_izq != 0 && suma_der != 0) return suma_izq + suma_der;

    if (suma_izq == 0) {



    }
    


}


bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int pi, di, pd, dd;
    cin >> pi >> di >> pd >> dd;

        if (pi == 0 && di == 0 && pd == 0 && dd == 0)
            return false;
        else {
            // CÓDIGO PRINCIPAL AQUÍ
            // Procesa un único caso.
            // Evita el uso de endl.

            int suma_izq = pi * di;
            int suma_der = pd * dd;

            if (balanceado(suma_izq, suma_der) == 0) cout << "SI";
            else cout << "NO";
            cout << '\n';

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main
