#include <iostream>
#include <cstdlib>
#include "hero.h"
#include "character.h"


void initHero(Hero_t* hero, char* name, int health, int gold){
    hero->hero_name = name;
    hero->lifepoints = health;
    hero->gold = gold;
    for(int i = 0; i<10; i++){
        initItem(&hero->hero_items[i]);
    }
        for(int i = 0; i<2; i++){
        initItem(&hero->hero_gear[i]);
    }
}


void attack(Hero_t* hero, Character_t* enemy){
    int damage = 15 + rand()%11;
    enemy->lifepoints -= damage;
    std::cout << hero->hero_name << " trifft " << enemy->char_name << " für " << damage << " Schadenspunkte" << std::endl;
}


void sellItem(Hero_t* hero, int index){
    if(hero->hero_items[index].isValid){
        hero->hero_items[index].isValid = false;
        hero->gold += hero->hero_items[index].gold;
        std::cout << "Gegenstand " << hero->hero_items[index].name << " wurde verkauft. " << hero->hero_name << " bezitzt nun " << hero->gold << " Goldstücke." << std::endl;
    }
}


bool fight(Hero_t* hero, Character_t* enemy){
    
    bool hero_turn = true;

    while(hero->lifepoints > 0 && enemy->lifepoints > 0){
        
        if(hero_turn){
            attack(hero,enemy);
            hero_turn = false;
        } else {
            attack(enemy,hero);
            hero_turn = true;
        }
    }

    if(hero->lifepoints <= 0){
        return false;
    } else {
        return true;
    }
}