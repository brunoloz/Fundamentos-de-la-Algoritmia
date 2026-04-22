//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno: Bruno Lozano Clemente
// Usuario del juez de clase: FAL-J19
// Usuario del juez de examen que has utilizado en la prueba de hoy: FAL-J19
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//*******************************
// Aqui explicacion del algoritmo de vuelta atras. Como es el vector solucion y como se obtiene

// Se utiliza un vector solucion de tamaño 2*n, donde n es el número total de tareas. 
// Cada tarea i (de 0 a n-1) necesita exactamente 2 alumnos, por lo que reservamos
// las posiciones (2*i) y (2*i + 1) del vector para guardar los índices de los alumnos asignados a esa tarea.


// En cada nivel k del árbol de exploración (desde 0 hasta 2*n - 1), intentamos asignar un alumno a un hueco de una tarea.
// La altura del árbol de exploración es de 2n, donde n representa el número de tareas que hay que realizar.

//*******************************

template <class T>
using tMatriz = std::vector<std::vector<T>>;

struct tDatos {
    int numTareas; // Numero de tareas a realizar
    int numAlumnos;  // Numero de alumnos de la clase
    int maxTareas;   // maximo numero de tareas que puede realizar un alumno
    tMatriz<int> preferencias;  // En cada fila las preferencias de cada alumno a cada tarea
};

// Aqui las funciones implementadas por el alumno

void resolver(tDatos const& d, int k, int suma_actual, int& suma_max, vector<int>& sol, vector<int>& tareas_alumno, vector<int> const& maximo_acu) {


    if (k == 2 * d.numTareas) { //si se han asignado dos tareas 

        if (suma_actual > suma_max) {

            suma_max = suma_actual;

        }
       
        return;
    }
    else if (suma_actual + maximo_acu[k] <= suma_max) { //si no se puede mejorar la solucion, se poda
        return;
    }
    else {

        int tarea = k / 2;
        int ini = 0;

        if (k % 2 != 0) { //si estamos en el segundo hueco de una tarea, el alumno asignado debe tener un índice mayor que el asignado en el primer hueco.

            ini = sol[k - 1] + 1;

        }

        for (int i = ini; i < d.numAlumnos; ++i) {

            if (tareas_alumno[i] < d.maxTareas) { //el alumno no puede hacer mas de las t tareas

                sol[k] = i;
                tareas_alumno[i]++;

                resolver(d, k + 1, suma_actual + d.preferencias[i][tarea], suma_max, sol, tareas_alumno, maximo_acu);

                tareas_alumno[i]--;
            }
        }

    }

}



bool resuelveCaso() {
    // Lectura de los datos de entrada
    tDatos d;
    std::cin >> d.numTareas >> d.numAlumnos >> d.maxTareas;
    if (d.numTareas == 0 && d.numAlumnos == 0 && d.maxTareas == 0) return false;
    // lectura de las preferencias
    d.preferencias.resize(d.numAlumnos, std::vector<int>(d.numTareas));
    for (int i = 0; i < d.numAlumnos; ++i)
        for (int j = 0; j < d.numTareas; ++j)
            std::cin >> d.preferencias[i][j];

    vector<int> maximo_tarea(d.numTareas, 0); //guardo el valor maximo de preferencia para cada tarea
    for (int j = 0; j < d.numTareas; ++j) {
        for (int i = 0; i < d.numAlumnos; ++i) {
            if (d.preferencias[i][j] > maximo_tarea[j]) {
                maximo_tarea[j] = d.preferencias[i][j];
            }
        }
    }

    vector<int> maximo_acu(2 * d.numTareas, 0); //guardo la acumulacion de las preferencias maximas
    int acumulado = 0;
    for (int k = 2 * d.numTareas - 1; k >= 0; --k) { 
        acumulado += maximo_tarea[k / 2];
        maximo_acu[k] = acumulado;
    }

    // preparar datos para la llamada a la funcion de VA
    vector<int> sol(2 * d.numTareas, -1);
    vector<int> tareas_alumno(d.numAlumnos, 0);
    int suma_max = -1;

    // LLamada a la funcion de VA
    resolver(d, 0, 0, suma_max, sol, tareas_alumno, maximo_acu);

    // Escribir solucion
    cout << suma_max << '\n';


    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
