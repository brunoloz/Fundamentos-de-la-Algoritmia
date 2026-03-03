// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Resultado {

    bool degradado;
    int suma;

};


// función que resuelve el problema
Resultado resolver2(vector<int> const& fila, int ini, int fin) {

    if (ini == fin) {

        return { true, fila[ini] };

    }


    int m = (ini + fin) / 2;

    Resultado izq = resolver2(fila, ini, m);
    Resultado der = resolver2(fila, m + 1, fin);

    bool degradado = der.degradado && izq.degradado && (der.suma > izq.suma);
    int suma = der.suma + izq.suma;

    return { degradado, suma };


}

bool resolver(vector<vector<int>> const& matriz, int n, int m) {

    vector<int> fila;

    for (int i = 0; i < n; i++) {

        fila = matriz[i];
        if (!resolver2(fila, 0, m - 1).degradado) return false;

    }

    return true;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, m;
    cin >> n >> m;

    if (!std::cin)
        return false;

    vector<vector<int>> matriz(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++){

            cin >> matriz[i][j];

        }

    }

    bool sol = resolver(matriz, n, m);


    // escribir sol
    if (sol) cout << "SI";
    else cout << "NO";
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