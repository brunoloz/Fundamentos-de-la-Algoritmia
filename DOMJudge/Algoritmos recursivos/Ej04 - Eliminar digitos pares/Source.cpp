// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL J-19


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
long long recursionFinal(long long n, long long suma_acu, long long d) {

    if (n == 0) return suma_acu;

    int dig = n % 10;
    if (dig % 2 == 0) {

        return recursionFinal(n / 10, suma_acu, d);

    }
    else {

        suma_acu += dig * d;

        return recursionFinal(n / 10, suma_acu, d * 10);
    }

}

long long recursionNoFinal(long long n, long long suma_acu, long long d) {

    if (n == 0) return 0;

    int dig = n % 10;
    if (dig % 2 == 0) {

        return recursionNoFinal(n / 10, suma_acu, d);

    }
    else {

        suma_acu = dig * d;

        return suma_acu + recursionNoFinal(n / 10, suma_acu, d * 10);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long n;
    cin >> n;
    if (!std::cin)
        return false;

    long long sol = recursionFinal(n, 0, 1);
    long long sol_nofinal = recursionNoFinal(n, 0, 1);
    cout << sol <<" " << sol_nofinal << '\n';

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