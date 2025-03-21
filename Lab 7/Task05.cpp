#include <iostream>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon){
        characterID = id;
        name = n;
        level = lvl;
        healthPoints = hp;
        weaponType = weapon;
    }
        

    void attack() {
        cout<<name<<" attacks with "<<weaponType<<endl;
    }

    void defend() {
        cout<<name<<" defends"<<endl;
    }

    void displayStats() {
        cout<<"ID: "<<characterID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"HP: "<<healthPoints<<endl;
        cout<<"Weapon: "<<weaponType<<endl;
    }

};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, int armor, int dmg, string weapon)
        : Character(id, n, lvl, hp, weapon){
            armorStrength = armor;
            meleeDamage = dmg;
        }

    void attack() {
        cout<<name<<" accacked. Damage: "<<meleeDamage<<endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int spell,string weapon)
        : Character(id, n, lvl, hp, weapon){
            manaPoints = mana;
            spellPower = spell;
        }

    void defend() {
        cout<<name<<" casts a spell. Defense boosted by: "<<spellPower<<endl;
    }
};


class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy,string weapon)
        : Character(id, n, lvl, hp, weapon){
            arrowCount = arrows;
            rangedAccuracy = accuracy;
        }

    void attack() {
        cout<<name<<" attacked with accuracy "<<rangedAccuracy<<endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int agil,string weapon)
        : Character(id, n, lvl, hp, weapon){
            stealthLevel = stealth;
            agility = agil;
        }

    void displayStats() {
        cout<<"ID: "<<characterID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"HP: "<<healthPoints<<endl;
        cout<<"Weapon: "<<weaponType<<endl;
        cout<<"Stealth: "<<stealthLevel<<endl;
        cout<<"Agility: "<<agility<<endl;
    }
};
