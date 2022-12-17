//
//  main.cpp
//  EsameDaCancellare
//
//  Created by Maurizio Minieri on 09/09/2020.
//  Copyright © 2020 Maurizio Minieri. All rights reserved.
//

#include <iostream>
int dim = 2;

struct prova{
    char citta[30];
    int popolazione;
};

int getMax(){
    return 100;
}

int getMin(){
    return 1;
}



int main(int argc, const char * argv[]) {
    prova top[dim];
    
    for(int i=0;i<2;i++){
        std::cout<<("Scrivi la citta: "+i);
        std::cin>>top[i].citta;
        std::cout<<("Scrivi la popolazione: "+i);
        std::cin>>top[i].popolazione;
    }
    
    
    std::cout<<("STAMPA:\n");
    for(int i=0;i<dim;i++){
       std::cout<<top[i].citta<<"\n";
       std::cout<<top[i].popolazione<<"\n";
    }
    
    std::cout<<"Il minimo è: ";
    std::cout<<getMin();
    std::cout<<"Il massimo è: ";
    std::cout<<getMax();
    
    return 0;
}
