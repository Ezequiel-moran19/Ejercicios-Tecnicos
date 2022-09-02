#define TARJETA 5
#define BINGO 75

/*
 * biblio-bingo.h
 *
 *  Created on: 1 sep. 2022
 *      Author: moran
 */

#ifndef BIBLIO_BINGO_H_
#define BIBLIO_BINGO_H_



#endif /* BIBLIO_BINGO_H_ */
void escribirCarton(int C[TARJETA][TARJETA], int s[BINGO]);
// recibe una tarjeta c y los números sorteados s y escribe la tarjeta en la pantalla

int verificaVitoria(int C[TARJETA][TARJETA], int s[BINGO]);
// devuelve 1 si la tarjeta está llena y 0 en caso contrario.

int verificaLinea(int C[TARJETA][TARJETA], int s[BINGO]);
// devuelve 1 si hay una fila, columna o diagonal completamente dibujada

int verificaVector(int v[TARJETA], int s[BINGO]);
// devuelve 1 si el vector ya ha sido dibujado
int fSorteo(int s[BINGO]);
