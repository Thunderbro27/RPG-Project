#include "shop.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>


int php = 100;  //Player Hit Points
int ehp = 100;  //Enemy Hiy points
int expcap = 100; //The Default amount of exp needed to level up
    int* phpp = &php;   //Pointers for the players hp and the enemies hp
    int* ehpp = &ehp;   //Needed for later funtions
    int* dhp; //Drained hp used to add the amount the player heals durring the King slime boss fight
int et =0; //Used when deciding enemy type (slime, fox, king slime) 
int t=0; //Counts down the amount of turns the enemy is burned
int bt =0;  // Counts down the smount of turns the player is bleeding

Shop s1; //Starts the shop



void attack(int*&,char,int);
void battle(std::string);
void enemy(int*&,int*&,int);
void lvlup();
void moveinfo();

class Player{
    private: 
    int gold;
    int lvl;
    int exp;
    int hpcap; // Max hp of the player and caps over healing
    std::string name;
public:
    Player(){
        lvl = 1;
        exp = 0;
        name = "N/A";
        hpcap = 100;
        gold = 0;
    };

    int Getlvl(){return lvl;};
    int Getgold(){return gold;}
    int Getexp(){return exp;};
    int GetHpcap(){return hpcap;};
    std::string Getname(){return name;};
    void setGold(int gold){this->gold += gold;}
    void setLvl(int lvl){this->lvl +=lvl;};
    void setHpcap(int hpcap){this->hpcap +=hpcap;}
    void setExp(int exp){this-> exp +=exp;};
    void setName(std::string name){this-> name = name;};
    void Displayer(){
        char e; // Is only used to halt the program so the player can read and e's of type char are used for readablity
     sep();
        std::cout << this->name <<"'s stats: "<< std::endl;
        std::cout << "Level: " << this->lvl << std:: endl;
        std::cout << "HP: " << php << "/"<< hpcap <<std:: endl;
        std::cout << "EXP: " << exp << "/"<< expcap <<std::endl;
        std::cout << "Gold: "<< gold;
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> e; // Paues the menu so the player can read it
    }
};

    
    Player* ppf; //A pointer used point at the methods within the Player class

int main(){
    
    int w =1; //Used to exit the menu loop, when w is equal to 2 the program ends
    char choice;
    char e;
    
   std::string name;
   sep();
        std:: cout<<"Welcome to Brandon's WIP RPG"<<std::endl;
        std::cout<<"Name pending... ";
   sep();
   std::cout << "Please enter your Name: ";
         getline(std::cin,name);

    Player p1;
    ppf = &p1;
    p1.setName(name);
    
     sep(); 
  std::cout << "Your stats: "<<std::endl;
    std::cout << "Your player name is: "<< p1.Getname() <<std::endl;
    std::cout <<"Exp: " << p1.Getexp() <<"/" << expcap << std::endl;
   std::cout <<"Lvel: "<<  p1.Getlvl()<< std::endl;
    

    std::cout <<"Press any key and enter to continue: ";
    sep();
   std::cin >> e;
    
    while(w == 1){ //This is the menu loop, if the user enters 5(Exit) as their choice the program exits the loop and the program ends
        sep();
    std::cout << "What would you like to do?"<<std::endl;
        std::cout << "1 = Battle" <<std::endl;
        std::cout << "2 = Rest(used to heal)" <<std::endl;
        std::cout << "3 = Show stats" <<std::endl;
        std::cout << "4 = Shop (Doesn't work yet)" <<std::endl;
        std::cout << "5 = Exit";
    sep();

    std::cin >> choice;
   
        switch (choice)
        {
        case '1':
            *ehpp = 100;// Sets the emeny's hp to 100 if it wasn't set alread
            battle(name);
           
            break;
        case '2':
                sep();
                std::cout << "You rested and full healed!";
                *phpp =ppf->GetHpcap(); //Heals the player by setting the hp pointer equal to the players max hp
            break;

        case '3':
            
            ppf->Displayer();
            break;
        case '4':
             
            char ch;
            s1.enterShop(); //Calls the shop. See shop.h for more detials
            std::cin>> ch;
            s1.Choice(ch);
            break;
        case '5':
                w++;
            break;

        default:
            std:: cout << "error"<<std::endl;
            break;
        }
    }
    std::cout << "Ending the program!" << std::endl;

return 0;
}





