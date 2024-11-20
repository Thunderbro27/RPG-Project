#include "shop.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>


int enemy_hp = 100;  //Enemy Hiy points
    int* enemy_hp_ptr = &enemy_hp;   //Needed for later funtions
    int* drained_hp; //Drained hp used to add the amount the player heals durring the King slime boss fight
int enemy_type =0; //Used when deciding enemy type (slime, fox, king slime) 
int turn_timer=0; //Counts down the amount of turns the enemy is burned
int bleed_timer=0;// Counts down the smount of turns the player is bleeding
Shop s1; //Starts the shop 

void attack(int*&,char,int);
void battle(std::string);
void enemy(int*&,int);
void lvlup();
void moveinfo();
void menu(std::string);

class Player{
private: 
    bool inventory[2];// The inventory uses type bool to deturmine if the player has an iten or not.
    int gold;
    int xp;
    int xp_cap; //The Default amount of xp needed to level up
protected:
    int hit_points;  //Player Hit Points
    int lvl;
    int max_hp; // Max hp of the player and caps over healing
    std::string name;
public:
    Player(){
        xp_cap = 100;
        hit_points = 100;
        lvl = 1;
        xp = 0;
        name = "   ";
        max_hp = 100;
        gold = 0;
    };
    bool Getinventory(int i){return inventory[i];};
    int Getlvl(){return lvl;};
    int Getgold(){return gold;};
    int Getexp(){return xp;};
    int GetXpCap(){return xp_cap;}
    int GetHpCap(){return max_hp;};
    int GetHp(){return hit_points;};
    std::string Getname(){return name;};
    void setInventory(bool id){
        inventory[id] = true;
    }
    void setGold(int gold){this->gold += gold;}
    void setLvl(int lvl){this->lvl +=lvl;};
    void setXpCap(int xp_cap){this-> xp_cap +=xp_cap;}
    void SetHpCap(int max_hp){this->max_hp +=max_hp;}
    void SetHpZero(){this->hit_points = 0;}
    void SetHp(int hit_points){this->hit_points +=hit_points;
        if(this->hit_points> this->max_hp){
            this->hit_points =this->max_hp;
        }
    }
    void setExp(int xp){this-> xp +=xp;};
    void setName(std::string name){this-> name = name;};
    void display(){
            if(this-> name == "   "){
                std::cout<< "New game" << std::endl;
            }else
                {
                std::cout << "Name: "<< this-> name << "  " << "Level: "<< this->lvl << std::endl;
                }
    };
    void stats(){
        char menu_stopper; // Is only used to halt the program so the player can read and menu_stopper's of type char are used for readablity
     sep();
        std::cout << this->name <<"'s stats: "<< std::endl;
        std::cout << "Level: " << this->lvl << std:: endl;
        std::cout << "HP: " << this->hit_points << "/"<< this->max_hp <<std:: endl;
        std::cout << "EXP: " << this->xp << "/"<< this->xp_cap <<std::endl;
        std::cout << "Gold: "<< this->gold;
        sep();
        std::cout << "Press any key and enter to continue or enter i for inventory: ";
        std::cin >> menu_stopper; // Paues the menu so the player can read it
        if(menu_stopper == 'i'){
            sep();
            std::cout << "Items in inventory: "<< std::endl;
                if(this->inventory[0]== false){
                    std::cout << "Hand: No Weapon"<< std::endl;
                }
                else{
                    std::cout <<"Hand: Sword"<< std::endl;
                }
                if(this->inventory[1]== false){
                    std::cout << "Body: No Armor"<<std::endl;
                }
                else{
                    std::cout<< "Body Armor"<<std::endl;
                }
        
        std::cout<<"Press any key and enter to continue: ";
        sep();
        std::cin>> menu_stopper;
        }
    }
};
//WIP below>>>>>>>>>>>>>>>>>>>
class Enemy: public Player {

private:
    int scaler;

public:
    Enemy(){
        hit_points =100;
        max_hp =100;
        name = "   ";
        lvl = 1;
    }; 
    void setScaler(int scaler){ this->scaler = this->scaler +1;}
    void enemySetLevel(int lvl){this->lvl = lvl;}
    void enemySetname(std::string name){this->name = name;}
    void enemySetHitPoints(int hit_points){this-> hit_points = hit_points;}
    void enemySetMaxHp(int max_hp){this-> max_hp = max_hp;}
    int EnemyGetHitPoints(){return hit_points;}
    int EnemyGetLevl(){return lvl;}
    std::string EnemyGetname(){return name;}
    int EnemyGetMaxHp(){return max_hp;}
    void checkPlayerLevel(int player_lvl){
        
    }
    /*void scalerFormula(bool inv){ 
            if(inv == ture){
                
            }
    }*/

};
//WIP Above>>>>>>>>>>>>>>

    Player* player_ptr = nullptr; //A pointer used point at the methods within the Player class

