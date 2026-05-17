// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*

    - Precondición: { datos.size >= 0 }

    - sinTresCrecientes(a, b) = (forAll k : a <= k <= b - 2 : !(datos[k] < datos[k+1] && datos[k+1] < datos[k+2]))

    - Invariante: { 1 <= i <= datos.size() and max_longitud = (max a , b : 0 <= a <= b < i and sinTresCrecientes(a,b) : b - a + 1) }
        Donde longitudVentana(i,j) = (forAll i, j : 0 <= i <= j < datos.size() : j - i + 1 : cont <= 3) 

    - Funcion de cota: n - i

    - Postcondición: { max a, b : 0 <= a <= b < datos.size() and sinTresCrecientes(a,b) : b - a + 1 }

    - Coste: O(n)

*/

// función que resuelve el problema
int resolver(vector<int> const& datos) {

    int ini = 0;
    int fin = datos.size() - 1;

    if(datos.size() < 3) return datos.size();

    int max_longitud = 1;
    int cont = 1;

    for (int i = 1; i < datos.size(); i++) {

        if (datos[i] > datos[i - 1]) cont++;
        else cont = 1;

        if (cont == 3) {
            ini = i - 1;
            cont--;
        }

        int longitud_actual = i - ini + 1;
        if (longitud_actual > max_longitud) {
            max_longitud = longitud_actual;
        }
    }

    return max_longitud;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        v.push_back(a);

    }

    int sol = resolver(v);
    // escribir sol
    cout << sol << '\n';

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