void battle(std::string pname){
    
    char act; //Reads the players action
    int c;
    if(*phpp!= ppf->GetHpcap()){ //Check if the player is at full hp
        std::cout<< "You aren't at full hp!"<<std::endl;
    }
    else{
        sep();
        std::cout << "What would you like to fight?"<< std::endl;
        std::cout << "1 = Slime"<<std::endl;
        std::cout << "2 = Fox"<<std::endl;
        std::cout << "3 = King Slime (Boss)";
        sep();
            std::cin >> et; //Takes in the choice for enemy type
        
    switch(et)
    {
        case 1:
    sep();
    std::cout << "A Slime appears: " << std::endl;

    while(*phpp > 0 && *ehpp > 0){
       
        std::cout << "Slime: "<< ehp << "/100"; 
        if(t > 0){
            std::cout << "-Burned"<< std::endl;
        }
        else    
           std::cout << std::endl;
        std::cout << pname << ": " << php << "/"<<ppf->GetHpcap() << std::endl;
            std::cout << "Enter i to show move details."<< std::endl;
        std::cout << "What will you do?" << std::endl << "1 = Attack" << std::endl << "2 = Heavy Attack (low acc)";
        
        if(ppf->Getlvl() >= 2){
            std::cout << std::endl << "3 = Execute";
        }
        if(ppf->Getlvl() >= 3){
            std::cout << std::endl << "4 = Fireball";
        }
        sep();
        std::cin >> act;

            switch (act)
            {
            case '1': 
                attack(ehpp, act,et);
                
                break;
            case '2': 
                attack(ehpp, act,et);
                break;
            case '3':
                if(ppf->Getlvl() >= 2){
                attack(ehpp, act,et);
                }
                break;
            case '4':
                if(ppf->Getlvl() >= 3){
                attack(ehpp, act,et);
                }
                break;
            case 'i':
                moveinfo();
                break;
                
            default:
                break;
            }

    }
    t =0;
      if(*phpp <= 0){
        sep();
       std::cout << "You died to the slime!";
       *phpp =0;

    }
    else{
        sep();
        std::cout << "You won the battle! You got "<< 75 << " exp!"<< std::endl;
        std::cout << "And you got 10 gold";
        ppf->setGold(10);
        ppf->setExp(75);
        

    }

    if(ppf->Getexp() >= expcap){
        lvlup();
        }
        break;

          case 2:
    sep();
    std::cout << "A Fox appears: " << std::endl;

    while(*phpp > 0 && *ehpp > 0){
       
        std::cout << "Fox: "<< ehp << "/100"; 
        if(t > 0){
            std::cout << "-Burned"<< std::endl;
        }
        else    
           std::cout << std::endl;
        std::cout << pname << ": " << php << "/" <<ppf->GetHpcap()<< std::endl;
            std::cout << "Enter i to show move details."<< std::endl;
        std::cout << "What will you do?" << std::endl << "1 = Attack" << std::endl << "2 = Heavy Attack (low acc)";
        
        if(ppf->Getlvl() >= 2){
            std::cout << std::endl << "3 = Execute";
        }
        if(ppf->Getlvl() >= 3){
            std::cout << std::endl << "4 = Fireball";
        }
        sep();
        std::cin >> act;

            switch (act)
            {
            case '1': 
                attack(ehpp, act,et);
                
                break;
            case '2': 
                attack(ehpp, act,et);
                break;
            case '3':
                if(ppf->Getlvl() >= 2){
                attack(ehpp, act,et);
                }
                break;
            case '4':
                if(ppf->Getlvl() >= 3){
                attack(ehpp, act,et);
                }
                break;
            case 'i':
                moveinfo();
                break;
                
            default:
                break;
            }

    }
    t =0;
    bt =0;
      if(*phpp <= 0){
       std::cout << "You died to the Fox!";
       *phpp =0;

    }
    else{
        std::cout << "You won the battle! You got "<< 75 << " exp!";
        std::cout << "And you got 10 gold";
        ppf->setGold(10);
        ppf->setExp(75);

    }

    if(ppf->Getexp() >= expcap){
        lvlup();
        }
        break;

    case 3:

          sep();
    std::cout << "The King Slime appears: " << std::endl;
        *ehpp = 300;
    while(*phpp > 0 && *ehpp > 0){
       
        std::cout << "King Slime: "<< ehp << "/300"; 
        if(t > 0){
            std::cout << "-Burned"<< std::endl;
        }
        else    
           std::cout << std::endl;
        std::cout << pname << ": " << php << "/" <<ppf->GetHpcap()<< std::endl;
            std::cout << "Enter i to show move details."<< std::endl;
        std::cout << "What will you do?" << std::endl << "1 = Attack" << std::endl << "2 = Heavy Attack (low acc)";
        
        if(ppf->Getlvl() >= 2){
            std::cout << std::endl << "3 = Execute";
        }
        if(ppf->Getlvl() >= 3){
            std::cout << std::endl << "4 = Fireball";
        }
        sep();
        std::cin >> act;

            switch (act)
            {
            case '1': 
                attack(ehpp, act,et);
                
                break;
            case '2': 
                attack(ehpp, act,et);
                break;
            case '3':
                if(ppf->Getlvl() >= 2){
                attack(ehpp, act,et);
                }
                break;
            case '4':
                if(ppf->Getlvl() >= 3){
                attack(ehpp, act,et);
                }
                break;
            case 'i':
                moveinfo();
                break;
                
            default:
                break;
            }

    }
    t =0;
    bt =0;
      if(*phpp <= 0){
        sep();
       std::cout << "You died to the King Slime!";
       *phpp =0;

    }
    else{
        sep();
        std::cout << "You won the battle! You got "<< 200 << " exp!";
        std::cout << "And you got"<< 30 << "gold";
        ppf->setGold(30);
        ppf->setExp(200);

    }

    if(ppf->Getexp() >= expcap){
        lvlup();
        }

        break;

    default:
        std::cout << "Invalid" << std::endl;
        break;
        }
    }
}

