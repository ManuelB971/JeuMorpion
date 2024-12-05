#ifndef JEUMORPION_JOUEUR_H
#define JEUMORPION_JOUEUR_H
#include "vector"
using namespace std;

class Joueur {
public:
    char Demanderchoix (int joueurNum,char autrepion);
    void PlacerPion(vector<vector<char>>& plateau);
    bool CaseValide(int x, int y, const vector<vector<char>>& plateau);
    bool TesterVictoire(char pion, vector<vector<char>>& plateau);
    void ToursParTours ();
    char GetPion() const;
    void SetPion(char choix){
        pion = choix;
    }
private:


protected:
    char pion;
};










#endif //JEUMORPION_JOUEUR_H
