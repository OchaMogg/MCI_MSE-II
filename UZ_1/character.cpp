#include <iostream>
#include "character.h"

void initCharacter(Character_t* character, char* name, int health, int gold){
    character->char_name = name;
    character->lifepoints = health;
    character->gold = gold;
    for(int i = 0; i<10; i++){
        initItem(&character->char_items[i]);
    }
}


void attack(Character_t* character, Hero_t* hero){

    int damage = 5 + rand()%11;
    hero->lifepoints -= damage;
    std::cout << character->char_name << " trifft " << hero->hero_name << " für " << damage << " Schadenspunkte" << std::endl;

}