#ifndef PLATEAU_H
#define PLATEAU_H

#include <QString>
#define NBLIG 6
#define NBCOL 5

class Plateau
{
private:
    int m_tray[NBLIG][NBCOL];

public:
    //int col;
    Plateau();
    QString toString();
    void init_game();
    void insereNombre(int listnbr, int col);
    void placement();

/*
    int getScrorre() const;
    void setScrorre(int value);
*/
private:
    int scrorre;
};

#endif // PLATEAU_H
