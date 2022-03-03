#ifndef HERO_H
#define HERO_H

#pragma once
#include <string>
#include <iostream>
#include "item.h"

#define MAX_ITEMS 10
#define MAX_GEAR 2

class Character;

class Hero{

    private:

        std::string name;
        int gold;
        int lifepoints;
        Item items[MAX_ITEMS];
        Item gear[MAX_GEAR];

    protected:

    public:
        void init_Hero(const std::string name, const int lifepoints, const int gold);
        void attack(Character &enemy);
        void sell_Item(const int index);
        bool fight(Character &enemy);
        int add_Inventar_Item(const Item& item);
        int add_Equipment_Item(const Item& item);
        Item* remove_Inventar_Item(const int slot);
        Item* remove_Equipment_Item(const int slot);

        void set_LP(const int damage);
        std::string get_name();

};

#include "character.h"

#endif