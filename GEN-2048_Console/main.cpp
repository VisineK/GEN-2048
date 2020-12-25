#include "../shared/qstd.h"
using namespace qstd;
#include "plateau.h"

int main() {
    Plateau p; // p est la classe Plateau()

    cout << "\t   Bienvenue dans Gen2048. \n\nLes regles sont simples. Arriver a faire 2048\navant qu'une colonne soit remplit entierement,\n    ou avant d'atteindre le 100eme tour." << endl;

    p.init_game(); //On place un premier chiffre de base pour commencer le jeu
    cout << endl << p.toString() << endl; //Affiche le plateau dans la console

    while(true){

        p.placement();  //Choix de la colonne et positionnement des chiffres
    }
    /*
    p.getScrorre();
    */
}
