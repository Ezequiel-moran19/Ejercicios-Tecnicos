/*
 * funciones-bingo.c
 *
 *  Created on: 1 sep. 2022
 *      Author: moran
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblio-bingo.h"


void escribirCarton (int C[TARJETA][TARJETA], int s[BINGO]){
    int i,j;

    for (i=0;i < TARJETA;i++){
        for(j=0;j < TARJETA;j++){
            if (s[C[i][j]] == 1)
                printf(" * ");
            else
                printf(" %d ",C[i][j]);
        }
        printf("\n");
    }
}

int verificaVitoria(int C[TARJETA][TARJETA], int s[BINGO]){
    int i,j;

    for(i=0;i < TARJETA;i++){
        for(j=0;j < TARJETA;j++){
            if (s[C[i][j]] == 0)
                return 0; // si la casa no fue dibujada, la tarjeta no está llena
        }
    }
    return 1; // si llegaste aqui es porque todas las casas estaban dibujadas
}


int verificaLinea(int C[TARJETA][TARJETA], int s[BINGO]){
    int i,j;

    // verifica las líneas en la tarjeta
    for (i=0;i < TARJETA;i++){
        if (verificaVector(C[i],s) == 1)
            return 1;
    }

    //verifica las columnas
    int vAux[TARJETA] = {0};

    for (j=0;j < TARJETA;j++){
        for (i=0;i < TARJETA;i++){
            vAux[i] = C[i][j];
        }
        if (verificaVector(vAux,s) == 1)
            return 1;
    }

    // verificando diagonal principal
    for (i=0;i < TARJETA;i++){
        vAux[i] = C[i][i];
    }
    if (verificaVector(vAux,s) == 1)
        return 1;

    //verificando la otra diagonal
    for (i=0;i < TARJETA;i++){
        vAux[i] = C[i][TARJETA-1-i];
    }
    if (verificaVector(vAux,s) == 1)
        return 1;

    return 0; // no hay esquina

}

int verificaVector(int v[TARJETA], int s[BINGO]){
    int i;
    for (i=0;i < TARJETA;i++){
        if (s[v[i]] == 0)
            return 0;
    }
    return 1;
}

int fSorteo(int s[BINGO]){
    int r;
    int nuevo = 0;
    srand(time(NULL));
    while (nuevo == 0){
        r = rand() % BINGO;
        printf("%d\n",r);
        if (s[r] == 0){
            nuevo = 1;
        }
    }
    return r;
}

