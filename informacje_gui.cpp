#include "informacje_gui.h"



int sprawdz_wyrazenie(char * wyrazenie, Ui::MainWindow *ui){
    if (wyrazenie[0] == '&'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Wpisałeś niepoprawne wyrażenie", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '@'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Błąd składni lub brak nawiasów", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '%'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Używaj liter jako zmiennych", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '!'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Używaj ')' oraz '(' ", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '`'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Użyłeś niedozwolonego znaku", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '#'){
        ui->txtRezultat->setText("");
         QMessageBox::warning(0,"Błąd", "Nie dziel wyrazeń ENTEREM", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '$'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Nie używaj spacji", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '1'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Znak równoważności: <=>", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '2'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Użyj: -> i obróć wyrażenie, znak <- jest nieobsługiwany", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '3'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Operator implikacji: ->", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '9'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Nie wpisano wyrażenia", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '8'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Za operatorem negacji może występować jedna spacja", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '7'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Przed i za operatorem alternatywy może występować jedna spacja", QMessageBox::Ok);
        return 0;
    }
    if (wyrazenie[0] == '6'){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Przed i za operatorem koniunkcji może występować jedna spacja", QMessageBox::Ok);
        return 0;
    }
    return 1;
}

int sprawdz_ilosc_zmiennych(int ilosc,  Ui::MainWindow *ui){
    if (ilosc > 5){
        ui->txtRezultat->setText("");
        QMessageBox::warning(0,"Błąd", "Możesz maksymalnie użyć 5 zmiennych", QMessageBox::Ok);
        return 0;
    }
    return 1;
}
