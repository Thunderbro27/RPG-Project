#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>


int php = 100;
int ehp = 100;
int expcap = 100;
int hpcap = 100;
    int* phpp = &php;
    int* ehpp = &ehp;
    int* dhp;
int ty =0;
int t=0;
int bt =0;


void sep();
void attack(int*&,char,int);
void battle(std::string);
void enemy(int*&,int*&,int);
void lvlup();
void moveinfo();

class Player{
    private: 
    int lvl;
    int exp;
    std::string name;
public:
    Player(){
        lvl = 1;
        exp = 0;
        name = "N/A";
    };

    int Getlvl(){return lvl;};
    int Getexp(){return exp;};
    std::string Getname(){return name;};
    void setLvl(int lvl){this->lvl +=lvl;};
    void setExp(int exp){this-> exp +=exp;};
    void setName(std::string name){this-> name = name;};
    void Displayer(){
        char e;
     sep();
        std::cout << this->name <<"'s stats: "<< std::endl;
        std::cout << "Level: " << this->lvl << std:: endl;
        std::cout << "HP: " << php << "/"<< hpcap <<std:: endl;
        std::cout << "EXP: " << exp << "/"<< expcap;
        sep();
        std::cout << "Press any key and enter to continue: ";
        std::cin >> e;
    }
};

    
    Player* ppf;

int main(){
    
    int w =1;
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
    
    while(w == 1){
        sep();
    std::cout << "What would you like to do?"<<std::endl;
        std::cout << "1 = Battle" <<std::endl;
        std::cout << "2 = Rest(used to heal)" <<std::endl;
        std::cout << "3 = Show stats" <<std::endl;
        std::cout << "4 = Exit";
    sep();

    std::cin >> choice;
   
        switch (choice)
        {
        case '1':
            *ehpp = 100;
            battle(name);
           
            break;
        case '2':
                sep();
                std::cout << "You rested and full healed!";
                *phpp =100;
            break;

        case '3':
            
            ppf->Displayer();
            break;

        case '4':
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



void sep(){
   std::cout<< std::endl <<  "-----------------------------" << std::endl;
}

void battle(std::string pname){
    
    char act;
    int c;
    if(*phpp!=hpcap){
        std::cout<< "You aren't at full hp!"<<std::endl;
    }
    else{
        sep();
        std::cout << "What would you like to fight?"<< std::endl;
        std::cout << "1 = Slime"<<std::endl;
        std::cout << "2 = Fox"<<std::endl;
        std::cout << "3 = King Slime (Boss)";
        sep();
            std::cin >> ty;
        
    switch(ty)
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
        std::cout << pname << ": " << php << "/100" << std::endl;
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
                attack(ehpp, act,ty);
                
                break;
            case '2': 
                attack(ehpp, act,ty);
                break;
            case '3':
                if(ppf->Getlvl() >= 2){
                attack(ehpp, act,ty);
                }
                break;
            case '4':
                if(ppf->Getlvl() >= 3){
                attack(ehpp, act,ty);
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
        std::cout << "You won the battle! You got "<< 75 << " exp!";
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
        std::cout << pname << ": " << php << "/100" << std::endl;
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
                attack(ehpp, act,ty);
                
                break;
            case '2': 
                attack(ehpp, act,ty);
                break;
            case '3':
                if(ppf->Getlvl() >= 2){
                attack(ehpp, act,ty);
                }
                break;
            case '4':
                if(ppf->Getlvl() >= 3){
                attack(ehpp, act,ty);
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
        std::cout << pname << ": " << php << "/100" << std::endl;
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
                attack(ehpp, act,ty);
                
                break;
            case '2': 
                attack(ehpp, act,ty);
                break;
            case '3':
                if(ppf->Getlvl() >= 2){
                attack(ehpp, act,ty);
                }
                break;
            case '4':
                if(ppf->Getlvl() >= 3){
                attack(ehpp, act,ty);
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
        enemy(phpp,hp,ty);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp, hp,ty);
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
        enemy(phpp,hp,ty);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp,hp,ty);
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
        enemy(phpp,hp,ty);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp, hp,ty);
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
        
        enemy(phpp,hp,ty);
        }
        else {
            std::cout << "You missed!";
            sep();
            enemy(phpp,hp,ty);
        }
     }
     
}
void enemy(int*& hp,int*& ehp,int ty){
    int r;
    int d;
    int c;

        if(ty == 1){
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

    if(ty == 2){

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

    if(ty == 3){

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1,10);


if(*ehp > 0){
    if(*ehp <=150 && *ehp>=100){
        
        std::cout << "The King Slime is in a weaked state, your next attacks will heal you!";
        sep();

        *hp =*hp + *dhp;
        if(*hp> hpcap){
            *hp = hpcap;
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

    sep();

    std::cout << "You lvled up!"<< std::endl;
    std::cout << "You are now level: "<< ppf->Getlvl();
    
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
