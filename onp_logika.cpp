#include <string.h>
#include <QApplication>
#include "funkcje_pomocnicze.h"
#include "walidacja_danych.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "logika.h"
#include "informacje_gui.h"


//plik z najważniejszymi funkcjami, ktore w glownej mierze odpowiadaja
//za dzialanie algorytmu wartosciowania wyrazen rachunku zdan

//z racji tego ze ponizsza funkcja za parametr przyjmuje obiekt typu qstring nie
//dalem jej do funkcji walidujacych dane, gdyz jest to plik C (mógłbym zrobić aby
//tamten plik był plikiem cpp, ale to jednak projekt z jezyka c wiec lepiej jak bedzie wiecej plikow z rozszerzeniem c
int sprawdz_spacje_w_impl_i_rowno(QString wyrazenie_p){                //tu ustawiam przeszten miedzy alternatywa a operandem i koniunkcia a operatorem  (rownowaznosci i implikacji nie ustawiam)
    int dlugosc = wyrazenie_p.length();
    QByteArray wyrazenie_b = wyrazenie_p.toLocal8Bit();
    char *wyrazenie = wyrazenie_b.data();
    int sprawdzam1 = 0;
    int sprawdzam2 = 0;
    for (int i = 0; i< dlugosc; i++){
        sprawdzam1 = 0;
        sprawdzam2 = 0;


        if (wyrazenie[i] == '-'){
            if (wyrazenie[i+1] == '>' && wyrazenie[i-1] == '<'){
                return 1;
            }
        }

        if (wyrazenie[i] == '-'){
            if (wyrazenie[i-1] == '<'){
                return 2;
            }
        }

        if (wyrazenie[i] == '='){
            if (wyrazenie[i+1] != '>'){
                return 1;
            }
        }
        if (wyrazenie[i] == '>'){
            if (wyrazenie[i-1] != '-'){

                sprawdzam1 = 1;
            }


            if(wyrazenie[i-1] != '='){
                sprawdzam2 = 1;

            }
        }

        if (wyrazenie[i] == '<'){
            if (wyrazenie[i+1] != '-'){
                sprawdzam1 = 1;
            }


            if(wyrazenie[i+1] != '='){
                sprawdzam2 = 1;

            }
        }

        if ((sprawdzam1 == 1) && (sprawdzam2 == 1)){
            return 4;
        }


        if (wyrazenie[i] == '='){
            if (wyrazenie[i-1] != '<'){
                return 1;
            }
        }

        if (wyrazenie[i] == '-'){
            if (wyrazenie[i+1] != '>'){
                return 3;
            }
        }


        if (wyrazenie[i] == '/'){
            if (wyrazenie[i+1] == ' '){
                if  (wyrazenie[i+2] == ' '){
                    return 8;
                }
            }
        }

        if (wyrazenie[i] == '/'){
            if ((wyrazenie[i+1] == '^') || (wyrazenie[i+1] == 'v') || (wyrazenie[i+1] == '-') || (wyrazenie[i+1] == '=')){
                return 4;
            }
        }

        if (wyrazenie[i] == 'v'){
            if (wyrazenie[i+1] == ' '){
                if  (wyrazenie[i+2] == ' '){
                    return 7;
                }
            }
        }

        if (wyrazenie[i] == 'v'){
            if (wyrazenie[i-1] == ' '){
                if  (wyrazenie[i-2] == ' '){
                    return 7;
                }
            }
        }


        if (wyrazenie[i] == '^'){
            if (wyrazenie[i-1] == ' '){
                if  (wyrazenie[i-2] == ' '){
                    return 7;
                }
            }
        }

        if (wyrazenie[i] == '^'){
            if (wyrazenie[i+1] == ' '){
                if  (wyrazenie[i+2] == ' '){
                    return 7;
                }
            }
        }


    }
    return 0;
}


