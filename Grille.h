#ifndef JEUMORPION_GRILLE_H
#define JEUMORPION_GRILLE_H
#include "vector"

using namespace std;
class Grille{
public :
    void AffichageGrille(const vector<vector<char>>&plateau,char pion1, char pion2) const;
    void InitialisationGrille(vector<vector<char>>&plateau);
};
#endif //JEUMORPION_GRILLE_H
