#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Ejercicio 2 a)

enum TipoEvento {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    SECURITY,
};

string NombreEvento(TipoEvento evento) {
    switch (evento) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        case SECURITY : return "SECURITY"; 
        default: return "UNKNOWN";
    }
}


void logMessage(string mensaje, TipoEvento evento){
    
    ofstream outFile("logMessagge.txt");
    if (outFile.is_open()) { 
    outFile << "[" << NombreEvento(evento) << "]" << " " << "<" << mensaje<< ">"<< endl;
    outFile.close();
    } else
    cerr << "Error abriendo el archivo!\n";

}

// b)

//ii 

void logMessage(string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream outFile("logMessagge.txt");
    if (outFile.is_open()) { 
    outFile << " " << "<" << Mensage_de_Error << "> " 
    << "Archivo: " << Archivo << ", Línea: " 
    << Línea_de_Código << endl;
    outFile.close();
    } else
    cerr << "Error abriendo el archivo!\n";
}

//iii.
void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream outFile("logMessagge.txt");
    if (outFile.is_open()) { 
    outFile << "[" << NombreEvento(SECURITY) <<  "] " << "<" << Mensaje_De_Acceso << "> " 
    << "Usuario: " << Nombre_de_Usuario << endl;
    outFile.close();
    } else
    cerr << "Error abriendo el archivo!\n";

}

// iv.

int verificafuncionalidad(){
    try {
        int x = 10, y = 0;
        if (y == 0) { 
            throw "Division por zero!";
        }
        int result = x / y;  
        cout << "El resultado es: " << result << endl;
        } catch (const char* e) { 
            logMessage(string(e), ERROR);
            std::cout << "Error capturado" << std::endl;
            return 1;
        }
        return 0;
        }
        


int main(){
    verificafuncionalidad();
    return 0;
}
