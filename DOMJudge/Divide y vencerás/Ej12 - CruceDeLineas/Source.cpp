// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-J19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Resultado {

    bool cruce;
    int valor1;
    int valor2;
    int p1;
    int p2;

};

// función que resuelve el problema
Resultado resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) {

    if (ini == fin) {

        if (v1[ini] > v2[ini]) return { false,v1[ini], v2[ini], ini - 1, ini};
        else if (v1[ini] == v2[ini]) return { true, v1[ini], v2[ini], ini, ini };
        else return { false, v1[ini], v2[ini], fin, fin + 1};

    }

    int m = (ini + fin) / 2;

    Resultado izq = resolver(v1, v2, ini, m);
    Resultado der = resolver(v1, v2, m + 1, fin);

    if (izq.cruce) return { true, izq.valor1, izq.valor2, izq.p1, izq.p2 };
    else {

        if (izq.valor1 > izq.valor2) return { false, izq.valor1, izq.valor2, izq.p1, izq.p2 };

    }

    if (der.cruce) return { true, izq.valor1, izq.valor2, der.p1, der.p2 };
        
    
    return { false, der.valor1, der.valor2, der.p1, der.p2 };

    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < n; i++) cin >> v2[i];


    Resultado sol = resolver(v1, v2, 0, n-1);

    // escribir sol
    if (sol.cruce) cout << "SI " << sol.p1;
    else cout << "NO " << sol.p1 << " " << sol.p2;

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
