// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {

    int n;
    vector<int> T;
    vector<int> P;
    vector<int> N;

};

/*

    El árbol de exploración de este problema es un árbol de exploración binario con una profundidad n, siendo n el número de trabajos a realizar.
    Cada rama del árbol representa una decisión (realizar o no el trabajo).
    Los nodos del árbol representan las tareas.

    El vector solución es un vector de booleanos de tamaño n, siendo n el numero de trabajos a realizar.
    El valor de una posición i puede ser true si realizo el trabajo y false si no lo realizo.

    Marcaje: Cunado hago el trabajo aumento el valor del tiempo_consumido sumando el tiempo que supone hacer ese trabajo y lo marco como true, además si no he sobrepasado el plazo
    entonces actualizo la puntuacion actual sumado la puntuacion que supone ese trabajo. Despuñés de la llamada recursiva deshago el marcaje.

*/


// función que resuelve el problema
void resolver(tDatos const& datos, int k, int punt_actual, int& punt_mejor, vector<bool>& sol, vector<bool>& sol_mejor, int tiempo_consumido, vector<int> const& acum) {

    //Hago el trabajo

    sol[k] = true;
    tiempo_consumido += datos.T[k];

    if (tiempo_consumido <= datos.P[k]) {

        punt_actual += datos.N[k];

        if (k == datos.n - 1) {

            if (punt_actual > punt_mejor) {

                punt_mejor = punt_actual;
                sol_mejor = sol;
            }


        }
        else {

            if (punt_actual + acum[k + 1] >= punt_mejor)
                resolver(datos, k + 1, punt_actual, punt_mejor, sol, sol_mejor, tiempo_consumido, acum);

        }

        punt_actual -= datos.N[k];

    }

    tiempo_consumido -= datos.T[k];
    sol[k] = false;

    //No hago el trabajo

    if (k == datos.n - 1) {

        if (punt_actual > punt_mejor) {

            punt_mejor = punt_actual;
            sol_mejor = sol;
        }

    }
    else {

        resolver(datos, k + 1, punt_actual, punt_mejor, sol, sol_mejor, tiempo_consumido, acum);

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    tDatos datos;
    cin >> datos.n;

    for (int i = 0; i < datos.n; i++) {

        int a;
        cin >> a;
        datos.T.push_back(a);

    }

    for (int i = 0; i < datos.n; i++) {

        int a;
        cin >> a;
        datos.P.push_back(a);

    }

    for (int i = 0; i < datos.n; i++) {

        int a;
        cin >> a;
        datos.N.push_back(a);

    }

    vector<int> acum(datos.n + 1, 0);
    for (int i = datos.n - 1; i >= 0; i--) {

        acum[i] = acum[i + 1] + datos.N[i];

    }


    vector<bool> sol(datos.n, false);
    vector<bool> sol_mejor(datos.n, false);
    int punt_mejor = 0;

    resolver(datos, 0, 0, punt_mejor, sol, sol_mejor, 0, acum);
    // escribir sol

    cout << punt_mejor << " ";
    for (int i = 0; i < sol_mejor.size(); i++) {

        if (sol_mejor[i] == true) cout << i << " ";

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