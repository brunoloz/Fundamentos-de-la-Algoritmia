// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/*

    El árbol de exploración tiene una profundidad de m, siendo m el número de puestos disponibles en el banquete.
    Cada nodo representa el puesto del banquete. Cada rama representa una de las opciones posibles para ese puesto.

    El vector solucion es un array de tipo booleano y de tamaño n, siendo n el numero de habitantes del reino.
    La posición i es true si el habitante i acude al banquete y false si no acude.

*/

struct tDatos {

    int n;
    int m;
    int hada;
    vector<vector<int>> matriz;

};

// función que resuelve el problema
void resolver(tDatos const& datos, int k, int sat_actual, int& sat_mejor, int cont, vector<bool>& sol, bool& posible, int& comb, vector<int> const& acum) {


    for (int i = 0; i < datos.n; i++) {

        if (i == k) cont++;

        if (!sol[i] && datos.matriz[k][i] >= 0 && (cont <= (datos.m / 3))) { //si la sat en ese puesto no es negativa y no se supera la superstición

            sat_actual += datos.matriz[k][i];
            sol[i] = true;

            if (k == datos.m - 1) {

                if (sol[datos.hada]) {

                    if (sat_actual > sat_mejor) {

                        sat_mejor = sat_actual;
                        comb = 1;

                    }
                    else if (sat_actual == sat_mejor) comb++;

                    posible = true;
                }

            }
            else {

                if (acum[k + 1] + sat_actual >= sat_mejor)
                    resolver(datos, k + 1, sat_actual, sat_mejor, cont, sol, posible, comb, acum);

            }

            sat_actual -= datos.matriz[k][i];
            sol[i] = false;

        }

        if (i == k) cont--;


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

    cin >> datos.m >> datos.hada;

    vector<int> maximos(datos.m, 0);
    int max = -100000;

    for (int i = 0; i < datos.m; i++) {

        vector<int> fila;

        for (int j = 0; j < datos.n; j++) {

            int a;
            cin >> a;
            fila.push_back(a);
            if (a > max) max = a;

        }
        maximos[i] = max;
        datos.matriz.push_back(fila);

    }

    vector<int> acum(datos.m + 1, 0);
    for (int i = datos.m - 1; i >= 0; i--) {

        acum[i] = acum[i + 1] + maximos[i];

    }

    int sat_mejor = -1;
    bool posible = false;
    vector<bool> sol(datos.n, false);
    int comb = 1;

    resolver(datos, 0, 0, sat_mejor, 0, sol, posible, comb, acum);

    // escribir sol
    if (!posible) cout << "No";
    else {

        cout << sat_mejor << " " << comb;

    }

    cout << '\n';

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