int main(){
    
    int exit_menu =0; //Used to exit the menu loop, when exit_menu is equal to 2 the program ends
    char menu_stopper;
    char slot;
    Player p1;
    Player p2;
    Player p3;
    Player p4;
   std::string name;
    while(exit_menu == 0){
   sep();
        std:: cout<<"Welcome to Brandon's WIP RPG"<<std::endl;
        std::cout<<"Name pending... "<<std::endl;
   std::cout << "Please enter a file number to start or enter 0 to end the program: ";
   sep();
            std::cout << "Slot 1: "; p1.display();
            std::cout << "Slot 2: "; p2.display();
            std::cout << "Slot 3: "; p3.display();
            std::cout << "Slot 4: "; p4.display();
            std::cout << "-----------------------------" << std::endl;
                std::cin >> slot;

            switch(slot){
                case '1':
                    player_ptr = &p1;
                    if(player_ptr->Getname()== "   "){
                        std::cout << "Enter your name:";
                            getline(std::cin,name);
                            getline(std::cin,name);
                            player_ptr->setName(name);
                            sep();
                                std::cout << "Your stats: "<<std::endl;
                                std::cout << "Your player name is: "<< player_ptr->Getname() <<std::endl;
                                std::cout <<"Exp: " << player_ptr->Getexp() <<"/" << player_ptr->GetXpCap() << std::endl;
                                std::cout <<"Lvel: "<<  player_ptr->Getlvl()<< std::endl;
                                std::cout <<"Press any key and enter to continue: ";
                                sep();
                                std::cin >> menu_stopper;
                    }
                     menu(name);
                    break;
                case '2':
                    player_ptr = &p2;
                    if(player_ptr->Getname()== "   "){
                        std::cout << "Enter your name:";
                            getline(std::cin,name);
                            getline(std::cin,name);
                            player_ptr->setName(name);
                            sep();
                                std::cout << "Your stats: "<<std::endl;
                                std::cout << "Your player name is: "<< player_ptr->Getname() <<std::endl;
                                std::cout <<"Exp: " << player_ptr->Getexp() <<"/" << player_ptr->GetXpCap() << std::endl;
                                std::cout <<"Lvel: "<<  player_ptr->Getlvl()<< std::endl;
                                std::cout <<"Press any key and enter to continue: ";
                                sep();
                                std::cin >> menu_stopper;
                    }
                     menu(name);
                    break;

                case '3':
                    player_ptr = &p3;
                    if(player_ptr->Getname()== "   "){
                        std::cout << "Enter your name:";
                            getline(std::cin,name);
                            getline(std::cin,name);
                            player_ptr->setName(name);
                            sep();
                                std::cout << "Your stats: ";
                                std::cout << "Your player name is: "<< player_ptr->Getname() <<std::endl;
                                std::cout <<"Exp: " << player_ptr->Getexp() <<"/" << player_ptr->GetXpCap() << std::endl;
                                std::cout <<"Lvel: "<<  player_ptr->Getlvl()<< std::endl;
                                std::cout <<"Press any key and enter to continue: ";
                                sep();
                                std::cin >> menu_stopper;
                    }  menu(name);
                    break;

                case '4':
                    player_ptr = &p4;
                    if(player_ptr->Getname()== "   "){
                        std::cout << "Enter your name:";
                            getline(std::cin,name);
                            getline(std::cin,name);
                            player_ptr->setName(name);
                            sep();
                                std::cout << "Your stats: "<<std::endl;
                                std::cout << "Your player name is: "<< player_ptr->Getname() <<std::endl;
                                std::cout <<"Exp: " << player_ptr->Getexp() <<"/" << player_ptr->GetXpCap() << std::endl;
                                std::cout <<"Lvel: "<<  player_ptr->Getlvl()<< std::endl;
                                std::cout <<"Press any key and enter to continue: ";
                                sep();
                                std::cin >> menu_stopper;
                    }
                     menu(name);
                    break;

                case '0':
                    std::cout<< "Ending the program.";
                        exit_menu++;
                    break;

                default:
                sep();
                    std::cout<< "Error";
                    break;
            }
    }
    return 0;
}
void menu(std::string name){
    char user_choice = 0;
    int exit_menu = 1;
    while(exit_menu == 1){ //This is the menu loop, if the user enters 5(Exit) as their user_choice the program exits the loop and the program ends
        sep();
    std::cout << "What would you like to do?"<<std::endl;
        std::cout << "1 = Battle" <<std::endl;
        std::cout << "2 = Rest(used to heal)" <<std::endl;
        std::cout << "3 = Show stats" <<std::endl;
        std::cout << "4 = Shop " <<std::endl;
        std::cout << "5 = Main Menu";
    sep();

    std::cin >> user_choice;
   
        switch (user_choice)
        {
        case '1':
            *enemy_hp_ptr = 100;// Sets the emeny's hp to 100 if it wasn't set alread
            battle(name);
           
            break;
        case '2':
                sep();
                std::cout << "You rested and full healed!";
                player_ptr->SetHp(player_ptr->GetHpCap()); //Heals the player by setting the hp pointer equal to the players max hp
            break;

        case '3':
            
            player_ptr->stats();
            break;
        case '4':
              
            int temp_gold;
            temp_gold = player_ptr->Getgold();
            char shop_choice;
            s1.enterShop(); //Calls the shop. See shop.h for more detials
            std::cin>> shop_choice;
            switch(s1.store(shop_choice,temp_gold))
            {
                case 1:
                    player_ptr->setInventory(0);
                    player_ptr->setGold(-10);
                break;

                case 2:
                    player_ptr->setInventory(1);
                    player_ptr->setGold(-10);
                break;

                default:
                break;
            }
            break;
            

        case '5':
                exit_menu++;
            break;
        case '0':
            player_ptr->setExp(1000);
            player_ptr->setGold(1000);
            lvlup();
            break;

        default:
            std:: cout << "error"<<std::endl;
            break;
        }
    }
    std::cout << "Returning to main menu." << std::endl;
}







