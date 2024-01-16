#ifndef WALIDACJA_DANYCH_H
#define WALIDACJA_DANYCH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef __cplusplus
extern "C" {
#endif
int sprawdz_ulozenie_nawiasow(int dlugosc,int liczba_nawiasow, char * wyrazenie);
int walidacja_danych(char * wyrazenie, int dlugosc);
#ifdef __cplusplus
}
#endif
#endif // WALIDACJA_DANYCH_H
