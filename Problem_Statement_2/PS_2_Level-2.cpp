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
double damage = ((double)(attackStat * movePowers[moveIndex])/target.defence);
damage = round(damage* elementAdvantage(target) * crit());
if(damage ==0){
    damage = 1; //Bumping the Damage to 1 if it is 0, so that the target can take damage
}
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

//Element Consideration

float elementAdvantage(Bender target){
    if((element == "Fire" && target.element == "Water") || (element == "Water" && target.element == "Earth")||(element == "Earth" && target.element == "Air")||(element == "Air" && target.element == "Fire")){
        return 0.5; // Disadvantage
    }
    else if((element == "Fire" && target.element == "Air") || (element == "Water" && target.element == "Fire") || (element == "Earth" && target.element == "Water")||(element == "Air" && target.element == "Earth")){
        return 2.0; // Advantage
    }
    return 1.0; // Neutral
}

//Speed Consideration

int speedAdvantage(Bender &target){
    if(speed > target.speed){
        return 1;
    }
    else if(speed < target.speed){
        return -1;
    }
    else{
        return 0;
    }
}
//Critical Hit

int crit(){
    int chance = rand() % 100;
    if(chance < 10){ // 10% chance for critical hit
        cout<<"It's a Critical Hit!!!";
        return 2; // Double damage
    }
    return 1; // Normal damage
}

//Turn-Wise Duel

void Duel(Bender &target){
    if (speedAdvantage(target) == 1){
        cout<< name <<" has a speed advantage!\n"<<"So "<< name <<" attacks first!\n";
        while(!isFainted() && !target.isFainted()){
            cout<< name <<" choose the move you want to use on "<< target.name<<": ";
            int moveIndex;
            cin>> moveIndex;
            Attack(target, moveIndex);
            displayStats();
            target.displayStats();
            if(target.isFainted()){
                cout<< target.name <<" has fainted! "<< name <<" wins the duel!\n";
                break;
            }
            cout<< target.name <<" choose the move you want to use on "<< name<<": ";
            cin>> moveIndex;
            target.Attack(*this, moveIndex);
            displayStats();
            target.displayStats();
            if(isFainted()){
                cout<< name <<" has fainted! "<< target.name <<" wins the duel!\n";
                break;
            }
        }
    }
    else if(speedAdvantage(target) == -1){
        cout<< target.name <<" has a speed advantage!\n"<<"So "<< target.name <<" attacks first!\n";
        while(!isFainted() && !target.isFainted()){
            cout<< target.name <<" choose the move you want to use on "<< name<<": ";
            int moveIndex;
            cin>> moveIndex;
            target.Attack(*this, moveIndex);
            displayStats();
            target.displayStats();
            if(isFainted()){
                cout<< name <<" has fainted! "<< target.name <<" wins the duel!\n";
                break;
            }
            cout<< name <<" choose the move you want to use on "<< target.name<<": ";
            cin>> moveIndex;
            Attack(target, moveIndex);
            displayStats();
            target.displayStats();
            if(isFainted()){
                cout<< target.name <<" has fainted! "<< name <<" wins the duel!\n";
                break;
            }
    }}
    else{
        cout<<"Both have equal speeds... The Attacker will be chosen randomly...\n\n";
        int x = rand() % 2;
        if(x == 0){
            while(!isFainted() && !target.isFainted()){
                cout<< name <<" got chance to attack!!!\n";
            cout<< name <<" choose the move you want to use on "<< target.name<<": ";
            int moveIndex;
            cin>> moveIndex;
            Attack(target, moveIndex);
            displayStats();
            target.displayStats();
            if(target.isFainted()){
                cout<< target.name <<" has fainted! "<< name <<" wins the duel!\n";
                break;
            }
            cout<< target.name <<" choose the move you want to use on "<< name<<": ";
            cin>> moveIndex;
            target.Attack(*this, moveIndex);
            displayStats();
            target.displayStats();
            if(isFainted()){
                cout<< name <<" has fainted! "<< target.name <<" wins the duel!\n";
                break;
            }
        
        }}
        else if(x == 1){
            cout<< target.name <<" got chance to attack!!!\n Choose the move you want to use on "<< name<<": ";
            while(!isFainted() && !target.isFainted()){
            cout<<target.name <<" choose the move you want to use on "<< name<<": ";
            int moveIndex;
            cin>> moveIndex;
            target.Attack(*this, moveIndex);
            displayStats();
            target.displayStats();
            if(isFainted()){
                cout<< name <<" has fainted! "<< target.name <<" wins the duel!\n";
                break;
            }
            cout<< name <<" choose the move you want to use on "<< target.name<<": ";
            cin>> moveIndex;
            Attack(*this, moveIndex);
            displayStats();
            target.displayStats();
            if(isFainted()){
                cout<< name <<" has fainted! "<< target.name <<" wins the duel!\n";
                break;
            }
        }
    }
}

}};

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
    
    Alok.Duel(Natasha);
    // Alok.Attack(Natasha, 3);
    // Natasha.displayStats();
    return 0;

}