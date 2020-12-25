#include "../shared/qstd.h"
using namespace qstd;
#include "plateau.h"
#include <QTextStream>
#include <QList>
#include <QString>
#include <cstdlib>


Plateau::Plateau()
{
    //Génère un plateau (= matrice)
    for(int l = 0; l < NBLIG; l++)
        for(int c = 0; c < NBCOL; c++)
            m_tray[l][c] = 0;
}

QString Plateau::toString()
{
    QString res;
    QString temp;
    QTextStream buf(&res);

    buf << "|----------------- GEN 2048 -----------------|" << endl << endl;


    //Affiche les emplacements des nombres
    for(int l = 0; l < NBLIG; l++) {
        for(int c = 0; c < NBCOL; c++) {
            if(m_tray[l][c] == 0)
                buf << " ---- ";
            else {
                temp.sprintf(" %4d ", m_tray[l][c]); //Affiche 4 valeurs
                buf << temp;
            }
        }
        buf << endl;
    }
    return res;
}


void Plateau::init_game()
{
    m_tray[5][2] = 2;
}


void Plateau::insereNombre(int n, int col)
{
    int l = 0;
    // Vérifie si la ligne/colonne = 0 et si on est toujours dans le tableaux
    while(m_tray[l+1][col] == 0 && l < NBLIG)
        l++;
    m_tray[l][col] = n;

    // fusion des lignes
    while(l<NBLIG && m_tray[l][col] == m_tray[l+1][col]) {
        m_tray[l+1][col] *= 2;
        m_tray[l][col] = 0;
        l++;
    }

    /* Ancienne fonction fusion
   if(l<NBLIG-1 && m_tray[l][col]==m_tray[l+1][col]) {
       m_tray[l+1][col]*=2;
       m_tray[l][col]=0;
   }*/
}


void Plateau::placement()
{
    int my_choice = 0;
    int t = 0;
    QList <int> list_nbr = {2, 2, 2, 2, 4, 2, 8, 2, 2, 16, 2, 8, 2, 4, 16, 2, 2, 8, 2, 2, 4, 4, 8, 8, 16, 8, 8, 2, 16, 2, 8, 2, 2, 8, 16, 2, 8, 8, 4, 8, 8, 2, 2, 4, 2, 2, 4, 16, 2, 8, 8, 4, 2, 2, 16, 16, 4, 16, 4, 8, 2, 16, 8, 2, 16, 8, 2, 16, 4, 16, 8, 4, 8, 16, 4, 4, 16, 16, 8, 4, 2, 16, 4, 8, 4, 2, 16, 8, 2, 4, 8, 4, 4, 8, 2, 16, 8, 16, 16, 4, 0};

    for(t = 0; t <= 101; t++){
        int listnbr = list_nbr[t];
        cout << "Nombre suivant : " << listnbr << "\t" << "Nombre de tour : " << t << endl << endl;

        cout << "Choisissez votre colonne : 1, 2, 3, 4 ou 5 ?" << endl;
        my_choice = (qrand()%5)+1;
        cout << my_choice << "\n" ;

        if(my_choice == 1){
            insereNombre(listnbr, 0);
        }
        else if(my_choice == 2){
            insereNombre(listnbr, 1);
        }
        else if(my_choice == 3){
            insereNombre(listnbr, 2);
        }
        else if(my_choice == 4){
            insereNombre(listnbr, 3);
        }
        else if(my_choice == 5){
            insereNombre(listnbr, 4);
        }
        else{
            cout << "Error : please choose a column between 1 and 5" << endl;
        }

        cout << endl << toString() << endl; //Affiche le plateau dans la console

        /* Si on atteint le 100eme tour, alors on a perdu.*/
        if(t == 100){
            char r;
            cout << "Vous avez atteint le 100eme tour. VOUS AVEZ PERDU !" << endl << endl;
            cout << "Voulez vous rejouer ? Y/N" << endl;
            cin >> r >> endl;

            if(r == 'y' || r == 'Y'){
                system("clear");
                cout << "on recommence";
            }
            else if(r == 'n' || r == 'N'){
            }
            system("clear");
            cout << "on arrete";
        }
    }
}
/*

int Plateau::getScrorre() const
{
    return scrorre;
}

void Plateau::setScrorre(int value)
{
    scrorre = value;
}
*/

