#ifndef ITEM_H
#define ITEM_H

#include <string>

struct Item_t {

    std::string name;
    int gold;
    bool isValid;

};

void initItem(Item_t* ITEM, char* name, int gold);
void initItem(Item_t* gegenstand);

#endif