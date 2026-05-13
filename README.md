# Hash Example - Tabla Hash con Manejo de Colisiones

Un programa educativo en C++ que implementa una **tabla hash** usando chaining (encadenamiento) para resolver colisiones. Demuestra conceptos fundamentales de estructuras de datos.

## Descripción

Este proyecto implementa un diccionario basado en tablas hash que:

- **Utiliza hashing**: Convierte claves en índices mediante la suma de valores ASCII
- **Maneja colisiones**: Usa listas ligadas para almacenar múltiples elementos en el mismo índice
- **Permite búsqueda rápida**: Encuentra elementos en O(1) promedio
- **Soporta actualizaciones**: Modifica valores de claves existentes

## Características

### 1. Función Hash
```cpp
int transformarClave(string clave, int totalCajones)
```
- Suma los valores ASCII de todos los caracteres
- Usa módulo para obtener un índice válido
- **Ejemplo**: "ROMA" y "AMOR" producen la misma suma (genera colisión)

### 2. Clase `Diccionario`
Implementa un diccionario con dos operaciones principales:

#### `insertar(string clave, string valor)`
- Agrega o actualiza un par clave-valor
- Si la clave existe, actualiza el valor
- Si no existe, la agrega al final de la lista

#### `buscar(string clave)`
- Busca un elemento por clave
- Retorna el valor si existe
- Retorna "No encontrado" si no existe

## Estructura Interna

```
Tabla Hash (Vector de tamaño 10)
?
??? [0] ? List: [("ANA", "Datos de Ana")]
??? [1] ? List: []
??? [2] ? List: [("ROMA", "Datos de Roma"), ("AMOR", "Datos de Amor")]
??? [3] ? List: [("PEPE", "Datos de Pepe")]
??? [4-9] ? List: []
```

## Requisitos

- **C++14** o superior
- Compilador MSVC (usa `windows.h`)
- Windows (por `SetConsoleOutputCP`)

## Compilación

### Con Visual Studio
```bash
cd hashExample
msbuild hashExample.sln
```

### Con compilador de línea de comandos
```bash
cl /std:c++14 hashExample.cpp
```

## Uso

Ejecuta el programa:
```bash
hashExample.exe
```

### Salida esperada
```
--- Búsqueda en el Diccionario ---
Buscando ANA: Datos de Ana
Buscando ROMA: Datos de Roma (Legal)
Buscando AMOR: Datos de Amor (RH)
Buscando LUIS: No encontrado
```

## Ejemplo de Código

```cpp
#include "hashExample.cpp"

int main() {
    Diccionario miDiccionario(10);

    // Insertar datos
    miDiccionario.insertar("JUAN", "Datos de Juan");
    miDiccionario.insertar("MARIA", "Datos de Maria");

    // Buscar datos
    cout << miDiccionario.buscar("JUAN") << endl;    // "Datos de Juan"
    cout << miDiccionario.buscar("CARLOS") << endl;  // "No encontrado"

    // Actualizar datos
    miDiccionario.insertar("JUAN", "Nuevo dato de Juan");
    cout << miDiccionario.buscar("JUAN") << endl;    // "Nuevo dato de Juan"

    return 0;
}
```

## Conceptos Educativos

### Resolución de Colisiones
Este proyecto usa **chaining** (encadenamiento):
- Cada posición del array es una lista ligada
- Elementos con el mismo hash se almacenan en la misma lista
- Las búsquedas deben recorrer la lista linealmente

### Complejidad

| Operación | Caso Promedio | Caso Peor |
|-----------|---------------|-----------|
| Insertar  | O(1)          | O(n)      |
| Buscar    | O(1)          | O(n)      |
| Factor de carga bajo | ? | ? |

### Limitaciones del Hash Actual

1. **Hash débil**: Solo suma caracteres ASCII
   - Anagramas producen el mismo hash
   - Distribución no uniforme

2. **Sin rehashing**: El tamaño es fijo
   - No crece dinámicamente
   - Factor de carga puede ser alto

3. **Dependencia de plataforma**: Usa `windows.h`
   - No es portable a Linux/Mac

## Mejoras Futuras

- [ ] Implementar mejor función hash (e.g., djb2, FNV-1a)
- [ ] Agregar método `eliminar()`
- [ ] Implementar rehashing dinámico
- [ ] Agregar estadísticas (colisiones, factor de carga)
- [ ] Hacer código multiplataforma
- [ ] Agregar pruebas unitarias

## Licencia

Este proyecto está bajo la licencia especificada en `LICENSE.txt`

## Autor

**Manuel Balderas** - [GitHub Profile](https://github.com/MBalderasV)

---

**Nota**: Este proyecto es de propósito educativo para entender el funcionamiento de tablas hash.