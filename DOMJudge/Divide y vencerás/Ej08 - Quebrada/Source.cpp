// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*

El coste de la busqueda es del orden de O(log n) siendo n el número de elementos del vector.

*/

// función que resuelve el problema
int pos_izq(vector<int> const& v, int ini, int fin) {

    if (ini + 1 >= fin) return ini;

    int m = (ini + fin) / 2;
    
    if (v[m] >= v[m - 1]) return pos_izq(v, ini, m);
    else return pos_izq(v, m, fin);

}


int pos_der(vector<int> const& v, int ini, int fin) {


    if (ini + 1 >= fin) return ini;

    int m = (ini + fin) / 2;

    if (v[m] > v[m - 1]) return pos_der(v, ini, m);
    else return pos_der(v, m, fin);


}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;

    if (n == -1)
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {

        cin >> v[i];

    }


    int ini = pos_izq(v, 0, n); //Posicion donde empieza el rio
    int fin = pos_der(v, 0, n); //Posicion donde acaba el rio

    // escribir sol

    int sol = fin - ini + 1;
    if (n == 0) sol = 0;

    cout << sol << '\n';

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
