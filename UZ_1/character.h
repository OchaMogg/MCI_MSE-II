#ifndef CHARACTER_H
#define CHARACTER_H

#include "hero.h"

struct Hero_t;

struct Character_t {
    std::string char_name;
    int lifepoints;
    int gold;
    Item_t char_items[10];
};

void initCharacter(Character_t* character, char* name, int health, int gold);
void attack(Character_t* character, Hero_t* hero);

#endif