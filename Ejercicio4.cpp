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




int main(){
    string palabra1 = "hola";
    string palabra2= "hola";
   // const char* palabra1_ = "hola";
   // const char* palabra2_ = "hola";
   // constexpr bool resultado = sonIgualesConstexpr("Hola mundo", "Hola mundo");
    auto startTime = std::chrono::high_resolution_clock::now();
    sonIguales(palabra1, palabra2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime - startTime);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << "nanosegundos"
    << std::endl; 
    return 0;
}
