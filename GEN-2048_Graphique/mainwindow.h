#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plateau.h"
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Plateau* p; //p = classe plateau


public slots:
    void onTableChange();
private slots:
    void on_pushButton_clicked();
    void on_chxcol_valueChanged();
};
#endif // MAINWINDOW_H
