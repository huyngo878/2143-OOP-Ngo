#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "weapon.hpp"
#include "helpers.hpp"

using namespace std;

#pragma once


class BaseFighter {

public:
    string name;
    int health;
    double regen;
    Weapon *weapon;


    BaseFighter() {
        name = "None";
        health = 1;
        regen = .15;
        weapon = new Weapon;
    }
    string setName()
    {
        return name;
    }
    void setHealth(double health_)
    {
        health = health_;
    }
    void setRegen(double regen_)
    {
        regen = regen_;
    }

    virtual double attack(){
        return weapon->use();
    }

    friend ostream& operator<<(ostream& os, const BaseFighter& f) {
        return os << "[" << f.name << " , " << *f.weapon << "]";
    }

};

class Warrior : public BaseFighter{
private:

public:
    Warrior(string side)
    {
        weapon = new Weapon("sword", "1.d.12");
        health = rand() % 5 + 3;
        if(side == "defence")
        {
            health *= 1.15;
        }
        else
        {
            health *= 1;
        }
    }
};

class Archer : public BaseFighter{
private:

public:
    Archer(string side)
    {
        weapon = new Weapon("bow", "1.d.8");
        health = rand() % 5 + 3;
        if(side == "defence")
        {
            health *= 1.15;
        }
        else
        {
            health *= 1;
        }
    }
};

class Wizard : public BaseFighter{
private:

public:
    Wizard(string side)
    {
        weapon = new Weapon("MagicSpell", "1.d.20");
        health = rand() % 5 + 3;
        if(side == "defence")
        {
            health *= 1.15;
        }
        else
        {
            health *= 1;
        }
    }
};

class Elf : public BaseFighter{
private:

public:
    Elf(string side)
    {
        weapon = new Weapon("sword", "1.d.4");
        health = rand() % 5 + 3;
        if(side == "defence")
        {
            health *= 1.15;
        }
        else
        {
            health *= 1;
        }
    }
};

class Dragonborn : public BaseFighter{
private:

public:
    Dragonborn(string side)
    {
        weapon = new Weapon("FireMagic", "1.d.8");
        health = rand() % 5 + 3;
        if(side == "defence")
        {
            health *= 1.15;
        }
        else
        {
            health *= 1;
        }
    }
};