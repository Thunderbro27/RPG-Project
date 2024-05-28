#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "Seperate.h"

class Shop{
private:
    std::string item_id[2];
public: 
Shop(){
    item_id[0] = "Sword";
    item_id[1] = "Armor";
};
void enterShop(){
    sep();
    std::cout << "Welcome to the shop" << std::endl;
    std::cout << "What would you like to buy? Or enter i for info: " <<std::endl;
    std::cout << "1 = "<< item_id[0]<<" 10G"<< std::endl<<"2 = "<< item_id[1]<<" 10G";
    sep();
};

int store(char shop_choice, int gold){
    char yes_no;
    while(true){
    switch (shop_choice){
    case '1':
        std::cout<<"Buy the "<< item_id[0]<< "? Y/N"<< std::endl;
            std::cin >> yes_no;
            if(yes_no == 'Y' || yes_no =='y'){
                if(gold!= 10){
                    sep();
                    std:: cout<< "You dont have enough gold to buy this sword.";
                    return NULL;
                }
                else{
                    std::cout << "You bought the sword.";
                    sep();
                    return 1;
                }


            }
        else {

        }

        break;

    case '2':
         std::cout<<"Buy the "<< item_id[1]<< "? Y/N"<< std::endl;
            std::cin >> yes_no;
            if(yes_no == 'Y' || yes_no =='y'){
                if(gold!= 10){
                    sep();
                    std:: cout<< "You dont have enough gold to buy this "<<item_id[1];
                    return NULL;
                }
                else{
                    std::cout << "You bought the "<<item_id[1];
                    sep();
                    return 2;
                }


            }
        else {

        }

        break;

    case 'i':
        sep();
            std::cout <<"The sword adds 10 to your attacks."<< std:: endl;
            std::cout <<"The body armor makes you take 10 less damage."<< std::endl;
            sep();
        break;
    
    default:
        break;
        }
    }
}
   
};
#endif 
/*
Shop caller: 


char ch;
            Shop.enterShop();
            std::cin>> ch;
            Shop.Choice(ch);


*/

// How do we link the shop to the gold member in the player class 
