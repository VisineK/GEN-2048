#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plateau.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new Plateau();
    connect(p,&Plateau::tableChange,this,&MainWindow::onTableChange);
    //cout << "\t   Bienvenue dans Gen2048. \n\nLes regles sont simples. Arriver a faire 2048\navant qu'une colonne soit remplit entierement,\n    ou avant d'atteindre le 100eme tour." << endl;

    p->init_game(); //On place un premier chiffre de base pour commencer le jeu
    cout << endl << p->toString().toLocal8Bit().data() << endl; //Affiche le plateau dans la console

    //while(true){

    //    p->placement();  //Choix de la colonne et positionnement des chiffres
    //}
    // p->getScrorre();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTableChange()
{
    for (int x = 0; x <= 5; x++){
        for (int y = 0 ; y <= 6; y++){
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QString::number(p->getTabl(x,y)));
            ui->tableWidget->setItem(x,y,item);
            ui->tableWidget->update();
            qDebug()<<"x:"<<x;
            qDebug()<<"y:"<<y;
            qDebug()<<QString::number(p->getTabl(y,x));
        }
    }
    ui->tableWidget->update();
}


void MainWindow::on_pushButton_clicked()
{
    p->placement();
}

void MainWindow::on_chxcol_valueChanged()
{
    Plateau p;
    int t = 0;
    int arg1 = 0;
    QList <int> list_nbr = {2, 2, 2, 2, 4, 2, 8, 2, 2, 16, 2, 8, 2, 4, 16, 2, 2, 8, 2, 2, 4, 4, 8, 8, 16, 8, 8, 2, 16, 2, 8, 2, 2, 8, 16, 2, 8, 8, 4, 8, 8, 2, 2, 4, 2, 2, 4, 16, 2, 8, 8, 4, 2, 2, 16, 16, 4, 16, 4, 8, 2, 16, 8, 2, 16, 8, 2, 16, 4, 16, 8, 4, 8, 16, 4, 4, 16, 16, 8, 4, 2, 16, 4, 8, 4, 2, 16, 8, 2, 4, 8, 4, 4, 8, 2, 16, 8, 16, 16, 4, 0};

    arg1 = (Qand%5)+1;

    for(t = 0; t <= 101; t++){
    int listnbr = list_nbr[t];

    if(arg1 == 1){
        p.insereNombre(listnbr, 0);
    }
    else if(arg1 == 2){
        p.insereNombre(listnbr, 1);
    }
    else if(arg1 == 3){
        p.insereNombre(listnbr, 2);
    }
    else if(arg1 == 4){
        p.insereNombre(listnbr, 3);
    }
    else if(arg1 == 5){
        p.insereNombre(listnbr, 4);
    }
    else{
        cout << "Error : please choose a column between 1 and 5" << endl;
    }
}
}
