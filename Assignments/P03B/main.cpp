/*
 
   /$$$$$$    /$$ /$$   /$$  /$$$$$$                               
  /$$__  $$ /$$$$| $$  | $$ /$$__  $$                              
 |__/  \ $$|_  $$| $$  | $$|__/  \ $$                              
   /$$$$$$/  | $$| $$$$$$$$   /$$$$$/                              
  /$$____/   | $$|_____  $$  |___  $$                              
 | $$        | $$      | $$ /$$  \ $$                              
 | $$$$$$$$ /$$$$$$    | $$|  $$$$$$/                              
 |________/|______/    |__/ \______/                               
                                                                   
                                                                   
                                                                   
  /$$$$$$$   /$$$$$$  /$$$$$$$                                     
 | $$__  $$ /$$$_  $$| $$____/                                     
 | $$  \ $$| $$$$\ $$| $$                                          
 | $$$$$$$/| $$ $$ $$| $$$$$$$                                     
 | $$____/ | $$\ $$$$|_____  $$                                    
 | $$      | $$ \ $$$ /$$  \ $$                                    
 | $$      |  $$$$$$/|  $$$$$$/                                    
 |__/       \______/  \______/                                     
                                                                   
                                                                   
                                                                   
  /$$   /$$                           /$$   /$$                    
 | $$  | $$                          | $$$ | $$                    
 | $$  | $$ /$$   /$$ /$$   /$$      | $$$$| $$  /$$$$$$   /$$$$$$ 
 | $$$$$$$$| $$  | $$| $$  | $$      | $$ $$ $$ /$$__  $$ /$$__  $$
 | $$__  $$| $$  | $$| $$  | $$      | $$  $$$$| $$  \ $$| $$  \ $$
 | $$  | $$| $$  | $$| $$  | $$      | $$\  $$$| $$  | $$| $$  | $$
 | $$  | $$|  $$$$$$/|  $$$$$$$      | $$ \  $$|  $$$$$$$|  $$$$$$/
 |__/  |__/ \______/  \____  $$      |__/  \__/ \____  $$ \______/ 
                      /$$  | $$                 /$$  \ $$          
                     |  $$$$$$/                |  $$$$$$/          
                      \______/                  \______/           
 
*/

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
    BaseFighter *attacker;
    BaseFighter *defender;
    
    //create 100 of each fighters on each side
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

    //if one of the teams have 0 fighters the while loop stops
    while(fighters.size() != 0 || defence.size() != 0)
    {
        attacker = fighters.back();
        defender = defence.back();


        while(attacker->health >= 0 || defender->health >= 0)
        {
            attacker->health =- defender->attack();
            defender->health =- attacker->attack();

            cout << attacker->health << endl;
            cout << defender->health<< endl;

            if(attacker->health <= 0)
            {
                fighters.pop_back();
            }
            else if(defender->health <= 0)
            {
            defence.pop_back();
            }

            defender->regen;
        }
        if(fighters.size() == 0)
        {
        cout << "Defender Won" << endl;
        }
        else if(defence.size() == 0)
        {
        cout << "Fighters won"<< endl;
        }

    }

    if(fighters.size() > 0)
    {
        cout << "Fighters won" << endl;
    }
    else if(defence.size() > 0)
    {
        cout << "Defenders won"<< endl;
    }

    cout << defence.back();
    return 0;
}