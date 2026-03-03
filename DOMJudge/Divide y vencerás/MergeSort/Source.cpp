// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void mezcla(vector<int>& v, int ini, int m, int fin) {

    int ni = m - ini + 1;
    int nd = fin - m;

    vector<int> v_izq(ni);
    vector<int> v_der(nd);

    for (int i = 0; i < ni; i++) {
        v_izq[i] = v[ini + i];
    }

    for (int j = 0; j < nd; j++) {
        v_der[j] = v[m + 1 + j];
    }

    int i = 0, j = 0, k = ini;

    while (i < ni && j < nd) {
        if (v_izq[i] <= v_der[j]) { 
            v[k] = v_izq[i];
            i++;
        }
        else {
            v[k] = v_der[j];
            j++;
        }
        k++;
    }

    // Vaciar restantes
    while (i < ni) {
        v[k] = v_izq[i];
        i++; k++;
    }
    while (j < nd) {
        v[k] = v_der[j];
        j++; k++;
    }
}

// función que resuelve el problema
void merge_sort(vector<int>& v, int ini, int fin) {

    if (ini >= fin) return;

    int m = (ini + fin) / 2;

    merge_sort(v, ini, m);
    merge_sort(v, m + 1, fin);
    mezcla(v, ini, m, fin);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;
    if (!std::cin)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {

        cin >> v[i];

    }

    merge_sort(v, 0, n - 1);

    // escribir sol
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";


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