void battle(std::string name){
    
    char player_action; //Reads the players action
    if(player_ptr->GetHp()!= player_ptr->GetHpCap()){ //Check if the player is at full hp
        std::cout<< "You aren't at full hp! Do you still want to continue? (Y/N)"<<std::endl;
        std:: cout << "Your Hp: "<< player_ptr->GetHp() << std::endl;
        std::cin >> player_action;
    }
    if(player_action == 'n'||player_action=='N'|| player_ptr->GetHp()==0){

    }
    else{
        sep();
        std::cout << "What would you like to fight?"<< std::endl;
        std::cout << "1 = Slime"<<std::endl;
        std::cout << "2 = Fox"<<std::endl;
        std::cout << "3 = King Slime (Boss)";
        sep();
            std::cin >> enemy_type; //Takes in the user_choice for enemy type
        
    switch(enemy_type)
    {
        case 1:
    sep();
    std::cout << "A Slime appears: " << std::endl;

    while(player_ptr->GetHp() > 0 && *enemy_hp_ptr > 0){
       
        std::cout << "Slime: "<< enemy_hp << "/100"; 
        if(turn_timer > 0){
            std::cout << " -Burned"<< std::endl;
        }
        else    
           std::cout << std::endl;
        std::cout << name << ": " << player_ptr->GetHp() << "/"<<player_ptr->GetHpCap() << std::endl;
            std::cout << "Enter i to show move details."<< std::endl;
        std::cout << "What will you do?" << std::endl << "1 = Attack" << std::endl << "2 = Heavy Attack";
        
        if(player_ptr->Getlvl() >= 2){
            std::cout << std::endl << "3 = Execute";
        }
        if(player_ptr->Getlvl() >= 3){
            std::cout << std::endl << "4 = Fireball";
        }
        sep();
        std::cin >> player_action;

            switch (player_action)
            {
            case '1': 
                attack(enemy_hp_ptr, player_action,enemy_type);
                
                break;
            case '2': 
                attack(enemy_hp_ptr, player_action,enemy_type);
                break;
            case '3':
                if(player_ptr->Getlvl() >= 2){
                attack(enemy_hp_ptr, player_action,enemy_type);
                }
                break;
            case '4':
                if(player_ptr->Getlvl() >= 3){
                attack(enemy_hp_ptr, player_action,enemy_type);
                }
                break;
            case 'i':
                moveinfo();
                break;
                
            default:
                break;
            }

    }
    turn_timer =0;
      if(player_ptr->GetHp() <= 0){
        sep();
       std::cout << "You died to the slime!";
       player_ptr->SetHpZero();

    }
    else{
        sep();
        std::cout << "You won the battle! You got "<< 75 << " xp!"<< std::endl;
        std::cout << "And you got 10 gold";
        player_ptr->setGold(10);
        player_ptr->setExp(75);
        

    }

    if(player_ptr->Getexp() >= player_ptr->GetXpCap()){
        lvlup();
        }
        break;

          case 2:
                sep();
                std::cout << "A Fox appears: " << std::endl;

                while(player_ptr->GetHp() > 0 && *enemy_hp_ptr > 0){

                    if(bleed_timer > 0){
                    int bleed_damage;
                    bleed_damage = rand() % 16 +3;
                    std::cout << player_ptr->Getname()<<" took " << bleed_damage <<" bleed damage.";
                    sep();
                    player_ptr->SetHp(-bleed_damage);
                    bleed_timer--;
                    }

                std::cout << "Fox: "<< enemy_hp << "/100"; 
                    if(turn_timer > 0){
                    std::cout << " -Burned"<< std::endl;
                    }
                    else    
                        std::cout << std::endl;

                    std::cout << name << ": " << player_ptr->GetHp() << "/" <<player_ptr->GetHpCap();
                        if(bleed_timer > 0){
                        std::cout<< " -Bleeding";
                        }
                std::cout<<std::endl << "Enter i to show move details."<< std::endl;
                std::cout << "What will you do?" << std::endl << "1 = Attack" << std::endl << "2 = Heavy Attack (low acc)";
        
                    if(player_ptr->Getlvl() >= 2){
                    std::cout << std::endl << "3 = Execute";
                    }
                if(player_ptr->Getlvl() >= 3){
                    std::cout << std::endl << "4 = Fireball";
                }

                sep();
                std::cin >> player_action;

                switch (player_action)
                {
                    case '1': 
                        attack(enemy_hp_ptr, player_action,enemy_type);
                
                        break;

                    case '2': 
                        attack(enemy_hp_ptr, player_action,enemy_type);
                        break;

                    case '3':
                        if(player_ptr->Getlvl() >= 2){
                        attack(enemy_hp_ptr, player_action,enemy_type);
                        }
                        break;

                    case '4':
                        if(player_ptr->Getlvl() >= 3){
                        attack(enemy_hp_ptr, player_action,enemy_type);
                        }
                        break;
                    case 'i':
                        moveinfo();
                            break;
                
                    default:
                    break;
                }

}

    turn_timer =0;
    
      if(player_ptr->GetHp() <= 0){
       std::cout << "You died to the Fox!";
       player_ptr->SetHpZero();

    }
    else{
        std::cout << "You won the battle! You got "<< 75 << " xp!"<< std::endl;
        std::cout << "And you got 10 gold";
        player_ptr->setGold(10);
        player_ptr->setExp(75);

    }

    if(player_ptr->Getexp() >= player_ptr->GetXpCap()){
        lvlup();
        }
        break;

    case 3:

          sep();
    std::cout << "The King Slime appears: " << std::endl;
        *enemy_hp_ptr = 300;
    while(player_ptr->GetHp() > 0 && *enemy_hp_ptr > 0){
       
        std::cout << "King Slime: "<< enemy_hp << "/300"; 
        if(turn_timer > 0){
            std::cout << " -Burned"<< std::endl;
        }
        else    
           std::cout << std::endl;
        std::cout << name << ": " << player_ptr->GetHp() << "/" <<player_ptr->GetHpCap()<< std::endl;
            std::cout << "Enter i to show move details."<< std::endl;
        std::cout << "What will you do?" << std::endl << "1 = Attack" << std::endl << "2 = Heavy Attack (low acc)";
        
        if(player_ptr->Getlvl() >= 2){
            std::cout << std::endl << "3 = Execute";
        }
        if(player_ptr->Getlvl() >= 3){
            std::cout << std::endl << "4 = Fireball";
        }
        sep();
        std::cin >> player_action;

            switch (player_action)
            {
            case '1': 
                attack(enemy_hp_ptr, player_action,enemy_type);
                
                break;
            case '2': 
                attack(enemy_hp_ptr, player_action,enemy_type);
                break;
            case '3':
                if(player_ptr->Getlvl() >= 2){
                attack(enemy_hp_ptr, player_action,enemy_type);
                }
                break;
            case '4':
                if(player_ptr->Getlvl() >= 3){
                attack(enemy_hp_ptr, player_action,enemy_type);
                }
                break;
            case 'i':
                moveinfo();
                break;
                
            default:
                break;
            }

    }
    turn_timer =0;
   

      if(player_ptr->GetHp() <= 0){
        sep();
       std::cout << "You died to the King Slime!";
       player_ptr->SetHp(0);

    }
    else{
        sep();
        std::cout << "You won the battle! You got "<< 200 << " xp!"<<std::endl;
        std::cout << "And you got"<< 30 << "gold";
        player_ptr->setGold(30);
        player_ptr->setExp(200);

    }

    if(player_ptr->Getexp() >= player_ptr->GetXpCap()){
        lvlup();
        }

        break;

    default:
        std::cout << "Invalid" << std::endl;
        break;
        }
    }
}

