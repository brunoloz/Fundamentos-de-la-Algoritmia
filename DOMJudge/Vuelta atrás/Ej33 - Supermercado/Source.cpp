// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {

    int n;
    int m;
    vector<vector<long long>> matriz;

};

/*

    La altura del arbol es de n, siendo n el numero de productos de la lista.
    Cada rama del arbol representa el supermercado donde se ha comprado el producto.

    El vector solución es un array de tamaño m, siendo m el numero de supermercados. 
    En este vector almacenamos cuantos productos se han comprado en cada supermercado.

*/


// función que resuelve el problema
void resolver(tDatos const& datos, int k, vector<int>& sol, long long coste_act, long long& coste_mejor, vector<long long>& estimacion) {


    for (int i = 0; i < datos.m; i++) {

        sol[i]++;
        coste_act += datos.matriz[i][k];

        if (sol[i] <= 3) {

            if (k == datos.n - 1) {

                if (coste_act < coste_mejor) coste_mejor = coste_act;


            }
            else {

                if (coste_act + estimacion[k + 1] < coste_mejor) {

                    resolver(datos, k + 1, sol, coste_act, coste_mejor, estimacion);

                }

            }

        }

        sol[i]--;
        coste_act -= datos.matriz[i][k];

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    tDatos datos;
    cin >> datos.m >> datos.n;

    long long minimo = 1000000;
    vector<long long> minimos(datos.n, 1000000);

    for (int i = 0; i < datos.m; ++i) {
        vector<long long> fila(datos.n);
        for (int j = 0; j < datos.n; ++j) {
            cin >> fila[j];
        }
        datos.matriz.push_back(fila);
    }

    vector<int> sol(datos.m, 0);

    long long coste_mejor = 1000000;
    long long comparador = coste_mejor;

    vector<long long> estimacion(datos.n + 1, 0);

    for (int j = 0; j < datos.n; j++) {

        for (int i = 0; i < datos.m; i++) {

            if (datos.matriz[i][j] < minimos[j]) {

                minimos[j] = datos.matriz[i][j];

            }

        }

    }

    for (int i = datos.n - 1; i >= 0; i--) {

        estimacion[i] = minimos[i] + estimacion[i + 1];

    }

    resolver(datos, 0, sol, 0, coste_mejor, estimacion);

    // escribir sol
    if (coste_mejor == comparador) cout << "Sin solucion factible" << '\n';
    else cout << coste_mejor << '\n';
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