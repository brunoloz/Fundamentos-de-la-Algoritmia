// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

int balanceado(int pi, int di, int pd, int dd, int peso_acu) {


    if (pi == 0) {
        cin >> pi >> di >> pd >> dd;
        return balanceado(pi, di, pd, dd, peso_acu);
    }
    else {

        if (pd == 0) {
            cin >> pi >> di >> pd >> dd;
            return balanceado(pi, di, pd, dd, peso_acu);
        }
        else {
            peso_acu = pi * di + pd * dd;
            return balanceado(pi, di, pd, dd, peso_acu);

        }

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
            if (balanceado(pi, di, pd, dd, 0) == 0) cout << "SI";
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
