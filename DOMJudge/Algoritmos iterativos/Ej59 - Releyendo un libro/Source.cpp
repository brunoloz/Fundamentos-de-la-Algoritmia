// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;



// función que resuelve el problema
int resolver(vector<int> libro, vector<int>& acum, int t) {

    int suma_acu = 0;


    for (int i = 0; i < t; i++) {

        suma_acu += libro[i];

    }
    
    int maximo = suma_acu;
    int ini = 0;

    for (int i = 1; i <= libro.size() - t; i++) {

        suma_acu = suma_acu - libro[i - 1] + libro[i + t - 1];

        if (suma_acu >= maximo) {

            maximo = suma_acu;
            ini = i;
        }

    }

    return ini;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, t;
    cin >> n >> t;
    
    if (n == 0 && t == 0)
        return false;

    vector<int> libro(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> libro[i];
    }

    vector<int> acum(n,0);
    int sol = resolver(libro, acum, t);

    // escribir sol
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
