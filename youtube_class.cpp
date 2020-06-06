#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <string>

class Warrior{
    private:
    std::string name;
    int health;
    int attack;
    int defense;
    static int number;

    public:
    Warrior(){
        this->name = " ";
        this->health = 0;
        this->attack =0;
        this->defense =0;
        Warrior::number++;
    }
    Warrior(std::string , int , int  ,int );
    ~Warrior(){
        std::cout << "DESTROYED: " << this->name << "\n";

    }
    int show_health(){return this->health; }

    void show_warrior(){
            std::cout<< "Name: " << this->name <<"Health: " <<this->health<< "Attack: " << this->attack << "Defense: " << this->defense << "\n";
    }

    static int GetNumber(){return number;}

    int getHealth(){return this->health;}
    int getDefense(){return this->defense;}
    int getAttack(){return this->attack;}

    void theHealth(int pp){
        this->health=pp;
    }
};

Warrior::Warrior(std::string name, int health, int attack, int defense){
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    Warrior::number++;
}


    void start_fight(Warrior &p1, Warrior &p2){
        
        while ( (p1.show_health() > 0) && (p2.show_health() >0) ){
            int p1_h=p1.getHealth()+std::rand()%p1.getDefense() -std::rand()%p2.getAttack();
            int p2_h=p2.getHealth()+std::rand()%p2.getDefense()-std::rand()%p1.getAttack();
            p1.theHealth(p1_h);
            p2.theHealth(p2_h);
            p1.show_warrior();
            p2.show_warrior();

        }

    return;
    }

    int Warrior::number=0;

int main(){
    srand(time(NULL));
    Warrior hulk("Hulk", 130, 20, 10);
    Warrior thor("Thor", 100, 30, 8);

    start_fight(thor,hulk);



    return 0;
}