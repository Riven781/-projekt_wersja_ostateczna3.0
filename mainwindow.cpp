#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logika.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QDir>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    ui->btncofnij->setIcon(QIcon("./icons8-back-24"));
    ui->wysunMenu->setIcon(QIcon("./setting.png"));

    ui->ustawMotyw->setVisible(false);
    ui->ustawienia->setVisible(false);

    ui->wysunMenu->setCheckable(true);

    animation = new QPropertyAnimation(ui->listawysuwana, "geometry");
    animation2 = new QPropertyAnimation(ui->listawysuwana, "geometry");
    animation->setDuration(30);
    animation->setStartValue(ui->listawysuwana->geometry());
    animation->setEndValue(QRect(-10,-10,130,510));
    animation2->setEndValue(QRect(-10,-10,30,510));

    this->setWindowIcon(QIcon("./puzzle.ico"));


    this->setWindowTitle("Kalkulator rachunku zdań");

    QPalette pal = QPalette();

    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(pal);
    ui->centralwidget->show();

    ui->txtRezultat->setStyleSheet("background-color: #50e8ff");   //powinienem jeszcze font zmienic ale dziala bez tego
    ui->txtWyrazenie->setStyleSheet("background-color: #50e8ff");

    ui->btnSprawdz->setStyleSheet("background-color: #ffffff");

    ui->listawysuwana->setStyleSheet("background-color:#ffffff");
    ui->ustawienia->setStyleSheet("color: #000000");

    ui->wysunMenu->setStyleSheet("background-color: #ffffff");

    ui->btnSprawdz->setDefault(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}



QString textr;
QString text_ostatni;
QString result;
char *wyrazenie;
int *wartosc;
QStringList wyrazenia {""};

int i = 0;
int b = 0;


void MainWindow::on_btnSprawdz_clicked()
{



    //Ui::MainWindow *ui2 = ui;
    textr = ui->txtWyrazenie->toPlainText();
    if (!(wyrazenia.contains(textr)))
    {
        wyrazenia.append(textr);
        b++;
    }
    i=b;





    wyrazenie = konwertuj_do_ONP(textr);
    oblicz(wyrazenie, ui);
}




void MainWindow::on_btncofnij_clicked()
{

    int result = wyrazenia[i].compare("");
    if (i > 0)
        i--;
    if (result != 0){
        ui->txtWyrazenie->setText(wyrazenia[i]);
        ui->txtRezultat->setText("");



        }

}


void MainWindow::on_wysunMenu_clicked(bool checked)
{
    if (checked) {
        animation->start();
        ui->ustawMotyw->setVisible(true);
        ui->ustawienia->setVisible(true);

    }
    else{
        animation2->start();
        ui->ustawienia->setVisible(false);
        ui->ustawMotyw->setVisible(false);

    }
}


void MainWindow::on_ustawMotyw_clicked(bool checked)
{
    if (checked){   //tu sie sciemnia
        QPalette pal = QPalette();
        pal.setColor(QPalette::Window, "#3a3a3a");
        ui->centralwidget->setAutoFillBackground(true);
        ui->centralwidget->setPalette(pal);
        ui->centralwidget->show();

        ui->txtRezultat->setStyleSheet("background-color: #444444 ; color : #ffffff");
        ui->txtWyrazenie->setStyleSheet("background-color: #444444 ; color : #ffffff");

        ui->btnSprawdz->setStyleSheet("background-color:#5a5959");

        ui->listawysuwana->setStyleSheet("background-color:#5a5959");

        ui->ustawienia->setStyleSheet("color: #ffffff");

        ui->wysunMenu->setStyleSheet("background-color: #5a5959");








    }
    else{
        QPalette pal = QPalette();
        pal.setColor(QPalette::Window, "#2cf0f0");

        ui->centralwidget->setAutoFillBackground(true);
        ui->centralwidget->setPalette(pal);
        ui->centralwidget->show();

        ui->txtRezultat->setStyleSheet("background-color: #50e8ff");   //powinienem jeszcze font zmienic ale dziala bez tego
        ui->txtWyrazenie->setStyleSheet("background-color: #50e8ff");

        ui->btnSprawdz->setStyleSheet("background-color: #ffffff");

        ui->listawysuwana->setStyleSheet("background-color:#ffffff");
        ui->ustawienia->setStyleSheet("color: #000000");

        ui->wysunMenu->setStyleSheet("background-color: #ffffff");
    }
}