char* konwertuj_do_ONP(QString wyrazenie_p){

    int sprawdzenie = sprawdz_spacje_w_impl_i_rowno(wyrazenie_p);

    wyrazenie_p.replace(" ", "");
    int dlugosc = wyrazenie_p.length();

    QByteArray wyrazenie_b = wyrazenie_p.toLocal8Bit();


    char *wyrazenie = wyrazenie_b.data();        /*juz w tej linijce przechodze na standard jezyka C*/


    if (dlugosc == 0){              //potencjalny błąd
        wyrazenie[0] = '9';
        return wyrazenie;
    }

    if (sprawdzenie == 2){
        wyrazenie[0] = '2';
        return wyrazenie;
    }
    if (sprawdzenie == 1){
        wyrazenie[0] = '1';
        return wyrazenie;
    }
    if (sprawdzenie == 3){
        wyrazenie[0] = '3';
        return wyrazenie;
    }
    if (sprawdzenie == 4){
        wyrazenie[0] = '&';
        return wyrazenie;
    }

    if (sprawdzenie == 8){
        wyrazenie[0] = '8';
        return wyrazenie;
    }

    if (sprawdzenie == 7){
        wyrazenie[0] = '7';
        return wyrazenie;
    }


    if (walidacja_danych(wyrazenie, dlugosc)== 0){
        wyrazenie[0] = '&';
        return  wyrazenie;
    }
    if (walidacja_danych(wyrazenie, dlugosc) == 2){
        wyrazenie[0] = '@';
        return  wyrazenie;
    }
    if (walidacja_danych(wyrazenie, dlugosc) == 3){
        wyrazenie[0] = '%';
        return  wyrazenie;
    }
    if (walidacja_danych(wyrazenie, dlugosc) == 4){
        wyrazenie[0] = '!';
        return  wyrazenie;
    }
    if (walidacja_danych(wyrazenie, dlugosc) == 5){
        wyrazenie[0] = '`';
        return  wyrazenie;
    }
    if (walidacja_danych(wyrazenie, dlugosc) == 6){
        wyrazenie[0] = '#';
        return  wyrazenie;
    }
    if (walidacja_danych(wyrazenie, dlugosc) == 7){
        wyrazenie[0] = '$';
        return  wyrazenie;
    }

    /*powyzszy kod lepiej chyba jakby byl w funkcji, ale z drugiej strony przez to, ze jest to na "widoku"
     *  szybko jestem w stanie zrozumiec to co sie dzieje w kodzie, choc intuicja jednak podpowiada mi, że
     *  lepszą praktyką byłoby włozenie to do funkcji*/

   /* if (wyrazenie[0] == '-'){
        printf("test1");
        wyrazenie[0] = '&';
        return  wyrazenie;
    }*/


    int nowa_dlugosc = 0;
    char *wyjscie = (char *) malloc(dlugosc);
    char *stos = (char*)malloc(dlugosc);
    char stos_priorytetow [dlugosc];    /*wczesmniej bylo 100*/
    stos[0] = '#';
    char operatory[7]  = {'/','^','v','-', '=', '(', 0};
    int priorytet[6] = {6,5,4,3,2,1};
    int w=0;
    int s = 0;


    for (int l = 0; l<dlugosc; l++){
        nowa_dlugosc++;


        if((wyrazenie[l] == '>') || (wyrazenie[l] == '<')){
            nowa_dlugosc--;
            continue;

        }

        if (wyrazenie[l] >= 97 && wyrazenie[l] <=122 && wyrazenie[l] != 118){
            wyjscie[w] = wyrazenie[l];
            w++;
        }

        if (((wyrazenie[l] >= 97 && wyrazenie[l] <=122) == 0)||(wyrazenie[l] == 118)){             /*jesli operator*/
            if ((wyrazenie[l] != '(') && (wyrazenie[l] != '(')){
                if (stos[0] == '#'){
                    for(int i = 0; i<7; i++){
                        if (wyrazenie[l] == operatory[i]){
                            stos_priorytetow[s] = priorytet[i];
                            stos[0] = wyrazenie[l];


                        }
                    }

                }

                else if (stos[0] != '#'){
                    for(int i = 0; i<7; i++){
                        if (wyrazenie[l] == operatory[i]){
                            if (priorytet[i] > stos_priorytetow[s]){
                                s++;
                                stos[s] = wyrazenie[l];
                                stos_priorytetow[s] = priorytet[i];
                            }
                            else {
                                while (priorytet[i] <= stos_priorytetow[s]){


                                    wyjscie[w] = stos[s];

                                    stos[s] = '#';
                                    w++;
                                    s--;
                                }

                                s++;
                                stos_priorytetow[s] = priorytet[i];
                                stos[s] = wyrazenie[l];
                            }

                        }

                    }
                }
            }
        }



        if (wyrazenie[l] == '('){
            nowa_dlugosc--;
            if (stos[0] != '#')
                s++;
            stos[s] = wyrazenie[l];
            stos_priorytetow[s] = 1;
        }

        if (wyrazenie[l] == ')'){
            nowa_dlugosc--;
            while (stos[s] != '('){
                wyjscie[w] = stos[s];
                int a;
                a = s -1;

                stos[s] = '#';
                w++;
                s--;
            }
            s--;   /*blad*/
        }


        if (l == (dlugosc-1)){

            while (s >= 0){
                if (stos[s] != '('){
                    wyjscie[w] = stos[s];
                    stos[s] = '#';
                    w++;
                }
                s--;
            }
            break;
        }
    }

    wyjscie = (char *) realloc(wyjscie, (sizeof(char)*(dlugosc+1)));    //trzeba przeanalizowac czy napewno
    wyjscie[nowa_dlugosc] = '\0';
    free(stos);

    return wyjscie;

}   //dobrze zwraca


