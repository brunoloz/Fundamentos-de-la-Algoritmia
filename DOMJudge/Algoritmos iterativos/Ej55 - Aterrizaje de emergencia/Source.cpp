// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

 /*-Precondición: { v.size() >= 0 and (forAll k : 0 <= k < v.size() : v[k] >= 0) and l >= 2 }

        - Predicados auxiliares :
            esCasiLlana(v, a, b) \equiv(forAll k : a <= k < b : | v[k] - v[k + 1] | < 2)
            esLarga(a, b, l)     \equiv(b - a + 1 >= l)

            esValida(v, a, b, l) \equiv esCasiLlana(v, a, b) and esLarga(a, b, l)

        - Invariante:
            { 0 <= i <= v.size() - 1 and 0 <= ini <= i and
            (forAll k : 0 <= k < sol.size() : 0 <= sol[k] < i) and
            esCasiLlana(v, ini, i) and
            (forAll k : 0 <= k < sol.size() : Existe b : sol[k] <= b < i : esValida(v, sol[k], b, l)) }

        - Función de cota : (v.size() - 1) - i

        - Postcondición :
            { (forAll k : 0 <= k < sol.size() : Existe b : sol[k] <= b < v.size() : esValida(v, sol[k], b, l)) }
*/

// función que resuelve el problema
vector<int> resolver(vector<int> const& v, int l) {

    vector<int> sol;
    int ini = 0;
    int longitud = 0;

    int n = v.size() - 1;

    for (int i = 0; i < n; i++) {

        longitud = i - ini + 1;

        if (abs(v[i] - v[i + 1]) >= 2) {

            if (longitud >= l) sol.push_back(ini);

            ini = i + 1;

        }

    }

    if (v.size() - ini >= l) sol.push_back(ini);


    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, l;
    cin >> n >> l;
    if (n == 0 && l == 0)
        return false;

    vector<int> v;
    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    vector<int> sol = resolver(v, l);

    // escribir sol
    cout << sol.size() << " ";

    for (int i = 0; i < sol.size(); i++) {

        cout << sol[i] << " ";

    }

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
