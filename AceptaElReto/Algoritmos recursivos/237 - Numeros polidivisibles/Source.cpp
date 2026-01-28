// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// función que resuelve el problema

bool polidivisible(long long numero, int num_digitos) {


    if (numero < 10) {

        return true;
    }  

    bool es = polidivisible(numero / 10, num_digitos - 1);


    return es && numero % num_digitos == 0;

}

int numDigitos(long long numero) {

    if (numero < 10) return 1;

    return numDigitos(numero / 10) + 1;

}

bool casoDePrueba() {

    long long numero;
    cin >> numero;
        if (!cin)
            return false;
        else {
            
            int d = numDigitos(numero);
            bool sol = polidivisible(numero, d);

            if (sol) cout << "POLIDIVISIBLE";
            else cout << "NO POLIDIVISIBLE";
            cout << '\n';

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main