#ifndef ITEM_H
#define ITEM_H

#pragma once
#include <string>
#include <iostream>
#include <ctime>

class Item
{

    private:
        std::string name;
        int gold;
        bool isValid;

    protected:

    public:
        void init_Item(const std::string type);

        bool get_isValid();
        void set_isValid(bool value);
        int get_gold();
        std::string get_name();

};

#endif