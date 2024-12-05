#include <iostream>
#include "Morpion.h"
#include "Grille.h"
#include "Joueur.h"
#include "robot.h"

//////////////IL est recommandé de jouer en console externe pour afficher le plateau en couleur//////////

using namespace std;


int main() {
    Morpion Menu;
    Grille Grillage;
    Joueur joueur;
    Joueur joueur1;
    Joueur joueur2;
    RobotRandom robot('M');

    vector<vector<char>> plateau(3, vector<char>(3,' '));
    Grillage.InitialisationGrille(plateau);
    while (true){
        int resultat = Menu.Menu();
        switch (resultat){
            case 1: cout<<"-Nouvelle Partie-"<< endl;
                Grillage.AffichageGrille(plateau,joueur1.GetPion(),joueur2.GetPion());
                joueur.ToursParTours();
                break;
            case 2 : cout<<"-Versus Manuel(Robot)-"<<endl;
                Grillage.AffichageGrille(plateau, joueur1.GetPion(), robot.RecupPion());
                robot.ToursParTours();
                break;
            case 3 : cout<<"-Quitter-"<<endl;
                return 2;
            default:
                cout << "Option invalide, veuillez réessayer." << endl;
                break;
        }

        cout << "Appuyez sur entre pour continuer..." << endl;


    }
}