void czy_to_tautologia(int * wartosc_wyrazenia, int liczba_elementow, int liczba_zmiennych, int** tabela_ze_zmiennymmi, char *tabela_z_nazwami, Ui::MainWindow *ui){

    int tabela_z_kontrprzykladem[liczba_elementow];
    int t=0;

    int pamw = 0;
    int rozmiar_tabeli = liczba_zmiennych * liczba_zmiennych * liczba_elementow;


    QString text;
    QChar chr;

    char tab[rozmiar_tabeli];    /*tu byl ostatni blad*/    /*gdyby jakims cudem wszystkie kontrprzyklady sie nie wyswietlaly to nalezy powiekszyc tą tablice i wpisac jakąś dużą stałą*/
    int ti = 0;
    for(int j = 0; j<liczba_elementow;j++){
        if  (wartosc_wyrazenia[j] == 0){
            tabela_z_kontrprzykladem[t] = j;

            t++;
        }
    }


    if (t==0){
        /* std::string str = "abc";
        QString qstr = QString::fromStdString(str);*/
        //MainWindow::ui->txtRezultat->setText("TO ZDANIE JEST TAUTOLOGIĄ");
        ui->txtRezultat->setText("TO ZDANIE JEST TAUTOLOGIĄ");
    }
    else{
        ui->txtRezultat->setText("TO ZDANIE NIE JEST TAUTOLOGIĄ");
        ui->txtRezultat->append("Kontrprzykład");

        for (int j = 0; j<liczba_elementow; j++){
            for (int i = 0; i<liczba_zmiennych; i++){
                for (int k = 0; k<t; k++){
                    if (j == tabela_z_kontrprzykladem[k]){
                        tab[ti] = tabela_z_nazwami[i];  //0
                        tab[ti + 1] = (tabela_ze_zmiennymmi[i][j] + '0');  //1
                        ti++;//1
                        ti++;   //2

                        if (i == (liczba_zmiennych-1)){
                            for (int w = pamw; w < ti; w++){
                                chr = tab[w];
                                text +=  chr;
                                text += " ";
                                pamw++;
                                if (w % 2 == 0){
                                    text += "=";
                                    text += " ";
                                }
                                if (w+1 == ti){
                                    ui->txtRezultat->append(text);
                                    text = "";
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}



void oblicz(char * wyrazenie, Ui::MainWindow *ui){
    int dlugosc = strlen(wyrazenie);
    char stos[100];                       //to limit mozna zmodyfikowac na przyszlosc*
    int* stos_z_tabelkami[100];
    int s = 0;
    int w = 0;
    int pom;


    char * zmienne = ilosc_zmiennych(wyrazenie, dlugosc);
    int ilosc = strlen(zmienne);

    int *tablica_z_adresami[ilosc];/*fdfsdfdsf*/
    int liczba_elementow = pow(2, ilosc);
    int tablica_wynikowa[liczba_elementow];

    if ((sprawdz_wyrazenie(wyrazenie, ui) != 0)&& (sprawdz_ilosc_zmiennych(ilosc,ui) != 0)){

        zwroc_tabelki(strlen(zmienne),tablica_z_adresami);

        while (wyrazenie[w] != '\0'){
            if (wyrazenie[w] >= 97 && wyrazenie[w] <=122 && wyrazenie[w] != 118) {
                for (int i = 0; i<ilosc; i++){
                    if (wyrazenie[w] == zmienne[i]){
                        stos[s] = wyrazenie[w];

                        stos_z_tabelkami[s] = tablica_z_adresami[i];



                        s++;
                    }
                }


            }
            else if (wyrazenie[w] == '^')
            {
                s--;
                pom = s;
                s--;
                stos_z_tabelkami[s] = sprawdz_koniunkcje(stos_z_tabelkami[s], stos_z_tabelkami[pom],liczba_elementow , tablica_wynikowa);
                s++;
            }
            else if (wyrazenie[w] == 'v')
            {

                s--;
                pom = s;
                s--;
                stos_z_tabelkami[s] = sprawdz_alternatywe(stos_z_tabelkami[s], stos_z_tabelkami[pom],liczba_elementow , tablica_wynikowa);
                s++;

            }
            else if (wyrazenie[w] == '=')
            {

                s--;
                pom = s;
                s--;
                stos_z_tabelkami[s] = sprawdz_rownowaznosc(stos_z_tabelkami[s], stos_z_tabelkami[pom],liczba_elementow , tablica_wynikowa);
                s++;

            }
            else if (wyrazenie[w] == '-')
            {

                s--;
                pom = s;
                s--;
                stos_z_tabelkami[s] = sprawdz_implikacje(stos_z_tabelkami[s], stos_z_tabelkami[pom],liczba_elementow , tablica_wynikowa);
                s++;

            }
            else if (wyrazenie[w] == '/')
            {

                s--;
                stos_z_tabelkami[s] = sprawdz_negacje(stos_z_tabelkami[s],liczba_elementow , tablica_wynikowa);
                s++;
            }

            w++;

            /* for(int j = 0; j<2;j++){
            for(int m = 0; m<8;m++){
                printf("%d %d\n",j, stos_z_tabelkami[j][m]);
                     }
                        }*/
        }

        czy_to_tautologia( stos_z_tabelkami[0], liczba_elementow, ilosc, tablica_z_adresami, zmienne, ui);
    }

}