void attack(int*& enemy_hp, char player_action,int enemy_name){
    int accuracy = 0;
    int damage = 0;
    int burn = 0;
    std::string type;
    if(enemy_name == 1){
        type = " slime ";
    }
        if(enemy_name== 2){
            type =" fox ";
        }
            if(enemy_name ==3){
                type = " King Slime ";
            }
        if(player_action == '1'){
        srand(time(NULL));

    accuracy = rand() % 11 + 1;
    damage = rand() % 20 + 1;
            
    if(player_ptr->Getinventory(0)== true){
            damage+= 10;
        }
        drained_hp = &damage;
        if(accuracy > 3){
            if(accuracy == 10){
                std::cout << "CRITICAL HIT ";
                damage= damage * 1.5;
            }
        std::cout << "You hit the" << type << "for: " << damage << " damage.";
         *enemy_hp= *enemy_hp -damage;;
         sep();
        enemy(enemy_hp,enemy_type);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(enemy_hp,enemy_type);
        }
     }
     if(player_action == '2'){
      srand(time(NULL));

    accuracy = rand() % 10 + 1;
    damage = rand() % 41 + 10;
         if(player_ptr->Getinventory(0)== true){
            damage+= 10;
        }
        drained_hp = &damage;
        if(accuracy > 6){
            if(accuracy == 10){
                std::cout << "CRITICAL HIT ";
                damage= damage * 1.5;
            }
        std::cout << "You hit the"<< type << "for: " << damage << " damage.";
         *enemy_hp= *enemy_hp -damage;;
         sep();
        enemy(enemy_hp,enemy_type);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(enemy_hp,enemy_type);
        }

     }
     if(player_action == '3'){
        srand(time(NULL));

    accuracy = rand() % 100 +1;
    damage = 9999;
        drained_hp = &damage;
        if(accuracy<=5){
        std::cout << "You hit the"<< type <<"for: " << damage << " damage.";
         *enemy_hp= *enemy_hp -damage;
         sep();
        enemy(enemy_hp,enemy_type);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(enemy_hp,enemy_type);
        }
     }
     if(player_action == '4'){
         srand(time(NULL));

    accuracy = rand() % 10 + 1;
    damage = rand() % 41 + 10;
    burn = rand() % 4 + 1;
    drained_hp = &damage;
        if(accuracy > 4){
            if(accuracy == 10){
                std::cout << "CRITICAL HIT ";
                damage= damage * 1.5;
            }
        std::cout << "You hit the"<< type << "for: " << damage << " damage.";
         *enemy_hp= *enemy_hp -damage;;
         sep();
         if(burn == 4){
            std::cout <<"You burned the" << type << std::endl;
            
            turn_timer=3;
         }
        
        enemy(enemy_hp,enemy_type);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(enemy_hp,enemy_type);
        }
     }
     
}
void enemy(int*& enemy_hp,int enemy_type){
    int accuracy;
    int damage;
    int bleed_chance;

        if(enemy_type == 1){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1,10);


if(*enemy_hp > 0){
    accuracy = dist(gen);
    damage = dist(gen)% 20 +6;
    if(turn_timer > 0){
        int burn_damage;
        burn_damage = rand() % 16 +3;
        std::cout << "The slime took " << burn_damage <<" damage from burn.";
        sep();
        *enemy_hp = *enemy_hp - burn_damage;
        turn_timer--;
    }
    if(player_ptr->Getinventory(1)== true){
            damage-= 10;
            if(damage<0){
                damage =0;
            }
        }  
        if(accuracy > 3){
            if(accuracy == 10){
                std::cout << "CRITICAL HIT ";
                damage= damage * 1.5;
            }
        std::cout << "The slime hit you for: " << damage << " damage.";
         player_ptr->SetHp(-damage);
         sep();
        }
        else {
            std::cout << "The slime missed!";
            
            sep();
        }

    }
        }

    if(enemy_type == 2){

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1,10);


