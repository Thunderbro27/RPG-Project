#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "Seperate.h"

class Shop{
private:
    std::string id[2]={"Sword 10G","Armor 10G"};
public: 

void enterShop(){
    sep();
    std::cout << "Welcome to the shop" << std::endl;
    std::cout << "What would you like to buy? Or enter i for info: " <<std::endl;
    std::cout << "1 = "<< id[0]<< std::endl<<"2 = "<< id[1];
    sep();
};

void Choice(char c){
    switch (c)
    {
    case '1':
        std::cout<<"Buy the "<< id[0]<< "? Y/N";
        break;

    case '2':
        std::cout <<"Buy the "<< id[1]<< "? Y/N";
        break;

    case 'i':
        break;
    
    default:
        break;
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
