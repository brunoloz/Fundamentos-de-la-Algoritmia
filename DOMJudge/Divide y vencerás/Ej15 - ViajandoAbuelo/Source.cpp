// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool es_posible(vector<int> const& v, int tiempo, int p) {

    int cont = 0;
    int suma_acu = 0;

    for (int i = 0; i < v.size(); i++) {

        if (suma_acu + v[i] > tiempo) {
            cont++;
            suma_acu = v[i];
        }
        else suma_acu += v[i];

    }

    if (cont > p) return false;
    else return true;

}

// función que resuelve el problema
int resolver(vector<int> const& v, int ini, int fin, int p) {

    if (ini >= fin) return ini;

    int m = (ini + fin) / 2;

    if (es_posible(v, m, p)) {

        return resolver(v, ini, m, p);

    }
    else return resolver(v, m + 1, fin, p);


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, p;
    cin >> n >> p;

    if (n == 0 && p == 0)
        return false;

    vector<int> v(n);

    int maximo = 0, minimo = 0;

    for (int i = 0; i < n; i++) {

        cin >> v[i];
        if (v[i] > minimo) minimo = v[i];
        maximo += v[i];

    }



    int sol = resolver(v, minimo, maximo, p);

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
