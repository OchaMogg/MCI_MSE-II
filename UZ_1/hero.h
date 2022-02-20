#ifndef HERO_H
#define HERO_H

#include <string>
#include "item.h"
#include "character.h"

struct Character_t;

struct Hero_t {
    std::string hero_name;
    int lifepoints;
    int gold;
    Item_t hero_items[10];
    Item_t hero_gear[2];
};

void initHero(Hero_t* hero, char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);
bool fight(Hero_t* hero, Character_t* enemy);


#endif