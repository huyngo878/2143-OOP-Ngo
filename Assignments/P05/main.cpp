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
    srand(time(0));

    BaseFighter *f1 = new BaseFighter;
    
    vector<BaseFighter*> fighters;
    
    
    //Optionally create a vector of 100 BaseFighters
    for(int i=0;i<100;i++){
        fighters.push_back(new BaseFighter);
    }
    
    
    cout<<*f1<<endl;

    cout<<f1->attack()<<endl;

    return 0;
    return 0;
}