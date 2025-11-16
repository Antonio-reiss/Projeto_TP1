#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <cstdlib>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "funcoes.de.controles.hpp"

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return;
}

/**
* @brief Pausa a execução do programa pelo número de segundos especificado.
* @param segundos O tempo de pausa em segundos.
*/
void esperar(int segundos) {
    #ifdef _WIN32
        Sleep(segundos*1000);
    #else
        Sleep(segundos);
    #endif
}
