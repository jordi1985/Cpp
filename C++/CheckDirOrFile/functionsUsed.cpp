#include <iostream>
#include <dirent.h>
#include "functionsUsed.hpp"
using namespace std;

bool dir_exist (string dir){
    DIR * directorio;
    if (directorio = opendir(dir.c_str())) {
        closedir(directorio);
        return true;
    } else {
        return false;
    }
}

bool file_exist (string file){
    FILE * archivo;
    if (archivo = fopen(file.c_str(), "r")) {
        fclose(archivo);
        return true;
    } else {
        return false;
    }
}

int mostrar (){
    cout << "Escribe directorio y/o archivo (teclea 'exit' para salir): "<< endl;
    string entrada;
    getline(cin, entrada);
    if (entrada == "exit") return 0;
    if (dir_exist(entrada)) cout << "La carpeta existe"<< endl;
    else if(file_exist(entrada)) cout << "El archivo existe" << endl; 
    else cout << "La carpeta o archivo no existe" << endl;
    mostrar ();
}