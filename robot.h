//
// Created by MANUEL on 25/10/2024.
//

#ifndef JEUMORPION_ROBOT_H
#define JEUMORPION_ROBOT_H
#include "iostream"
#include "vector"
#include <cstdlib>
#include <ctime>

using namespace std;

class RobotRandom {
public:
    RobotRandom(char pion) : pion(pion) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }
    char RecupPion() const;
    void RobotJoue(vector<vector<char>>& plateau);
    void ToursParTours();
    bool TesterVictoire2(char pion, vector<vector<char>>& plateau);


private:
    char pion;
};


#endif //JEUMORPION_ROBOT_H
