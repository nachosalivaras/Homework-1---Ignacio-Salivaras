#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <chrono>


// COMENTARIO DE MI ELECCION Y RESUMEN DEL PROCESO:
/*
En mi primera función no sabía si utilizar `const char*` o `std::string` para realizar la comparación 
entre las dos palabras. Analicé cuál era más conveniente en cuanto a tiempo de compilación y tiempo 
de ejecución. Llegué a la conclusión de que era mejor usar `const char*`, ya que permite hacer la comparación 
en tiempo de compilación, porque no utiliza memoria dinámica como `std::string`. 

Analizando los nanosegundos, el tiempo de compilación es mucho más rápido que el tiempo de ejecución. 
También, desde el punto de vista de la recursividad, `const char*` es mejor en cuanto al espacio que ocupa 
en memoria, ya que me permite comparar carácter por carácter en cada llamado a la función. En cambio, 
`std::string` crea un nuevo objeto en cada llamado a la función, lo que lo hace más pesado en memoria. 
Además, `std::string` usa memoria dinámica, mientras que `const char*` usa memoria estática. 

Probé mi función que recibe `const char*` y medí cuánto tardaba en comparar las palabras en tiempo 
de ejecución y en tiempo de compilación, y noté claramente que en tiempo de compilación es mucho más rápido.
*/


constexpr bool sonIgualesConstexpr(const char* palabra1, const char* palabra2) {
    // Si ambos caracteres actuales son nulos, significa que llegamos al final y son iguales
    if (*palabra1 == '\0' && *palabra2 == '\0') {
        return true;
    }
    // Si los caracteres actuales son diferentes, las palabras no son iguales
    if (*palabra1 != *palabra2) {
        return false;
    }
    // Seguir comparando el siguiente carácter recursivamente
    return sonIgualesConstexpr(palabra1 + 1, palabra2 + 1);
}


bool sonIguales(const char* palabra1, const char* palabra2) {
    if (*palabra1 == '\0' && *palabra2 == '\0') {
        return true;
    }
    if (*palabra1 != *palabra2) {
        return false;
    }
    return sonIguales(palabra1 + 1, palabra2 + 1);
}


int main(){
    const char* palabra1 = "Hola ¿como va? ¿todo bien?";
    const char* palabra2 = "Hola ¿como va? ¿todo bienn?";

    auto startTime1 = std::chrono::high_resolution_clock::now();
    bool resultado1 = sonIguales(palabra1, palabra2);
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto elapsedTime1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime1 - startTime1);

    cout << "Tiempo de ejecución con función normal: " << elapsedTime1.count() << " nanosegundos" << std::endl;
    if (resultado1) 
    cout << "Resultado: Iguales" << endl;
    else 
    cout << "Resultado: Diferentes" << endl;


    constexpr bool resultadoConstexpr = sonIgualesConstexpr("Hola ¿como va? ¿todo bienn?", "Hola ¿como va? ¿todo bien?"); // Literal → se evalúa en compilación

    auto startTime2 = std::chrono::high_resolution_clock::now();
    volatile bool dummy = resultadoConstexpr; // Evita que el compilador lo optimice fuera
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2);

    cout << "Tiempo de ejecución tras comparación en compilación: " << elapsedTime2.count() << " nanosegundos" <<endl;
    if (dummy) 
    cout << "Resultado: Iguales" << endl;
    else 
    cout << "Resultado: Diferentes" << endl;

    return 0;
}
