// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*

La ecuacion de recurrecia del algoritmo es: T(N) = 4T(N/2) + O(1)
Por lo tanto, decimos que el coste es de O(n) siendo n el numero de filas y columnas de la matriz.

*/

// función que resuelve el problema

struct Resultado {

    bool equilibrada;
    int labranza;

};

Resultado resolver(vector<vector<int>> const& matriz, int fila_ini,  int fila_fin, int col_ini, int col_fin, int total) {

    if (fila_ini == fila_fin && col_ini == col_fin) {

        if (matriz[fila_fin][col_fin] == 1) return { true, 1 };
        else return { true, 0 };

    }

    int m_fila = (fila_ini + fila_fin) / 2;
    int m_col = (col_ini + col_fin) / 2;

    Resultado cuadrante1 = resolver(matriz, fila_ini, m_fila, col_ini, m_col, total/ 4);
    Resultado cuadrante2 = resolver(matriz, m_fila + 1, fila_fin, col_ini, m_col, total / 4);
    Resultado cuadrante3 = resolver(matriz, fila_ini, m_fila, m_col + 1, col_fin, total / 4);
    Resultado cuadrante4 = resolver(matriz, m_fila + 1, fila_fin, m_col + 1, col_fin, total / 4);

    int maximo = max({ cuadrante1.labranza, cuadrante2.labranza, cuadrante3.labranza, cuadrante4.labranza });
    int minimo = min({ cuadrante1.labranza, cuadrante2.labranza, cuadrante3.labranza, cuadrante4.labranza });

    bool diferencia = abs(maximo - minimo) <= 2;

    bool equilibradas = cuadrante1.equilibrada && cuadrante2.equilibrada && cuadrante3.equilibrada && cuadrante4.equilibrada && diferencia;

    int total_labranzas = cuadrante1.labranza + cuadrante2.labranza + cuadrante3.labranza + cuadrante4.labranza;

    return { equilibradas && (total_labranzas >= (total / 4 - 1) && total_labranzas <= (total - total / 4)), total_labranzas };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> matriz[i][j];

        }

    }

    Resultado sol = resolver(matriz, 0, n-1, 0, n-1, n*n);
    // escribir sol
    if (sol.equilibrada) cout << "SI";
    else cout << "NO";
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