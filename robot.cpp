//
// Created by MANUEL on 25/10/2024.
//

#include "robot.h"
#include "Joueur.h"
#include "Grille.h"

char RobotRandom::RecupPion() const {
    return pion;
}

void RobotRandom::RobotJoue(vector<vector<char>> &plateau) {
    vector<pair<int, int>> cases_vide;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (plateau[i][j] == ' ') {
                cases_vide.push_back({i, j});
            }
        }
    }
    if (!cases_vide.empty()) {
        int index = rand() % cases_vide.size();
        plateau[cases_vide[index].first][cases_vide[index].second] = pion;

    }
}
bool RobotRandom::TesterVictoire2(char pion, vector<vector<char>>& plateau){
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




void RobotRandom::ToursParTours() {
    Grille grille;
    int victoire = 0;
    int egalite = 0;
    int coupsJoues = 0;
    vector<vector<char>> plateau(3, vector<char>(3, ' '));

    Joueur joueur1, joueur2;

    joueur1.SetPion(joueur1.Demanderchoix(1, ' '));
    joueur2.SetPion('M');
    RobotRandom robot(joueur2.GetPion());

    while (victoire != 1 && egalite != 1) {

        cout << "Tour de Joueur 1 (" << joueur1.GetPion() << ")." << endl;
        joueur1.PlacerPion(plateau);
        coupsJoues++;

        grille.AffichageGrille(plateau, joueur1.GetPion(), robot.RecupPion());
        if (joueur1.TesterVictoire(joueur1.GetPion(), plateau)) {
            cout << "Joueur 1 (" << joueur1.GetPion() << ") a gagne" << endl;
            victoire = 1;
            break;
        }

        if (coupsJoues == 9) {
            egalite = 1;
            cout << "Match nul!" << endl;
            break;
        }
////////////////Mon Tour////////////////
        cout << "Tour de Manuel (" << robot.RecupPion() << ")." << endl;
        robot.RobotJoue(plateau);
        coupsJoues++;

        grille.AffichageGrille(plateau, joueur1.GetPion(), robot.RecupPion());
        if (robot.TesterVictoire2(robot.RecupPion(), plateau)) {
            cout << "Manuel (" << robot.RecupPion() << ") a gagne" << endl;
            victoire = 1;
            break;
        }

        if (coupsJoues == 9) {
            egalite = 1;
            cout << "Match nul!" << endl;
            break;
        }
    }
}