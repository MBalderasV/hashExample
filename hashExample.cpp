#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <windows.h>

using namespace std;

// Función Hash
int transformarClave(string clave, int totalCajones) {
    int suma = 0;
    for (char letra : clave) {
        suma += letra;
    }
    return suma % totalCajones;
}

// Estructura de Diccionario (Tabla Hash)
class Diccionario {
private:
    int totalCajones;
    // Vector que actúa como el arreglo principal.
    // Cada posición contiene una lista de pares <Clave, Valor> para manejar colisiones.
    vector<list<pair<string, string>>> archivero;

public:
    Diccionario(int tamano) {
        totalCajones = tamano;
        archivero.resize(tamano);
    }

    // Guardar en el diccionario
    void insertar(string clave, string valor) {
        int indice = transformarClave(clave, totalCajones);

        // 1. Revisar si la clave ya existe en la lista de ese índice para actualizarla
        for (auto& elemento : archivero[indice]) {
            if (elemento.first == clave) {
                elemento.second = valor;
                return;
            }
        }

        // 2. Si no existe (o si hay colisión con otras claves), se agrega al final de la lista
        archivero[indice].push_back({ clave, valor });
    }

    // Recuperar del diccionario
    string buscar(string clave) {
        int indice = transformarClave(clave, totalCajones);

        // Buscar linealmente dentro de la lista correspondiente a ese índice
        for (auto& elemento : archivero[indice]) {
            if (elemento.first == clave) {
                return elemento.second;
            }
        }
        return "No encontrado";
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Diccionario miDiccionario(10);

    // Inserción normal
    miDiccionario.insertar("ANA", "Datos de Ana");
    miDiccionario.insertar("PEPE", "Datos de Pepe");

    // Forzando una colisión: "ROMA" y "AMOR" tienen las mismas letras.
    // La suma ASCII será idéntica, resultando en el mismo índice (colisión).
    miDiccionario.insertar("ROMA", "Datos de Roma (Legal)");
    miDiccionario.insertar("AMOR", "Datos de Amor (RH)");

    cout << "--- Búsqueda en el Diccionario ---" << endl;
    cout << "Buscando ANA: " << miDiccionario.buscar("ANA") << endl;
    cout << "Buscando ROMA: " << miDiccionario.buscar("ROMA") << endl;

    // Al buscar "AMOR", el algoritmo va al mismo índice que "ROMA" 
    // y recorre la lista ligada hasta encontrar la clave exacta.
    cout << "Buscando AMOR: " << miDiccionario.buscar("AMOR") << endl;

    // Búsqueda de un elemento inexistente
    cout << "Buscando LUIS: " << miDiccionario.buscar("LUIS") << endl;

    return 0;
}