if(*enemy_hp > 0){
    bleed_chance = dist(gen)% 4 + 1;
    accuracy = dist(gen);
    damage = dist(gen)% 20 +6;
    if(turn_timer > 0){
        int burn_damage;
        burn_damage = rand() % 16 +3;
        std::cout << "The Fox took " << burn_damage <<" damage from burn.";
        sep();
        *enemy_hp = *enemy_hp - burn_damage;
        turn_timer--;
    }
    if(player_ptr->Getinventory(1)== true){
            damage-= 10;
            if(damage<0){
                damage =0;
            }
        }  
        if(accuracy > 3){
            if(accuracy == 10){
                std::cout << "CRITICAL HIT ";
                damage= damage * 1.5;
            }
        std::cout << "The Fox hit you for: " << damage << " damage.";
         player_ptr->SetHp(-damage);
         sep();
         if(bleed_chance == 4){
             std:: cout << "The fox scratched you!"<< std:: endl;
             std:: cout << "You are now bleeding!";
             bleed_timer = 3;
             sep();

         }
        }
        else {
            std::cout << "The Fox missed!";
            
            sep();
            }
        }
    }

    if(enemy_type == 3){

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1,10);


if(*enemy_hp > 0){
    if(*enemy_hp <=150 && *enemy_hp>=100){
        
        std::cout << "The King Slime is in a weaked state, your next attacks will heal you!";
        sep();

        player_ptr->SetHp(*drained_hp);
       
    }  
    else{
    accuracy = dist(gen);
    damage = dist(gen)% 30 +6;
    if(turn_timer > 0){
        int burn_damage;
        burn_damage = rand() % 16 +3;
        std::cout << "The King Slime took " << burn_damage <<" damage from burn.";
        sep();
        *enemy_hp = *enemy_hp - burn_damage;
        turn_timer--;
    }
        if(player_ptr->Getinventory(1)== true){
            damage-= 10;
            if(damage<0){
                damage =0;
            }
        }  
        if(accuracy > 3){
            if(accuracy == 10){
                std::cout << "CRITICAL HIT ";
                damage= damage * 1.5;
            }
        std::cout << "The King Slime hit you for: " << damage << " damage.";
         player_ptr->SetHp(-damage);
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
    while(player_ptr->Getexp() >= player_ptr->GetXpCap()){
    player_ptr->setExp(-player_ptr->GetXpCap());
    player_ptr->setXpCap(100);
    player_ptr->setLvl(1);
    player_ptr->SetHpCap(10);

    sep();

    std::cout << "You leveled up!"<< std::endl;
    std::cout << "You are now level: "<< player_ptr->Getlvl()<< std::endl;
    std::cout << "And you gained 10 exrta hitpoints.";
    
    if(player_ptr->Getlvl() == 2){
        std::cout << std::endl << "You unlocked Execution!";
    }
    if(player_ptr->Getlvl()== 3){
        std::cout << std::endl << "You unlocked Fireball!";
    }

    }
    player_ptr->SetHp(player_ptr->GetHpCap());
}

void moveinfo(){
    char info_choice;
    int exit_menu =0;
    char menu_stopper;
    while(exit_menu==0){
        info_choice =0;
    sep();
    std::cout << "What move do you want info on?" <<std::endl;
    std::cout << "1 = Attack"<<std::endl;
    std::cout << "2 = Heavy attack"<<std::endl;
    std::cout << "3 = Execute"<<std::endl;
    std::cout << "4 = Fireball"<<std::endl;
    std::cout << "5 = Exit";
    sep();
    std::cin >> info_choice;


    switch (info_choice)
    {
    case '1':
        std::cout<<"Does ok damage and, has a 70"<< "% "<< "chance to hit the target.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> menu_stopper;
        break;
    case '2':
        std::cout << "Does heavy damage and, has a 40" << "% "<< "chance to hit the target.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> menu_stopper;
        break;

    case '3':
        std::cout << "Has a 5" << "% "<< " chance to hit the target, but always kills.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> menu_stopper;
        break;

    case '4':
        std::cout << "Does heavy damage and, has a 60" << "% "<< " chance to hit the target. Also has a 25"<< "% "<< "chance to burn.";
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> menu_stopper;
        break;

    case '5':
        exit_menu++;
        sep();
        break;

    default:
        break;
    }

    }
}