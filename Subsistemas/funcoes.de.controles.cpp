#include "funcoes.de.controles.hpp"
#include <cstdlib>
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define WIN32_EXTRA_LEAN
#define NOMINMAX

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

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
