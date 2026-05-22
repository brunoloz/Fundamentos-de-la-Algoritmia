// Nombre del alumno ..... Bruno Lozano Clemente
// Usuario del Juez ...... FAL-19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema

/*

    Precondición: { p.size() >= 0 && L >= 2 }

*/

int resolver(vector<int> const& p, int L) {

    int longitud = 0;
    int suma_acum = 0;
    int maximo = 0;
    int ini = 0;

    /*
    
    - Invariante: { 0 <= i <= p.size() and maximo = ( max k : 0 <= k < i : p[k] ) }
    
    */

    for (int i = 0; i < p.size(); i++) {

        if (p[i] > maximo) maximo = p[i];

    }

    int cont = 0;

    /*
    
        Invariante: { 0 <= i <= L and suma_acu = (sum k : 0 <= k < i : p[k]) and cont = (#k : 0 <= k < i : p[k] == maximo) } 
    
    */


    for (int i = 0; i < L; i++) {

        suma_acum += p[i];

        if (p[i] == maximo) {
            cont++;
        }
    }


    int max_segmento = -1;
    
    if (cont > 0) {

        max_segmento = suma_acum;

    }



    for (int i = 1; i <= p.size() - L; i++) {

        suma_acum = suma_acum - p[i - 1] + p[i + L - 1];

        if (p[i - 1] == maximo) cont--;
        if (p[i + L - 1] == maximo) cont++;

        if (cont > 0) {


            if (suma_acum >= max_segmento) {

                max_segmento = suma_acum;
                ini = i;

            }

        }

    }

    return ini;

}


/*

    Postcondición: 

*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, L;
    cin >> n >> L;

    if (n == 0 && L == 0)
        return false;

    vector<int> p;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;
        p.push_back(a);

    }

    int sol = resolver(p, L);

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
