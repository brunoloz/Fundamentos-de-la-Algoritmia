// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema

/*
    - Precondición: { datos.size >= 0 } 
        resolver(vector<int> const& datos, int error) dev integer

    - Invariante: { 0 <= i <= datos.size and cont = #k : 0 <= k < i : datos[k] == error }

    - Funcion de cota = n - i

    - Postcondición: { ret = datos.size - cont : cont = #k : 0 <= k < datos.size : datos[k] == error }

    - Coste: O(n)

*/

int resolver(vector<int> const& datos, int error) {

    int n = datos.size();
    int cont = 0;

    for (int i = 0; i < n; i++) {

        if (datos[i] == error) cont++;

    }

    return n - cont;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n, error;
    cin >> n >> error;

    vector<int> v;
    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    int cont = resolver(v, error);
    // escribir sol

    cout << cont << '\n';

    for (int i = 0; i < v.size(); i++) {

        if (v[i] != error) cout << v[i] << " ";

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