void attack(int*& hp, char act,int en){
    int r;
    int d;
    int burn;
    std::string type;
    if(en == 1){
        type = " slime ";
    }
        if(en== 2){
            type =" fox ";
        }
            if(en ==3){
                type = " King Slime ";
            }
        if(act == '1'){
        srand(time(NULL));

    r = rand() % 9 + 1;
    d = rand() % 19 + 1;
        dhp = &d;
        if(r > 3){
        std::cout << "You hit the" << type << "for: " << d << " damage.";
         *hp = *hp -d;
         sep();
        enemy(phpp,hp,et);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp, hp,et);
        }
     }
     if(act == '2'){
      srand(time(NULL));

    r = rand() % 9 + 1;
    d = rand() % 40 + 10;
        dhp = &d;
        if(r > 6){
        std::cout << "You hit the"<< type << "for: " << d << " damage.";
         *hp = *hp -d;
         sep();
        enemy(phpp,hp,et);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp,hp,et);
        }

     }
     if(act == '3'){
        srand(time(NULL));

    r = rand() % 99 +1;
    d = 9999;
        dhp = &d;
        if(r<=5){
        std::cout << "You hit the"<< type <<"for: " << d << " damage.";
         *hp = *hp -d;
         sep();
        enemy(phpp,hp,et);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp, hp,et);
        }
     }
     if(act == '4'){
         srand(time(NULL));

    r = rand() % 9 + 1;
    d = rand() % 40 + 10;
    burn = rand() % 3 + 1;
    dhp = &d;
        if(r > 4){
        std::cout << "You hit the"<< type << "for: " << d << " damage.";
         *hp = *hp -d;
         sep();
         if(burn == 4){
            std::cout <<"You burned the" << type << std::endl;
            
            t=3;
         }
        
        enemy(phpp,hp,et);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp,hp,et);
        }
     }
     
}
void enemy(int*& hp,int*& ehp,int et){
    int r;
    int d;
    int c;

        if(et == 1){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1,10);


if(*ehp > 0){
    r = dist(gen);
    d = dist(gen)% 20 +6;
    if(t > 0){
        int bur;
        bur = rand() % 15 +3;
        std::cout << "The slime took " << bur <<" damage from burn.";
        sep();
        *ehp = *ehp - bur;
        t--;
    }
        if(r > 3){
        std::cout << "The slime hit you for: " << d << " damage.";
         *hp = *hp -d;
         sep();
        }
        else {
            std::cout << "The slime missed!";
            
            sep();
        }

    }
        }

    if(et == 2){

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1,10);


