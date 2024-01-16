#ifndef FUNKCJE_POMOCNICZE_H
#define FUNKCJE_POMOCNICZE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef __cplusplus
extern "C" {
#endif
char* ilosc_zmiennych(char *tab,int dlugosc);
void zwroc_tabelki(int ilosc, int **tablica_z_adresemi_tabel);
char* ilosc_zmiennych(char *tab,int dlugosc);
int * kopiuj_tablice( int*wartosc, int liczba_elementow);
int * sprawdz_koniunkcje(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa);
int * sprawdz_alternatywe(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa);
int * sprawdz_rownowaznosc(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa);
int * sprawdz_implikacje(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa);
int * sprawdz_negacje(int *tablica1, int liczba_elementow, int *tablica_wynikowa);
#ifdef __cplusplus
}
#endif

#endif // FUNKCJE_POMOCNICZE_H
