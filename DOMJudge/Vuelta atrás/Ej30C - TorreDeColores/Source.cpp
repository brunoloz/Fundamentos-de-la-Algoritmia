// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Datos {

    vector<string> colores = { "azul", "rojo", "verde" };
    int m;
    int azules;
    int rojos;
    int verdes;

};


bool esValida(vector<string>& sol, int k, vector<int> piezasUsadas, Datos const& datos) {

    string color = sol[k];

    if (piezasUsadas[0] > datos.azules) return false;

    if (piezasUsadas[1] > datos.rojos) return false;

    if (piezasUsadas[2] > datos.verdes) return false;


    if (piezasUsadas[2] > piezasUsadas[0]) return false;

    if (k > 0) {

        if (sol[k - 1] == "verde" && sol[k] == "verde") return false;

    }

    return true;

}

// función que resuelve el problema
void resolver(Datos& datos, int k, vector<string>& sol, vector<int> piezasUsadas, bool& haySolucion) {


    for (int i = 0; i < datos.colores.size(); i++) {

        sol[k] = datos.colores[i];
        piezasUsadas[i]++;


        if (sol[0] == "rojo" && esValida(sol, k, piezasUsadas, datos)) {



            if (k == datos.m - 1) {


                if (piezasUsadas[1] > (piezasUsadas[0] + piezasUsadas[2])) {

                    haySolucion = true;

                    for (int i = 0; i < sol.size(); i++)
                        cout << sol[i] << " ";

                    cout << '\n';

                }

            }
            else {

                resolver(datos, k + 1, sol, piezasUsadas, haySolucion);

            }

        }
        piezasUsadas[i]--;

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    Datos datos;
    cin >> datos.m >> datos.azules >> datos.rojos >> datos.verdes;

    if (datos.m == 0 && datos.azules == 0 && datos.rojos == 0 && datos.verdes == 0)
        return false;

    vector<string> sol(datos.m, " ");
    vector<int> piezasUsadas(3, 0);

    bool haySolucion = false;

    resolver(datos, 0, sol, piezasUsadas, haySolucion);

    // escribir sol
    if (!haySolucion) cout << "SIN SOLUCION" << '\n';
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
