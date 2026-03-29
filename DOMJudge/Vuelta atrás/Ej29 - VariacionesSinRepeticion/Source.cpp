// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const vector<char> abecedario = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o','p','q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

struct Datos {

    vector<char> letras;
    int n;
    int m;

};

bool esValida(vector<char> const& sol, int k) {

    char letra = sol[k];

    for (int i = k - 1; i >= 0; i--) {

        if (letra == sol[i]) return false;

    }

    return true;

}

// función que resuelve el problema
void resolver(Datos const& datos, int k, vector<char>& sol) {

    for (int i = 0; i < datos.n; i++) {

        sol[k] = abecedario[i];

        if (esValida(sol, k)) {

            if (k == datos.m - 1) {

                for (int i = 0; i < sol.size(); i++) {

                    cout << sol[i];

                }

                cout << '\n';

            }
            else {

                resolver(datos, k + 1, sol);

            }

        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Datos datos;
    cin >> datos.n >> datos.m;
    if (!std::cin)
        return false;

    vector<int> letras;
    for (int i = 0; i < datos.n; i++) {
        datos.letras.push_back(abecedario[i]);
    }

    vector<char> sol(datos.m, 0);
    resolver(datos, 0, sol);

    // escribir sol

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