// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Datos {

    int m;
    int n;
    vector<vector<int>> matriz_sat;


};

/*

    El arbol de exploración de este ejercicio tiene una altura n donde n es el numero de niños.
    Cada rama representa las opciones que tiene un niño.

    El vector solución es de tamaño m donde m es el numero de juguetes, e indica si ese juguete se ha elegido o no.

*/


// función que resuelve el problema
void resolver(Datos const& datos, int k, vector<bool>& sol, int sat_actual, int& sat_mejor, vector<int>& estimacion) {

    for (int i = 0; i < datos.m; i++) {

        if (!sol[i]) {

            sol[i] = true;
            sat_actual += datos.matriz_sat[k][i];

            if (k == datos.n - 1) {

                if (sat_actual > sat_mejor) sat_mejor = sat_actual;

            }
            else {


                if(sat_actual + estimacion[k + 1] > sat_mejor)
                    resolver(datos, k + 1, sol, sat_actual, sat_mejor, estimacion);

            }

            sol[i] = false;
            sat_actual -= datos.matriz_sat[k][i];


        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    Datos datos;
    cin >> datos.m >> datos.n;

    if (!std::cin)
        return false;

    vector<int> maximos(datos.n, 0);
    int maximo = 0;

    for (int i = 0; i < datos.n; ++i) {
        vector<int> fila(datos.m);
        for (int j = 0; j < datos.m; ++j) {
            cin >> fila[j];
            if (fila[j] > maximo) {
                maximo = fila[j];
                maximos[i] = maximo;
            }
        }
        datos.matriz_sat.push_back(fila);
        maximo = 0;
    }

    vector<bool>sol(datos.m, false);
    int sat_mejor = -1;

    vector<int> estimacion(datos.n + 1, 0);

    for (int i = datos.n - 1; i >= 0; i--) {

        estimacion[i] = maximos[i] + estimacion[i + 1];

    }


    resolver(datos, 0, sol, 0, sat_mejor, estimacion);

    // escribir sol
    cout << sat_mejor << '\n';

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