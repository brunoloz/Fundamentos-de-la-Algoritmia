// Nombre del alumno: Bruno Lozano Clemente
// Usuario del Juez: FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema

//Recursion No Final
/*int sumaDigitos(int n) {

    if (n < 10) {
        return n;
    }

    return n%10 + sumaDigitos(n / 10);

}*/

//Recursion Final
int sumaDigitosFinal(int n, int suma) {

    if (n < 10) {
        return suma + n;
    }

    return sumaDigitosFinal(n / 10, suma + n%10);

}

int sumaDigitos(int n) {

    return sumaDigitosFinal(n, 0);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, numero;
    cin >> n >> numero;

    int sol = sumaDigitos(numero);
    // escribir sol

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        if (sol == sumaDigitos(a)) {
            cout << a << " ";
        }

    }

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