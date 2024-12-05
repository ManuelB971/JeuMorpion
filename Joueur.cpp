#include "Joueur.h"
#include "iostream"
#include "Grille.h"


using namespace std;

char Joueur::Demanderchoix (int joueurNum, char autrepion){
    char choix;
    bool valide = false;
    while (!valide){
        cout<<"Joueur "<< joueurNum << " choisir votre pion"<< endl;
        cin>>choix;

        if (isalpha(choix) && choix != ' '){
            if (choix == autrepion) {
                cout << "Ce pion déjà choisi par l'autre joueur." << endl;
            } else {
                valide = true;
            }
        } else {
            cout <<"Caractere invalide entrez une lettre! "<<endl;
        }

    }
    return choix;
}
bool Joueur::TesterVictoire(char pion, vector<vector<char>>& plateau){
    for (int i = 0; i < 3; i++) {
        if (plateau[i][0] == pion && plateau[i][1] == pion && plateau[i][2] ==pion){
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (plateau[0][j] == pion && plateau[1][j] == pion && plateau[2][j] == pion){
            return true;
        }
    }
    if (plateau[0][0] == pion && plateau[1][1] == pion && plateau[2][2] == pion){
        return true;
    }
    if (plateau[0][2] == pion && plateau[1][1] == pion && plateau[2][0] == pion){
        return true;
    }
    return false;
}


bool Joueur::CaseValide(int x, int y, const vector<vector<char>>& plateau) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || plateau[x][y] !=' ') {
        printf("case invalide\n");
        return false;
    }
    return true;
}
char Joueur::GetPion() const {
    return pion;
}

void Joueur::PlacerPion(vector<vector<char>>& plateau) {
    int x = 0, y = 0;
    do {
        cout<<"En quelle coordonnees voulez-vous jouer ? " <<endl;
        cout<<"ligne :" <<endl;
        cin>>x ;
        cout<<"Rangee :" <<endl;
        cin>>y ;

        x -= 1;
        y -= 1;
    }while (!CaseValide(x, y, plateau));

    plateau[x][y] = pion;

}



void Joueur::ToursParTours () {
    Joueur joueur1;
    Joueur joueur2;
    Grille grille;
    int victoire = 0;
    int egalite = 0;
    int coupsJoues = 0;
    vector<vector<char>> plateau(3, vector<char>(3,' '));

    ////// Choix des pions
    joueur1.pion = joueur1.Demanderchoix(1,' ');
    joueur2.pion = joueur2.Demanderchoix(2,joueur1.pion);

    /// Boucle de jeu
    while (victoire != 1 && egalite != 1) {

        cout << "Tour de Joueur 1 (" << joueur1.pion << ")." << endl;
        joueur1.PlacerPion(plateau);
        coupsJoues++;

        //// Affichage
        grille.AffichageGrille(plateau,joueur1.pion,joueur2.pion);
        if (joueur1.TesterVictoire(joueur1.pion, plateau)){
            cout<<"Joueur 1 (" << joueur1.pion << ") a gagne" <<endl;
            victoire =1;

            break;

        }

        if (coupsJoues == 9) {
            egalite = 1;
            break;
        }

        ////// Tour de joueur 2
        cout << "Tour de Joueur 2 (" << joueur2.pion << ")." << endl;
        joueur2.PlacerPion(plateau);
        coupsJoues++;

        // Affichage
        grille.AffichageGrille(plateau,joueur1.pion,joueur2.pion);

        //// Vérification de la victoire de j2
        if (joueur2.TesterVictoire(joueur2.pion, plateau)){
            cout<<"Joueur 2 (" << joueur2.pion << ") a gagne" <<endl;
            victoire =1;
            return;
        }


        if (coupsJoues == 9) {
            egalite = 1;
            cout << "Match nul!" << endl;
            return;
        }
    }

}