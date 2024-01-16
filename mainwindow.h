#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnSprawdz_clicked();

    void on_btncofnij_clicked();

    void on_wysunMenu_clicked(bool checked);

    void on_ustawMotyw_clicked(bool checked);

public:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation2;
};
#endif // MAINWINDOW_H
