#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Bender{
public:
    string name;
    string element;
    int maxHp;
    int hp;
    int attackStat;
    int defence;
    int speed;
    string moveNames[4];
    int movePowers[4];
//Constructor
Bender(string n, string e, int h, int a, int d, int s, string mNames[4], int mPowers[4]){
    name = n;
    element = e;
    maxHp = h;
    hp = h;
    attackStat = a;
    defence = d;
    speed = s;
    for(int i=0; i<4; i++){
        moveNames[i] = mNames[i];
        movePowers[i] = mPowers[i];
    }
}

//Attack

void Attack(Bender &target, int moveIndex){
int damage = round((double)(attackStat * movePowers[moveIndex])/target.defence);
cout<< name <<" used " << moveNames[moveIndex] << "\n";
target.takeDamage(damage);
}

//Take Damage

void takeDamage(int damage){
    hp-=damage;
    if(hp < 0){
        hp = 0;}
}

//Checking that Target is Fainted or not

bool isFainted(){
     if(hp == 0){
        return true;
     }
     return false;
}

//Display Stats

void displayStats(){
    cout<< name <<"("<< element << ") - HP:" << hp << "/" << maxHp <<
     ", Attack: " << attackStat << ", Defence: " << defence << ", Speed: "<< speed <<"\n";
     cout<<"Moves: ";
     for(int i=0; i<4; i++){
        cout<<moveNames[i]<<"("<<movePowers[i]<<")";
        if(i<3) cout<<", ";
     }
     cout<<"\n";
    }
};

int main(){
    string AlokNames[4] = {"Ember Slash", "Quick Jab", "Focus", "Flame Surge"};
    int AlokPowers[4] = {40, 30, 0, 70};

    string NatashaNames[4] = {"Water Whip", "Tide Push", "Mist Veil", "Tidal Wave"};
    int NatashaPowers[4] = {35, 25, 0, 60};

    Bender Alok("Alok","Fire",120, 60, 45, 75, AlokNames, AlokPowers);
    Bender Natasha("Natasha","Water",90, 50, 55, 45, NatashaNames, NatashaPowers);

    Alok.displayStats();
    Natasha.displayStats();
    cout<<"\n";

    Alok.Attack(Natasha, 3);
    cout<<"/n";

    Natasha.displayStats();
    cout<<"\n"<<"Natasha fainted : "<< Natasha.isFainted()<<"\n";
    return 0;

}