// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL J-19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema



struct tSolucion {

    int inicio;
    int longitud;

};


/*

    consecutivos(v, ini, fin) = (forAll k : 0 <= ini <= k < fin : v[k] + 1 == v[k+1])

    secuenciaMax(v, longitud) = (longitud == max( i, j : 0 <= i <= j and consecutivos(v, i, j) : j - i + 1)

    - Precondicion: { v.size > 0 }
        resolver(vector<int> const& v) dev integer and integer

    - Invariante: { 0 <= i <= v.size() - 1 ∧consecutivos(v, ini, i) ∧ longitud == i - ini + 1 ∧
                sol.longitud == (max j, k : 0 <= j <= k <= i ∧ consecutivos(v, j, k) : k - j + 1) }

    - Funcion de cota: (n - 1) - i

    - Postcondición: { secuenciaMax(v, sol.longitud) ∧consecutivos(v, sol.inicio, sol.inicio + sol.longitud - 1) ∧
                   (forAll i, j : 0 ≤ i ≤ j < v.size() ∧ consecutivos(v, i, j) ∧(j - i + 1) == sol.longitud : sol.inicio ≤ i) }

*/

tSolucion resolver(vector<int>const v) {

    tSolucion sol = { 0,1 };

    int max = 0;
    int longitud = 1;
    int ini = 0;

    for (int i = 0; i < v.size() - 1; i++) {

        if (v[i] + 1 == v[i + 1]) {

            longitud++;

            if (longitud > max) {

                max = longitud;
                sol.longitud = longitud;
                sol.inicio = ini;

            }

        }
        else {
            longitud = 1;
            ini = i + 1;
        }


    }

    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> v;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    tSolucion sol = resolver(v);

    // escribir sol
    cout << sol.inicio << " " << sol.longitud << '\n';

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
