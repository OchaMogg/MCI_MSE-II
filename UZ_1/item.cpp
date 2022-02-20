#include "item.h"
#include <iostream>

void initItem(Item_t* ITEM, char* name, int gold){
    ITEM->name = name;
    ITEM->gold = gold;
    ITEM->isValid = true;
    std::cout << "Der Gegenstand " << name << " wurde dem Inventar der Heldin hinzugefügt!" << std::endl;
}


void initItem(Item_t* gegenstand){
    gegenstand->isValid = false;
}