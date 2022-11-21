#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "dice.hpp"
#include "helpers.hpp"
#include "weapon.hpp"
#include "fighter.hpp"

using namespace std;

int main()
{
    //srand(time(0));

    vector<BaseFighter*> fighters;
    vector<BaseFighter*> defence;
    
    
    //Optionally create a vector of 100 of each BaseFighters
    for(int i=0;i<100;i++){
        fighters.push_back(new Warrior("fighters"));
        fighters.push_back(new Archer("fighters"));
        fighters.push_back(new Wizard("fighters"));
        fighters.push_back(new Elf("fighters"));
        fighters.push_back(new Dragonborn("fighters"));

        defence.push_back(new Warrior("defence"));
        defence.push_back(new Archer("defence"));
        defence.push_back(new Wizard("defence"));
        defence.push_back(new Elf("defence"));
        defence.push_back(new Dragonborn("defence"));
    }
    cout<< defence.back();
    return 0;
}