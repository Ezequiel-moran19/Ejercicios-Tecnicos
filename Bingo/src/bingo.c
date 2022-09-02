/*
 ============================================================================
 Name        : bingo.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblio-bingo.h"

int main(){

    int carton[TARJETA][TARJETA] = {
    {1,16,31,51,62},
    {2,18,32,52,63},
    {3,20,33,55,64},
    {4,21,38,56,65},
    {6,22,39,58,66}};

    int sorteados[BINGO] = {0}; // dibujado[i] vale 1 si el número i ya ha sido sorteado

    int gano = 0;
    int lineas = 0;
    int bolilla;

    while (gano == 0){
        bolilla = fSorteo(sorteados);

        printf("el numero fue sorteado %d\n",bolilla);

        sorteados[bolilla] = 1; // confirmación de que el valor de la bolilla ha sido sorteada

        if (lineas == 0){
            if (verificaLinea(carton, sorteados) == 1){
                printf("hizo el quinto!\n");
                lineas = 1;
            }
        }

        gano = verificaVitoria(carton,sorteados);
        if (gano == 1){
            printf("Carton lleno !!!!\n");
        }

        escribirCarton(carton,sorteados);

        system("pause");
    }
    return 0;
}

