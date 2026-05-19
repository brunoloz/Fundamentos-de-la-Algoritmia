// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL J19

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct tDatos {
    int m;
    int n;
    int sat;
    vector<vector<int>> matriz;
    vector<string> tipos; 
};

/*
* 
    El arbol de exploracion tiene una profundidad de n*2 siendo n el numero de niños. Cada rama representa los juguetes disponibles.
    El vector solucion es un array de enteros de tamaño de n * 2, donde n es el numero de niños. En cada posicion par se guarda el primer juguete de un niño y en las posiciones impares el segundo juguete.
    
*/

// función que resuelve el problema
void resolver(tDatos const& datos, int k, vector<int>& unidades, vector<int>& sol, bool& hay_solucion) {

    int nino = k / 2;

    int inicio = 0;
    if (k % 2 != 0) {
        inicio = sol[k - 1] + 1;
    }

    for (int j = inicio; j < datos.m; ++j) {

        if (unidades[j] > 0) {
            bool valido = true;

            if (k % 2 != 0) {

                if (datos.tipos[j] == datos.tipos[sol[k - 1]]) {
                    valido = false;
                }

                if (valido && (datos.matriz[nino][sol[k - 1]] + datos.matriz[nino][j] < datos.sat)) {
                    valido = false;
                }
            }

            if (valido) {
                sol[k] = j;         
                unidades[j]--;      

                if (k == (2 * datos.n) - 1) 
                {
                    hay_solucion = true;
                    for (int i = 0; i < sol.size(); i++) {
                        cout << sol[i] << " ";
                    }
                    cout << '\n';

                }
                else {

                    resolver(datos, k + 1, unidades, sol, hay_solucion);

                }

                unidades[j]++;
            }
        }
    }
}

// Resuelve un caso de prueba
bool resuelveCaso() {
    tDatos datos;

    cin >> datos.m >> datos.n >> datos.sat;
    if (!std::cin) return false;

    vector<int> unidades(datos.m);
    for (int i = 0; i < datos.m; i++) {
        cin >> unidades[i];
    }

    datos.tipos.resize(datos.m);
    for (int i = 0; i < datos.m; i++) {
        cin >> datos.tipos[i];
    }

    for (int i = 0; i < datos.n; i++) {
        vector<int> fila(datos.m);
        for (int j = 0; j < datos.m; j++) {
            cin >> fila[j];
        }
        datos.matriz.push_back(fila);
    }

    // Vector solución con tamaño 2 * n para albergar los dos juguetes de cada niño
    vector<int> sol(datos.n * 2, -1);
    bool hay_solucion = false;

    resolver(datos, 0, unidades, sol, hay_solucion);

    // Si no existe ninguna asignación posible se escribirá SIN SOLUCION.
    if (!hay_solucion) {
        cout << "SIN SOLUCION\n";
    }

    // Después de cada caso se escribe una línea en blanco.
    cout << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    // system("PAUSE"); // Evita usar system pause por compatibilidad, pero lo dejo a tu criterio
#endif

    return 0;
}