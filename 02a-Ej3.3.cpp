#include <iostream>
#include <string>
#include <bitset>

using namespace std;


bool validarBits(int bits) {
    return bits == 16 || bits == 32 || bits == 64;
}

int multiplicar(int multiplicando, int multiplicador, int bits) {
    int resultado = 0;
    int multiplicandoAbs = abs(multiplicando);
    int multiplicadorAbs = abs(multiplicador);

    for (int i = 0; i < bits; i++) {
        if (multiplicadorAbs & 1) {
            resultado += multiplicandoAbs;
        }
        multiplicandoAbs <<= 1;
        multiplicadorAbs >>= 1;
    }

    return (multiplicando < 0) ^ (multiplicador < 0) ? -resultado : resultado;
}

string convertirABinario(int n, int bits) {
    return bitset<64>(n).to_string().substr(64 - bits); 
}

int main() {
    string continuar = "Y";

    while (continuar == "Y") {
        int number1, number2, cantBits;
        cout << "Ingresar cantidad de bits (16, 32, 64): ";
        cin >> cantBits;

        if (!validarBits(cantBits)) {
            cout << "Cantidad de bits invalida. Debe ser 16, 32 o 64." << endl;
            continue;
        }

        cout << "Ingrese el primer numero (decimal): ";
        cin >> number1;

        cout << "Ingrese el segundo numero (decimal): ";
        cin >> number2;

        int producto = multiplicar(number1, number2, cantBits);

        cout << "\"A\" en binario: " << convertirABinario(number1, cantBits) << endl;
        cout << "\"B\" en binario: " << convertirABinario(number2, cantBits) << endl;
        cout << "Resultado de la multiplicacion: " << producto << endl;
        cout << "Resultado en binario: " << convertirABinario(producto, cantBits) << endl;

        cout << "Continuar? (Y/N): ";
        cin >> continuar;

        while (continuar != "Y" && continuar != "N") {
            cout << "Entrada invalida. Por favor, ingrese Y o N: ";
            cin >> continuar;
        }
    }

    return 0;
    
}
