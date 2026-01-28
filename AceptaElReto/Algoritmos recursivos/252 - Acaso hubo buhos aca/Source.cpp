// Esquema de la entrada: caso de prueba que marca el final
#include <iostream>
#include <string>

using namespace std;

bool palindromo(int i, int j, string frase) {


    if (i >= j) return true;

    while (frase[i] == ' ') i++;
    while (frase[j] == ' ') j--;

    if (tolower(frase[i]) == tolower(frase[j]))
        return palindromo(i + 1, j - 1, frase);
    else return false;

}

bool casoDePrueba() {

    string frase;

    getline(cin, frase);

        if (frase == "XXX")
            return false;
        else {
            
            bool sol = palindromo(0, frase.size() - 1, frase);
            if (sol) cout << "SI";
            else cout << "NO";

            cout << '\n';

            return true;
        }

} // casoDePrueba

int main() {

    while (casoDePrueba())
        ;

    return 0;

} // main
