// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Datos {

    vector<string> colores = {  "azul", "rojo", "verde" };
    int m;

};

bool esValida(vector<string> const& sol, int k) {

    string color = sol[k];

    if (k > 0) {

        if (sol[k - 1] == "verde" && sol[k] == "verde") return false;

    }

    return true;

}

// función que resuelve el problema
void resolver(Datos const& datos, int k, vector<string>& sol) {


    for (int i = 0; i < datos.colores.size(); i++) {

        sol[k] = datos.colores[i];

        if (sol[0] == "rojo" && esValida(sol, k)) {

            if (k == datos.m - 1) {

                for (int i = 0; i < sol.size(); i++)
                    cout << sol[i] << " ";

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
    cin >> datos.m;

    if (datos.m == 0)
        return false;

    vector<string> sol(datos.m, " ");

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
