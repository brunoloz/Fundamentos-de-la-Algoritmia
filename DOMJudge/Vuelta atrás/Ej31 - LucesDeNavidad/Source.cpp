// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Datos {

    int m;
    int n;
    int consumo;
    vector<int> consumoBombillas;


};

bool esValida(vector<int> const& sol, int k, vector<int> const& luzUsada) {
    
    int maximo = 0;
    int n = luzUsada.size();
    int index_max = -1;
    int total = 0;

    for (int i = 0; i < n; i++) {

        if (luzUsada[i] > maximo) {
            maximo = luzUsada[i];
            index_max = i;
        }
        total += luzUsada[i];
    }

    int suma_resto = total - maximo;

    if (maximo >= suma_resto + 2) return false;

    if (k > 2) {

        if (sol[k - 2] == sol[k - 1] && sol[k - 1] == sol[k]) return false;

    }

    return true;

}

bool noEsSuperior(vector<int>& sol, vector<int> const& consumoBombillas, int max_consumo) {


    int consumo_total = 0;



    for (int i = 0; i < sol.size(); i++) {

        int a = sol[i];
        consumo_total += consumoBombillas[a];

    }

    if (consumo_total > max_consumo) return false;

    return true;

}

// función que resuelve el problema
void resolver(Datos const& datos, int k, vector<int>& sol, vector<int>& luzUsada, bool& haySolucion, int& cont) {

    for (int i = 0; i < datos.n; i++) {

        sol[k] = i;
        luzUsada[i]++;

        if (esValida(sol, k, luzUsada)) {

            if (datos.m - 1 == k) {

                if (noEsSuperior(sol, datos.consumoBombillas, datos.consumo)) {

                    haySolucion = true;
                    cont++;

                  /*  for (int i = 0; i < sol.size(); i++) {
                        cout << sol[i] << " ";
                    }

                    cout << '\n';*/

                }


            }
            else {

                resolver(datos, k + 1, sol, luzUsada, haySolucion, cont);

            }

        }

        luzUsada[i]--;

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Datos datos;
    cin >> datos.m >> datos.n >> datos.consumo;
    if (datos.m == 0)
        return false;


    for (int i = 0; i < datos.n; i++) {

        int valor;
        cin >> valor;
        datos.consumoBombillas.push_back(valor);

    }

    vector<int> sol(datos.m, -1);
    vector<int> luzUsada(datos.n, 0);

    bool haySolucion = false;
    int cont = 0;
    resolver(datos, 0, sol, luzUsada, haySolucion, cont);

    


    // escribir sol

    cout << cont;


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
