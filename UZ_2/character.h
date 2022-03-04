#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once

#include <string>
#include "item.h"

class Hero;

class Character
{
    private:
        std::string name;
        int gold;
        int lifepoints;
        Item items[10];

    protected:

    public:

        void init_Character(const std::string name, const int health, const int gold);
        void init_Item_Slots();
        void attack(Hero &hero);
        int add_Inventar_Item(Item& item);
        Item* remove_Inventar_Item(const int slot);

        
        void set_LP(const int damage);
        int get_LP();
        std::string get_name();
        Item* get_Inventory(int index);

};

#include "hero.h"

#endif