// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Resultado {

    int tiempo;
    vector<int> v;

};

vector<int> mezclar(const vector<int>& izq, const vector<int>& der, int& contador)
{
    int i = 0;
    int j = 0;
    vector<int> ret;
    while (i < izq.size() && j < der.size()) {
        if (izq[i] < der[j]) {
            ret.push_back(izq[i]);
            i++;
        }
        else {
            ret.push_back(der[j]);
            j++;
            contador += izq.size() - i;

        }
    }
    while (i < izq.size()) {
        ret.push_back(izq[i]);
        i++;
    }
    while (j < der.size()) {
        ret.push_back(der[j]);
        j++;
    }
    return ret;
}

// función que resuelve el problema
Resultado resolver(vector<int>& v, int ini, int fin) {

    if (ini + 1 >= fin) {

        return { 0, vector<int>(1, v[ini]) };

    }

    int m = (ini + fin) / 2;

    Resultado izq = resolver(v, ini, m);
    Resultado der = resolver(v, m, fin);

    int suma = izq.tiempo + der.tiempo;

    vector<int> aux = mezclar(izq.v, der.v, suma);

    return { suma, aux };
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

    Resultado sol = resolver(v, 0 , n);

    // escribir sol
    cout << sol.tiempo << '\n';

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