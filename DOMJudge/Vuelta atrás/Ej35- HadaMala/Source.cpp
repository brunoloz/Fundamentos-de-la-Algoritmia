// Nombre del alumno  Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Resultado {

    bool posible;
    int max_sat;
    int num_comb;

};

/*

    El vector solución sol_parcial es un array de tamaño m.

    El indice representa el número de asiento que estamos asignando en el paso actual. Toma valores desde 0 hasta m - 1.

    En el vector se guarda el identificador del habitante (un valor entre 0 y n - 1) que ha sido asignado a sentarse en el asiento 'k'.


*/

/*

    Cada nodo del arbol de exploracion representa un estado de la asignación parcial del banquete hasta el asiento 'k'.
    La altura máxima es m o m+1 si contamos el nivel de la raíz como nivel 0.
    En el nivel 0 hay 1 nodo (raíz).
    En el nivel 1 hay n nodos. 
    En el nivel 2 hay n*(n-1) nodos.

*/

void resolverAux(int n, int m, int hada, vector<vector<int>> const& matriz, int k, int sat_actual, int supersticion, vector<bool>& visitado, vector<int>& sol_parcial,
    vector<int>& acum_max, Resultado& sol) {

    if (sat_actual + acum_max[k] < sol.max_sat) return;

    //caso base
    if (k == m) {
        if (!visitado[hada]) return; // el hada debe estar invitada

        if (sat_actual > sol.max_sat) {
            sol.max_sat = sat_actual;
            sol.num_comb = 1;
            sol.posible = true;
        }
        else if (sat_actual == sol.max_sat) {
            sol.num_comb++;
        }
        return;
    }

    for (int i = 0; i < n; i++) {

        if (visitado[hada] || (m - k) != 1 || i == hada) { // si hada esta invitada || no estamos en el ult asiento || si estamos evaluando el hada

            if (!visitado[i] && matriz[k][i] >= 0) {

                // calculamos si este habitante en este asiento suma a la superstición
                int sig_supersticion;
                if (i == k) sig_supersticion = supersticion + 1;
                else sig_supersticion = supersticion;

                // comprobamos la restricción del límite de supersticiosos (m/3)
                if (sig_supersticion <= m / 3) {

                    //marcaje
                    visitado[i] = true;
                    sol_parcial[k] = i; // guardamos en el vector solución


                    resolverAux(n, m, hada, matriz, k + 1, sat_actual + matriz[k][i], sig_supersticion, visitado, sol_parcial, acum_max, sol);

                    visitado[i] = false;
                }
            }

        }

    }

}

// función que resuelve el problema
Resultado resolver(int n, int m, int hada, vector<vector<int>> const& matriz) {

    Resultado sol = { false, -1, 0 };
    vector<bool> visitados(n, false);
    vector<int> sol_parcial(m, -1);

    vector<int> maximos(m, 0); //para guardar los maximos por fila
    for (int i = 0; i < m; i++) {

        int maximo = -1;

        for (int j = 0; j < n; j++) {

            if (matriz[i][j] > maximo) 
                maximo = matriz[i][j]; 

        }

        if (maximo > 0) maximos[i] = maximo;
        else maximo = 0;

    }

    vector<int> acum_max(m + 1, 0); //para la suma de las maximas satisfacciones
    for (int i = m - 1; i >= 0; --i) {
        acum_max[i] = acum_max[i + 1] + maximos[i];
    }

    resolverAux(n, m, hada, matriz, 0, 0, 0, visitados, sol_parcial, acum_max, sol);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;

    if (n== 0)
        return false;

    int m, hada;
    cin >> m >> hada;

    vector<vector<int>> matriz;

    for (int i = 0; i < m; ++i) {
        vector<int> fila(n); 
        for (int j = 0; j < n; ++j) {
            cin >> fila[j]; 
        }
        matriz.push_back(fila); 
    }

    Resultado sol = resolver(n, m, hada, matriz);

    // escribir sol
    if (sol.posible) {
        cout << sol.max_sat << " " << sol.num_comb << "\n";
    }
    else {
        std::cout << "No\n";
    }

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
