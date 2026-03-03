// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool resolver(vector<int> const& v, int ini, int fin, int d) {

    if (ini >= fin) return true;

    int m = (ini + fin) / 2;

    bool izq = resolver(v, ini, m, d);
    bool der = resolver(v, m + 1, fin, d);

    return (abs(v[ini] - v[fin]) >= d && izq && der);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, d;
    cin >> n >> d;

    if (!std::cin)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];


    bool sol = resolver(v, 0, n-1, d);


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