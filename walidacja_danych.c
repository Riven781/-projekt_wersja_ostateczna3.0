#include "walidacja_danych.h"

int sprawdz_ulozenie_nawiasow(int dlugosc,int liczba_nawiasow, char * wyrazenie){   //filtruje takie ułożenie nawiasów:   )  (
    char * stos = (char*)malloc(sizeof(char)* liczba_nawiasow);
    int s = 0;
    for (int i = 0; i< dlugosc; i++){
        if (wyrazenie[i] == '('){
            stos[s] = '(';
            s++;
        }
        if (wyrazenie[i] == ')'){
            if (s==0){
                free(stos);  /*nowe*/
                return 0;
            }
            s--;
        }
    }
    free(stos);   /*nowe*/
    /*printf("%d\n", s);*/
    if (s == 0){
        return 1;
    }
    else{
        return 0;
    }

}


int walidacja_danych(char * wyrazenie, int dlugosc)
{

    int warunek1 = 0;
    int warunek2 = 0;
    int licznikNawiasowO = 0;
    int licznikNawiasowZ = 0;
    int liczba_operandow = 0;
    int licznik_operatorow_dwuarg = 0;
    int czy_jest_ENTER = 0;



    char operatory[5]  = {'^','v','-', '='};
    for (int i = 0; i<dlugosc; i++){
        if (wyrazenie[i] >= 97 && wyrazenie[i] <=122 && wyrazenie[i] != 118){
            liczba_operandow++;
        }

        if ((wyrazenie[i] == '^') || (wyrazenie[i] == 'v') || (wyrazenie[i] == '-') || (wyrazenie[i] == '=')){
            licznik_operatorow_dwuarg++;
        }


        if ((wyrazenie[i] >= 97 && wyrazenie[i] <=122 && wyrazenie[i] != 118) && (wyrazenie[i+1] >= 97 && wyrazenie[i+1] <=122 && wyrazenie[i+1] != 118)){
            return 0;
        }

        if (i+2 < dlugosc){
            if ((wyrazenie[i] >= 97 && wyrazenie[i] <=122 && wyrazenie[i] != 118) && (wyrazenie[i+1] == '(' || wyrazenie[i+1] == ')') && (wyrazenie[i+2] >= 97 && wyrazenie[i+2] <=122 && wyrazenie[i+2] != 118)){
                return 0;
            }
        }

        //specjalna_wiadomosc:
        if ((wyrazenie[i] == '/') && (wyrazenie[i+1] == '/')){
            return 2;
        }


        if (wyrazenie [i] == ')'){
            licznikNawiasowZ++;
        }

        if (wyrazenie[i] == '('){
            licznikNawiasowO++;
        }

        if ((wyrazenie[i]== 125) || (wyrazenie[i]== 123) || (wyrazenie[i]== 93 || (wyrazenie[i]== 91)))
            return 4;


        if ((wyrazenie[i] >= 48) && (wyrazenie[i]<= 57)){
            return 3;
        }

        if (wyrazenie[i] == '\n'){
            czy_jest_ENTER++;
        }



        if (czy_jest_ENTER > 0){
            if((wyrazenie[i] >= 97 && wyrazenie[i] <=122 && wyrazenie[i] != 118) || ((wyrazenie[i] == '^') || (wyrazenie[i] == 'v') || (wyrazenie[i] == '-') || (wyrazenie[i] == '='))){
                return 6;
            }
        }


        if ((wyrazenie[i] == 58) || (wyrazenie[i]== 59) ||(wyrazenie[i]== 63) || (wyrazenie[i]== 64) || (wyrazenie[i]== 44) ||(wyrazenie[i]== 46) || (wyrazenie[i]== 95) || (wyrazenie[i]== 92) || (wyrazenie[i]== 96) || (wyrazenie[i]== 124) ||  (wyrazenie[i]== 42) ||  (wyrazenie[i]== 43)){          //niepoprawny znak
            return 5;
        }

        if ((wyrazenie[i] >= 33) && (wyrazenie[i] <= 39)){          //niepoprawny znak
            return 5;
        }

        for (int j = 0; j<4; j++){
            if (wyrazenie[i] == operatory[j]){
                warunek1 = 1;
            }
            if (wyrazenie[i+1] == operatory[j]){
                warunek2 = 1;
            }

        }

        if (warunek1 && warunek2){
            return 0;
        }

        warunek1 = 0;
        warunek2 = 0;



    }

    if (wyrazenie[dlugosc-1] == '/'){
        return 0;
    }

    /*operatorow dwuargumentowych nie moze byc wiecej niz operandow*/

    if ((liczba_operandow == 2) && (licznik_operatorow_dwuarg != 1)){
        return 0;
    }


    if (liczba_operandow <= licznik_operatorow_dwuarg){
        return 0;
    }

    if (licznikNawiasowO != licznikNawiasowZ){
        return 0;
    }

    if(sprawdz_ulozenie_nawiasow(dlugosc, licznikNawiasowO, wyrazenie) == 0){
        return 0;
    }



    return 1;
}
