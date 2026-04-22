// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {

    int n;
    vector<vector<long long>> matriz;

};

/*

    El árbol de exploracion es de altura n, donde n es el numero de ciudades.
    Cada rama del arbol representa el camino tomado que une dos ciudades.

    El vector solucion es un array de tamaño n, donde n es el numero de ciudades.
    En él se indica si la ciudad ha sido visitada o no.

*/

// función que resuelve el problema
void resolver(tDatos const& datos, int k, vector<bool>& sol, int coste_act, long long& coste_mejor) {

    for (int i = 0; i < datos.n; i++) {

        sol[i] = true;
        coste_act += datos.matriz[k][i];

        if (coste_act != 0) {

            if (k == datos.n - 1) {

                if (coste_act < coste_mejor) coste_mejor = coste_act;

            }
            else {

                resolver(datos, k + 1, sol, coste_act, coste_mejor);

            }

        }

        sol[i] = false;
        coste_act -= datos.matriz[k][i];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    tDatos datos;
    cin >> datos.n;

    if (datos.n == 0)
        return false;



    for (int i = 0; i < datos.n; i++) {

        vector<long long> fila(datos.n);

        for (int j = 0; j < datos.n; j++) {

            cin >> fila[j];
        }
        datos.matriz.push_back(fila);

    }

    vector<bool> sol(datos.n, false);
    long long coste_mejor = 1000000;

    resolver(datos, 0, sol, 0, coste_mejor);

    // escribir sol
    cout << coste_mejor << '\n';

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
