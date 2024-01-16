#include "funkcje_pomocnicze.h"


void zwroc_tabelki(int ilosc, int **tablica_z_adresemi_tabel){
    int i =0;
    int pom = 0;
    int pom2 = 0;
    int * zmienna1;
    int * zmienna2;
    int * zmienna3;
    int * zmienna4;
    int * zmienna5;


    int liczba_elementow = pow(2, ilosc);
    if (ilosc >= 0){
        zmienna1 = (int*)malloc(sizeof(int)* liczba_elementow);
        for (i = 0; i<liczba_elementow;i++){
            if (pom < 2){
                zmienna1[i] = 1;
                pom++;
                if (pom == 2){
                    pom2 = 0;
                }
            }
            else if (pom2 < 2){
                zmienna1[i] = 0;
                pom2++;
                if (pom2 == 2){
                    pom = 0;
                }
            }
        }
        tablica_z_adresemi_tabel[1] = zmienna1;

    }

    if (ilosc >= 1){
        zmienna2 = (int*)malloc(sizeof(int)* liczba_elementow);
        for (i=0; i<liczba_elementow;i++){
            if (i % 2 == 0)
                zmienna2[i] = 1;
            else
                zmienna2[i] = 0;
        }
        tablica_z_adresemi_tabel[0] = zmienna2;

    }
    if (ilosc >= 3){
        zmienna3 = (int*)malloc(sizeof(int)* liczba_elementow);
        for (i=0; i<liczba_elementow;i++){
            if (pom < 4){
                zmienna3[i] = 1;
                pom++;
                if (pom == 4){
                    pom2 = 0;
                }
            }
            else if (pom2 < 4){
                zmienna3[i] = 0;
                pom2++;
                if (pom2 == 4){
                    pom = 0;
                }
            }
        }
        tablica_z_adresemi_tabel[2] = zmienna3;
    }

    if (ilosc >= 4){
        zmienna4 = (int*)malloc(sizeof(int)* liczba_elementow);
        for (i=0; i<liczba_elementow;i++){
            if (pom < 8){
                zmienna4[i] = 1;
                pom++;
                if (pom == 8){
                    pom2 = 0;
                }
            }
            else if (pom2 < 8){
                zmienna4[i] = 0;
                pom2++;
                if (pom2 == 8){
                    pom = 0;
                }
            }
        }
        tablica_z_adresemi_tabel[3] = zmienna4;
    }
    if (ilosc >= 5){
        zmienna5 = (int*)malloc(sizeof(int)* liczba_elementow);
        for (i=0; i<liczba_elementow;i++){
            if (pom < 16){
                zmienna5[i] = 1;
                pom++;
                if (pom == 16){
                    pom2 = 0;
                }
            }
            else if (pom2 < 16){
                zmienna5[i] = 0;
                pom2++;
                if (pom2 == 16){
                    pom = 0;
                }
            }
        }
        tablica_z_adresemi_tabel[4] = zmienna5;
    }
}

char* ilosc_zmiennych(char *tab,int dlugosc){

    char*tablica_zmiennych = (char*)calloc(dlugosc, sizeof(char));
    int jest = 0;
    int k = 0;

    for (int i = 0;i<dlugosc;i++){
        jest = 0;
        if (tab[i] >= 97 && tab[i] <=122 && tab[i] != 118 ){      /*tablica jest */
            jest = 0;
            for (int t = 0; t <(dlugosc) ;t++){

                if (tablica_zmiennych[t] == tab[i]){
                    jest = 1;
                }

            }
            if (jest == 0){

                tablica_zmiennych[k] = tab[i];
                k++;

            }
        }
    }
    /*mozna reallocowac tu*/

    return tablica_zmiennych;
}

int * kopiuj_tablice( int*wartosc, int liczba_elementow){
    int i = 0;
    int *nowaTablica = (int*)malloc(sizeof(int)*liczba_elementow);
    for (i=0; i <liczba_elementow;i++){
        nowaTablica[i] = wartosc[i];
    }
    return nowaTablica;
}


int * sprawdz_koniunkcje(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa){
    int * kopia = kopiuj_tablice(tablica_wynikowa, liczba_elementow);

    for (int j = 0; j<liczba_elementow; j++){

        if (tablica1[j] && tablica2[j]){
            kopia[j] = 1;

        }
        else
        {
            kopia[j] = 0;
        }
    }
    return kopia;

}

int * sprawdz_alternatywe(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa){
    int * kopia = kopiuj_tablice(tablica_wynikowa, liczba_elementow);
    for (int j = 0; j<liczba_elementow; j++){

        if (tablica1[j] || tablica2[j]){
            kopia[j] = 1;
        }
        else
        {
            kopia[j] = 0;
        }
    }
    return kopia;
}

int * sprawdz_rownowaznosc(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa){
    int * kopia = kopiuj_tablice(tablica_wynikowa, liczba_elementow);
    for (int j = 0; j<liczba_elementow; j++){

        if (tablica1[j] == tablica2[j]){
            kopia[j] = 1;
        }
        else
        {
            kopia[j] = 0;
        }
    }
    return kopia;
}


int * sprawdz_implikacje(int *tablica1, int *tablica2, int liczba_elementow, int *tablica_wynikowa){
    int * kopia = kopiuj_tablice(tablica_wynikowa, liczba_elementow);
    for (int j = 0; j<liczba_elementow; j++){

        if ((!tablica1[j] || tablica2[j])){
            kopia[j] = 1;
        }
        else
        {
            kopia[j] = 0;
        }
    }
    return kopia;


}

int * sprawdz_negacje(int *tablica1, int liczba_elementow, int *tablica_wynikowa){
    int * kopia = kopiuj_tablice(tablica_wynikowa, liczba_elementow);

    for (int j = 0; j<liczba_elementow; j++){
        if (tablica1[j] == 1){
            kopia[j] = 0;
        }
        else{
            kopia[j] = 1;
        }
    }
    return kopia;

}

