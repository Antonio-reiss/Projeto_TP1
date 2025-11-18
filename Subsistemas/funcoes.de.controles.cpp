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

void esperar(int segundos) {
    #ifdef _WIN32
        Sleep(segundos*1000);
    #else
        sleep(segundos);
    #endif
}
