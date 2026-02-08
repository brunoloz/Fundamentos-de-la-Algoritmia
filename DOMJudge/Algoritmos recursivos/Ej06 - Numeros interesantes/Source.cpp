// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
bool interesante(long long int n, int suma_izq, int suma_der) {

    if (n == 0) return true;

    int digit = n % 10;

    if (digit == 0) return false;

    if (!((suma_izq - digit) % digit == 0) || !(suma_der % digit == 0)) return false;

    return interesante(n / 10, suma_izq - digit, suma_der + digit);

}

int valorSuma(long long int n) {

    if (n == 0) return 0;

    return valorSuma(n / 10) + n % 10;

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long long int n;
    cin >> n;

    int suma = valorSuma(n);

    bool sol = interesante(n, suma, 0);

    // escribir sol
    if (sol) cout << "SI";
    else cout << "NO";
    cout << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}