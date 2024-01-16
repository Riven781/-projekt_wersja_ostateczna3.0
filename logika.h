#ifndef LOGIKA_H
#define LOGIKA_H
#include <QApplication>
#include "ui_mainwindow.h"


void czy_to_tautologia(int * wartosc_wyrazenia, int liczba_elementow, int liczba_zmiennych, int** tabela_ze_zmiennymmi, char *tabela_z_nazwami, Ui::MainWindow *ui);

char* konwertuj_do_ONP(QString wyrazenie_p);
void oblicz(char * wyrazenie, Ui::MainWindow *ui);

#endif // LOGIKA_H
