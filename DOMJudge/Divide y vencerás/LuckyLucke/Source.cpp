// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Resultado {

    int pos;
    bool existe;

};

// función que resuelve el problema
Resultado buscarIzq(vector<int> const& v, int ini, int fin, int altura) {

    if (ini == fin) {
        if(v[ini] == altura)
            return { ini, true };
        else return { ini, false };
    }
    if (v[ini] == altura) return { ini, true };

    int m = (ini + fin) / 2;

    if (v[m] == altura) return { m, true };
    else if(v[m] > altura) return buscarIzq(v, ini, m, altura);
    else return buscarIzq(v, m + 1, fin, altura);

}

Resultado buscarDer(vector<int> const& v, int ini, int fin, int altura) {

    if (ini == fin) {
        if (v[ini] == altura)
            return { ini, true };
        else return { ini, false };
    }

    int m = (ini + fin) / 2;

    if (v[m] > altura) return buscarIzq(v, ini, m, altura);
    else return buscarIzq(v, m + 1, fin, altura);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, altura;
    cin >> n >> altura;

    if (!std::cin)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {

        cin >> v[i];

    }

    Resultado izq = buscarIzq(v, 0, n - 1, altura);

    if (izq.existe) {

        cout << izq.pos << " ";

        Resultado der = buscarDer(v, 0, n - 1, altura);

        if (izq.pos < der.pos)
            cout << der.pos;

    }
    else cout << "NO EXISTE";

    // escribir sol
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