#include "Grille.h"
#include "iostream"
#include "vector"

using namespace std;

void Grille::InitialisationGrille(vector<vector<char>>&plateau){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plateau[i][j] = ' ';
        }
    }
}

const string RESET = "\033[0m";
const string VIOLET = "\033[35m";
const string ROUGE = "\033[31m";
const string BLEU = "\033[34m";

void Grille::AffichageGrille(const vector<vector<char>>&plateau,char pion1, char pion2) const {
    cout << "     1   2   3  " << endl;
    cout << VIOLET << "   -------------"<< RESET << endl;

    for (int i = 0; i < 3; i++) {
        cout  << " " << i + 1  << VIOLET <<" |"<< RESET;
        for (int j = 0; j < 3; j++) {
            if (plateau[i][j] == pion1) {
                cout << BLEU << " " << plateau[i][j] << RESET; // Pion 1 en bleu
            } else if (plateau[i][j] == pion2) {
                cout << ROUGE << " " << plateau[i][j] << RESET; // Pion 2 en rouge
            }else {
                cout << "  ";
            }
            if (j < 2) cout << VIOLET << " |";
        }
        cout << VIOLET << " |"<< RESET << endl;
        if (i < 2) cout << VIOLET << "   -------------" << RESET << endl;
    }
    cout << VIOLET << "   -------------" << RESET << endl;
}

