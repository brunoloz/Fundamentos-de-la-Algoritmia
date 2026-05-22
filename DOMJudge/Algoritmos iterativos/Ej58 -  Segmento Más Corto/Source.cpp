// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
* 
*   - numTrues(v, a, b) = #k : a <= k <= b : v[k] == true
*   - longitud(v, a, b) = b - a + 1 

    - Precondición: { 0 <= v.size < 100 and k > 0 }

    - Invariante: { 0 <= i <= v.size() and 0 <= ini < i and longitud_minima = min (v.size + 1, b - a + 1 : 0 <= a <= b < i : numTrues(v, a, b) == k }

    - Funcion de cota: v.size() - i

    - Postcondicion: { longitud_minima = min ( v.size + 1, b - a + 1 : 0 <= a <= b < v.size() : numTrues(v, a, b) == k }

    - El orden d complejidad de este algoritmo es de O(n) siendo n el numero de elementos del vector, ya que se necesita recorrer todas las posiciones del vector para obtener la solución
*/

// función que resuelve el problema
int resolver(vector<int> const& v, int k) {

    int i = 0;
    int cont = 0;
    int ini = 0;

    int longitud_min = v.size();
    bool existe = false;

    for (int i = 0; i < v.size(); i++) {

        if (v[i] == true) {
            cont++;
        }

        while ((cont > k  || (cont == k && v[ini] == false)) && ini <= i) {

            if (v[ini] == true) {
                cont--;
            }

            ini++;
        }

        if (cont == k) {

            existe = true;
            int longitud_actual = i - ini + 1;
            if (longitud_actual < longitud_min)
                longitud_min = longitud_actual;
            

        }

    }

    if (existe)
        return longitud_min;
    else return longitud_min + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;
    if (n == -1)
        return false;

    vector<int> v;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    int k;
    cin >> k;

    int sol = resolver(v, k);

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
