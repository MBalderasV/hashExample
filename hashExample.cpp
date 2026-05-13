#include <iostream>
#include <string>
#include <Windows.h>
//#include <locale>

using namespace std;

// Esta es nuestra función de transformación (Función Hash)
int transformarClave(string clave, int totalCajones) {
    int suma = 0;

    // 1. Recorremos cada letra de la palabra (clave)
    for (char letra : clave) {
        // Al sumar un 'char' a un 'int', C++ usa automáticamente 
        // el valor numérico (ASCII) de la letra.
        suma = suma + letra;
    }

    // 2. Usamos la operación módulo (%) que nos da el residuo de una división.
    // Esto garantiza que el resultado SIEMPRE sea un número entre 0 y (totalCajones - 1).
    int posicionFinal = suma % totalCajones;

    return posicionFinal;
}

int main() {
	//setlocale(LC_ALL, "spanish"); // Configura la localización para soportar caracteres especiales
    SetConsoleOutputCP(CP_UTF8); // Configura la consola para mostrar caracteres UTF-8
    // Imaginemos que tenemos un arreglo o archivero de 10 posiciones (0 al 9)
    int cajones = 10;

    // Nuestras claves a transformar
    string clave1 = "ANA";
    string clave2 = "PEPE";
    string clave3 = "ROBERTO";

    cout << "--- Resultados de la Transformación ---" << endl;

    cout << "La clave '" << clave1 << "' va al cajón: "
        << transformarClave(clave1, cajones) << endl;

    cout << "La clave '" << clave2 << "' va al cajón: "
        << transformarClave(clave2, cajones) << endl;

    cout << "La clave '" << clave3 << "' va al cajón: "
        << transformarClave(clave3, cajones) << endl;

    return 0;
}