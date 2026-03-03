// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//El coste del algoritmo es del orden de O(log n) siendo n el numero de elementos del vector

// función que resuelve el problema
char resolver(vector<char> const& v, int ini, int fin, char prim) {


    if (ini > fin) {
        return prim + ini;
    }

    int m = (ini + fin) / 2;

    if (v[m] == prim + m) {

        return resolver(v, m + 1, fin, prim);

    }
    else return resolver(v, ini, m - 1, prim);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    char prim, ult;
    cin >> prim >> ult;

    int n = ult - prim;
    vector<char> v(n);

    for (int i = 0; i < n; i++) {

        cin >> v[i];

    }

    char sol = resolver(v, 0, n-1, prim);
    // escribir sol
    cout << sol << '\n';

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