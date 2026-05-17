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
void resolver(tDatos const& datos, int k, int coste_act, long long& coste_mejor, vector<int>& ruta, vector<bool>& visitado, vector<long long>& minimos, long long suma_acu) {

    for (int i = 1; i < datos.n; i++) {


        if (!visitado[i]) {

            ruta[k] = i;
            coste_act += datos.matriz[ruta[k - 1]][i];
            visitado[i] = true;

            if (k == datos.n - 1) {


                if (coste_act + datos.matriz[ruta[k]][0] < coste_mejor) {
                    coste_mejor = coste_act + datos.matriz[ruta[k]][0];
                }
            }
            else {

                suma_acu -= minimos[i];

                if (coste_act + suma_acu < coste_mejor) {

                    resolver(datos, k + 1, coste_act, coste_mejor, ruta, visitado, minimos, suma_acu);

                }

                suma_acu += minimos[i];

                

            }

            visitado[i] = false;
            coste_act -= datos.matriz[ruta[k - 1]][i];
        }

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

    vector<long long> minimos(datos.n);
    long long suma_acu = 0;

    for (int i = 0; i < datos.n; i++) {

        vector<long long> fila(datos.n);
        long long minimo = 1000000;

        for (int j = 0; j < datos.n; j++) {

            cin >> fila[j];
            if (fila[j] != 0 && fila[j] < minimo) {
                minimo = fila[j];
                minimos[i] = minimo;
            }

        }
        datos.matriz.push_back(fila);

    }

    for (int i = 0; i < minimos.size(); i++) suma_acu += minimos[i];

    vector<bool> sol(datos.n, false);
    long long coste_mejor = 1000000;
    vector<int> ruta(datos.n, 0);
    vector<bool> visitado(datos.n, false);




    ruta[0] = 0;
    visitado[0] = true;

    resolver(datos, 1, 0, coste_mejor, ruta, visitado, minimos, suma_acu);

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
