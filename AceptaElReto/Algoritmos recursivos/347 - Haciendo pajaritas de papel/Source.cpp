// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
using namespace std;

int cuantas(int a, int b) {

    if (a < 10 || b < 10) return 0;

    int cociente, resto;
    int minimo;

    if (a > b) {

        cociente = a / b;
        resto = a % b;
        minimo = b;
    }
    else if (a < b) {

        cociente = b / a;
        resto = b % a;
        minimo = a;

    }
    else return 1;

    return cuantas(resto, minimo) + cociente;

}


bool casoDePrueba() {

    // LEER CASO DE PRUEBA
    int a, b;
    cin >> a >> b;

        if (a == 0 && b == 0)
            return false;
        else {
            
            cout << cuantas(a, b) << '\n';

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main
