// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*
    Complejidad:
    El problema tiene una complejidad del orden de O(n), siendo n el número de digitos que tiene el numero.

*/

// función que resuelve el problema
bool sumDivisible(long long int n, int suma_acu, int digit) {

    if (n == 0) return true;

    

    bool res = sumDivisible(n / 10, suma_acu - n% 10 , digit - 1);

    

    return res && (suma_acu % digit == 0);

}

int numDigitos(long long int n) {

    if (n < 10) return 1;

    return numDigitos(n / 10) + 1;

}

int valorSuma(long long int n) {

    if (n == 0) return 0;

    return valorSuma(n / 10) + n % 10;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int n;
    cin >> n;

    if (n == 0)
        return false;

    int d = numDigitos(n);
    int suma = valorSuma(n);

    bool sol = sumDivisible(n,suma, d);

    if (sol) cout << "SI";
    else cout << "NO";
    cout << '\n';

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
