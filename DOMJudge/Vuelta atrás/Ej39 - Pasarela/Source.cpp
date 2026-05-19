// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {

    int n;
    vector<vector<int>> trajes;
    vector<vector<int>> zapatos;

};

/*

    El arbol de exploracion tiene una profundidad de n siendo n el numero de modelos. Cada rama del arbol representa las distintas opciones de trajes y zapatos a elegir.
    Utilizo dos vectores booleanos, uno para trajes y otro para zapatos, si un accesorio se utiliza se marca a true sino a false.

*/

// función que resuelve el problema
void resolver(tDatos const& datos, int k, vector<int> acum, int acu, vector<bool>& sol_traje, vector<bool>& sol_zapato, int& sol_mejor) {

    for (int i = 0; i < datos.n; i++) {

        if (!sol_traje[i]) {

            sol_traje[i] = true;

            for (int j = 0; j < datos.n; j++) {

                if (!sol_zapato[j]) {

                    sol_zapato[j] = true;
                    acu += (datos.trajes[k][i] * datos.zapatos[k][j]);

                    if (k == datos.n - 1) {

                        if (acu > sol_mejor)
                            sol_mejor = acu;

                    }
                    else {

                        if (acu + acum[k + 1] >= sol_mejor)
                            resolver(datos, k + 1, acum, acu, sol_traje, sol_zapato, sol_mejor);

                    }

                    sol_zapato[j] = false;
                    acu -= (datos.trajes[k][i] * datos.zapatos[k][j]);

                }

            }

            sol_traje[i] = false;

        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    tDatos datos;
    cin >> datos.n;

    vector<int> maximo_traje(datos.n, 0);
    vector<int> maximo_zapato(datos.n, 0);

    for (int i = 0; i < datos.n; i++) {

        vector<int> fila;
        int max_traje = 0;

        for (int j = 0; j < datos.n; j++) {

            int a;
            cin >> a;
            fila.push_back(a);

            if (a > max_traje) {

                max_traje = a;
                maximo_traje[i] = a;

            }

        }

        datos.trajes.push_back(fila);

    }

    for (int i = 0; i < datos.n; i++) {

        vector<int> fila;
        int max_zapato = 0;

        for (int j = 0; j < datos.n; j++) {

            int a;
            cin >> a;
            fila.push_back(a);

            if (a > max_zapato) {

                max_zapato = a;
                maximo_zapato[i] = a;

            }

        }

        datos.zapatos.push_back(fila);

    }

    vector<int> acum(datos.n + 1, 0);

    for (int i = datos.n - 1; i >= 0; i--) {

        acum[i] = acum[i+ 1] + (maximo_traje[i] * maximo_zapato[i]);

    }

    vector<bool> sol_trajes(datos.n, false);
    vector<bool> sol_zapatos(datos.n, false);

    int sol_mejor = 0;

    resolver(datos, 0, acum, 0, sol_trajes, sol_zapatos, sol_mejor);
    // escribir sol

    cout << sol_mejor << '\n';

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