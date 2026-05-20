// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    - Precondición: { ordenado(v1) ∧ ordenado(v2) ∧ sol.size() == 0 }
      Donde ordenado(v) ≡ (forAll k : 0 <= k < v.size()-1 : v[k] <= v[k+1])

    - Invariante:
      { 0 <= i <= v1.size() ∧ 0 <= j <= v2.size() ∧ ordenado(sol) ∧
        (forAll x : x ∈ sol ≡ (x ∈ v1[0..i-1] ⊕ x ∈ v2[0..j-1])) }

    - Función de cota: (v1.size() - i) + (v2.size() - j)

    - Postcondición: { ordenado(sol) ∧ (forAll x : x ∈ sol ≡ (x ∈ v1 ⊕ x ∈ v2)) }

    - Coste: O(n + m) siendo n y m los tamaños de v1 y v2 respectivamente.
             Es un coste lineal ya que en cada paso del bucle se procesa al menos un elemento.
*/

// función que resuelve el problema
void resolver(vector<int> const& v1, vector<int> const& v2, vector<int>& sol) {

    int i = 0;
    int j = 0;


    while (i < v1.size() && j < v2.size()) {

        if (v1[i] == v2[j]) {
            i++;
            j++;
        }
        else if (v1[i] > v2[j]) {
            sol.push_back(v2[j]);
            j++;
        }
        else if (v1[i] < v2[j]) {
            sol.push_back(v1[i]);
            i++;
        }

    }

    for (int k = i; k < v1.size(); k++) {

        sol.push_back(v1[k]);

    }

    for (int k = j; k < v2.size(); k++) {

        sol.push_back(v2[k]);

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int a;
    cin >> a;

    vector<int> v1;

    while (a != 0) {

        v1.push_back(a);
        cin >> a;
    }

    cin >> a;

    vector<int> v2;

    while (a != 0) {

        v2.push_back(a);
        cin >> a;
    }

    vector<int> sol;
    resolver(v1, v2, sol);
    // escribir sol

    for (int i = 0; i < sol.size(); i++) {

        cout << sol[i] << " ";

    }

    cout << '\n';

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