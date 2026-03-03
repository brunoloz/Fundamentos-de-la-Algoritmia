// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//El coste del algoritmo es del orden de O(log n) siendo n el numero de elementos del vector v.

int resolver(vector<int> const& v, int ini, int fin) {


    if (ini + 1 >= fin) {

        if (v[ini] > v[fin]) return v[fin];
        else return v[ini];

    }


    if (v[ini] > v[fin]) return v[fin];

    int m = (ini + fin) / 2;


    if (v[m] < v[ini]) {

        return resolver(v, m, fin);
    }
    else {

        return resolver(v, ini, m);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {

        cin >> v[i];

    }

    int sol = resolver(v, 0, n -1);

    // escribir sol
    cout << sol << '\n';

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