if(*ehp > 0){
    c = dist(gen)% 3 + 1;
    r = dist(gen);
    d = dist(gen)% 20 +6;
    if(t > 0){
        int bur;
        bur = rand() % 15 +3;
        std::cout << "The Fox took " << bur <<" damage from burn.";
        sep();
        *ehp = *ehp - bur;
        t--;
    }
        if(r > 3){
        std::cout << "The Fox hit you for: " << d << " damage.";
         *hp = *hp -d;
         sep();
         if(c == 4){
             std:: cout << "The fox scratched you!"<< std:: endl;
             std:: cout << "You are now bleeding!";
         }
        }
        else {
            std::cout << "The Fox missed!";
            
            sep();
            }
        }
    }

    if(et == 3){

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1,10);


if(*ehp > 0){
    if(*ehp <=150 && *ehp>=100){
        
        std::cout << "The King Slime is in a weaked state, your next attacks will heal you!";
        sep();

        *hp =*hp + *dhp;
        if(*hp> ppf->GetHpcap()){
            *hp = ppf->GetHpcap();
        }
    }  
    else{
    r = dist(gen);
    d = dist(gen)% 30 +6;
    if(t > 0){
        int bur;
        bur = rand() % 15 +3;
        std::cout << "The King Slime took " << bur <<" damage from burn.";
        sep();
        *ehp = *ehp - bur;
        t--;
    }
        if(r > 3){
        std::cout << "The King Slime hit you for: " << d << " damage.";
         *hp = *hp -d;
         sep();
        }
        else {
            std::cout << "The King Slime missed!";
            
            sep();
                }
            }
        
        }
    }
}
void lvlup(){
    while(ppf->Getexp() >= expcap){
    ppf->setExp(-expcap);
    expcap +=100;
    ppf->setLvl(1);
    ppf->setHpcap(10);

    sep();

    std::cout << "You lvled up!"<< std::endl;
    std::cout << "You are now level: "<< ppf->Getlvl()<< std::endl;
    std::cout << "And you gained 10 exrta hitpoints.";
    
    if(ppf->Getlvl() == 2){
        std::cout << std::endl << "You unlocked Execution!";
    }
    if(ppf->Getlvl()== 3){
        std::cout << std::endl << "You unlocked Fireball!";
    }

    }
}

void moveinfo(){
    int e;
    int w =0;
    char t;
    while(w==0){
        e =0;
    sep();
    std::cout << "What move do you want info on?" <<std::endl;
    std::cout << "1 = Attack"<<std::endl;
    std::cout << "2 = Heavy attack"<<std::endl;
    std::cout << "3 = Execute"<<std::endl;
    std::cout << "4 = Fallball"<<std::endl;
    std::cout << "5 = Exit";
    sep();
    std::cin >> e;


    switch (e)
    {
    case 1:
        std::cout<<"Does ok damage and, has a 70"<< "% "<< "chance to hit the target.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> t;
        break;
    case 2:
        std::cout << "Does heavy damage and, has a 40" << "% "<< "chance to hit the target.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> t;
        break;

    case 3:
        std::cout << "Has a 5" << "% "<< " chance to hit the target, but always kills.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> t;
        break;

    case 4:
        std::cout << "Does heavy damage and, has a 60" << "% "<< " chance to hit the target. Also has a 25"<< "% "<< "chance to burn.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> t;
        break;

    case 5:
        w++;
        sep();
        break;

    default:
        break;
    }

    }
}
