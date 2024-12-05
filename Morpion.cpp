#include "Morpion.h"
#include "iostream"

using namespace std;

int Morpion::Menu(){
    int choix;
    cout<<"_________________________"<< endl;
    cout<<"|          Menu         |"<< endl;
    cout<<"|1. Commencer une partie|"<< endl;
    cout<<"|2.      VS Manuel      |"<< endl;
    cout<<"|3.       Quitter       |"<< endl;
    cout<<"|_______________________|"<< endl;
    cout<<"Quelle est votre choix ? \n"<< endl;
    cin>>choix;
    return choix;
}


