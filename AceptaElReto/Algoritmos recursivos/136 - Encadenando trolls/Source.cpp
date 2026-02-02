// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

int particion(int hobbit, int enano, int tamanyo) {

    if (hobbit >= tamanyo || enano >= tamanyo) return 0;

    int menor = particion(hobbit, enano, tamanyo / 3) + 1;
    int mayor = particion(hobbit, enano, (tamanyo / 3) * 2 + tamanyo % 3) + 1;

    return menor + mayor - 1;
}


bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int H, N;
    cin >> H >> N;
        if (H == 0)
            return false;
        else {
            // CÓDIGO PRINCIPAL AQUÍ
            // Procesa un único caso.
            // Evita el uso de endl.
            cout << particion(H, H * 2, N) << '\n';

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main
