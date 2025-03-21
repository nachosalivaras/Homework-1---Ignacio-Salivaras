#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <chrono>

bool sonIguales(string palabra1, string palabra2){
    if (palabra1.size() != palabra2.size()){
        return false;
    }

    if (palabra1.empty()) {  
        return true;
    }
    if (palabra1[0] != palabra2[0]) {  
        return false;
    }
    return sonIguales(palabra1.substr(1), palabra2.substr(1));


}

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
    // Si ambos caracteres actuales son nulos, significa que llegamos al final y son iguales
    if (*palabra1 == '\0' && *palabra2 == '\0') {
        return true;
    }
    // Si los caracteres actuales son diferentes, las palabras no son iguales
    if (*palabra1 != *palabra2) {
        return false;
    }
    // Seguir comparando el siguiente carácter recursivamente
    return sonIguales(palabra1 + 1, palabra2 + 1);
}




int main(){
    const char* palabra1 = "hola";
    const char* palabra2 = "hola";

    auto startTime1 = std::chrono::high_resolution_clock::now();
    bool resultado1 = sonIguales(palabra1, palabra2);
    auto endTime1 = std::chrono::high_resolution_clock::now();
    auto elapsedTime1 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime1 - startTime1);

    std::cout << "Tiempo de ejecución con función normal: " << elapsedTime1.count() << " nanosegundos" << std::endl;



    constexpr bool resultadoConstexpr = sonIgualesConstexpr("hola", "hola"); // Literal → se evalúa en compilación

    auto startTime2 = std::chrono::high_resolution_clock::now();
    volatile bool dummy = resultadoConstexpr; // Evita que el compilador lo optimice fuera
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2);

    std::cout << "Tiempo de ejecución tras comparación en compilación: " << elapsedTime2.count() << " nanosegundos" << std::endl;


    return 0;
}
