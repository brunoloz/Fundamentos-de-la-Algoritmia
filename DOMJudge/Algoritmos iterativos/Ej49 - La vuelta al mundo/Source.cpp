// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema

/*

    - Precondición: { v.size >= 0 }

    - Invariante: { - 1 <= i < v.size() and suma = sum k : i < k < v.size() : v[k] and (forAll k : i < k < v.size() : dias[k] == sum j : k <= j < v.size() : v[j]) }

    - Funcion de cota: i + 1

    - Postcondición: { dias.size() == v.size() and (forAll k : 0 <= k < v.size() : dias[k] == sum j : k <= j < v.size() : v[j]) }

    - Coste: O(n)
*/


vector<long long> resolver(vector<long long> const& v) {

    vector<long long> dias(v.size(), 0);

    long long suma = 0;

    for (int i = v.size() - 1; i >= 0; i--) {

        suma += v[i];
        dias[i] = suma;

    }

    return dias;


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;

    vector<long long> etapas;

    for (int i = 0; i < n; i++) {

        long long a;
        cin >> a;
        etapas.push_back(a);

    }

    int d;
    cin >> d;
    
    vector<long long> sol = resolver(etapas);

    for (int i = 0; i < d; i++) {

        int b;
        cin >> b;
        
        if (b - 1 < sol.size())
            cout << sol[b - 1] << '\n';
        else cout << 0 << '\n';

    }

    cout << "---" << '\n';

    // escribir sol

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
