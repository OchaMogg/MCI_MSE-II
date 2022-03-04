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
        void init_Item(const std::string type, const std::string c_name);

        bool get_isValid();
        void set_isValid(bool value);
        void set_gold(const int gold);
        int get_gold();
        void set_name(const std::string name);
        std::string get_name();

};

#endif