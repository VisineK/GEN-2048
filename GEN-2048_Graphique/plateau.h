#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>
#include <QString>
//#include "../shared/qstd.h"
#include <iostream>
using namespace std;
#include <QTextStream>
#include <QList>
#include <QString>
#include <cstdlib>
#define NBLIG 6
#define NBCOL 5

class Plateau : public QObject
{
    Q_OBJECT
public:
    explicit Plateau(QObject *parent = nullptr);

private:
    int m_tray[NBLIG][NBCOL];

public:
    //int col;
    QString toString();
    void init_game();
    void insereNombre(int listnbr, int col);
    void placement();
    void score();


    int getScrorre() const;
    void setScrorre(int value);

    int getTabl(int x ,int y);
    void setTable (int x ,int y ,int value);


private:
    int scrorre;

signals:
    void tableChange();
};

#endif // PLATEAU_H
