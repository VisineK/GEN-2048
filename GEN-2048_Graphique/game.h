#ifndef GAME_H
#define GAME_H

#include <QString>
#define NBLIG 6
#define NBCOL 5
#include <QObject>

class Plateau:
    public QObject
{
    Q_OBJECT
private:
    int m_tray[NBLIG][NBCOL];

public:
    //int col;
    Plateau();
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
