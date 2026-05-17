// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema

/*
    - Precondicion: {true}

    - Invariante: { -1 <= p < i and
        numUnos(v, p + 1) == numCeros(v, p + 1) and
        (forAll k : p < k < i : numUnos(v, k + 1) != numCeros(v, k + 1)) }

    - Funcion de cota: n - i

    - Postcondicion: { -1 <= p < v.size() and numUnos(v, p + 1) == numCeros(v, p + 1) and (forAll k : p < k < datos.size : numUnos(v, k + 1) != numCeros(v, k + 1)) }

    - Coste: O(n)

*/

int equilibrio(vector<int> const& v) {

    int unos = 0;
    int ceros = 0;

    int p = -1;

    for (int i = 0; i < v.size(); i++) {

        if (v[i] == 1) unos++;
        else if (v[i] == 0) ceros++;

        if (unos == ceros) p = i;

    }

    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    int sol = equilibrio(v);
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