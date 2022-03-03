#include "hero.h"

void Hero::init_Hero(const std::string name, const int lifepoints, const int gold){
    this->name = name;
    this->lifepoints = lifepoints;
    this->gold = gold;
    for(int i = 0; i<MAX_ITEMS; i++){
        items[i].set_isValid(false);
    }
    for(int i = 0; i<MAX_GEAR; i++){
        gear[i].set_isValid(false);
    }
}

void Hero::attack(Character &enemy){
    
    std::srand(std::time(nullptr));
    int damage = 15 + rand()%11;
    enemy.set_LP(-damage);
    std::cout << this->name << " trifft " << enemy.get_name() << " für " << damage << " Schadenspunkte" << std::endl;
}


void Hero::sell_Item(const int index){
    if(this->items[index].get_isValid()){
        this->items[index].set_isValid(false);
        this->gold += this->items[index].get_gold();
        std::cout << "Gegenstand " << this->items[index].get_name() << " wurde verkauft. " << this->name << " bezitzt nun " << this->gold << " Goldstücke." << std::endl;
    }
}


bool Hero::fight(Character &enemy){
    
    bool hero_turn = true;

    while(this->lifepoints > 0 && enemy.get_LP() > 0){
        
        if(hero_turn){
            attack(enemy);
            hero_turn = false;
        } else {
            enemy.attack(*this);
            hero_turn = true;
        }
    }

    if(this->lifepoints <= 0){
        return false;
    } else {
        return true;
    }
}

int Hero::add_Inventar_Item(const Item &item){
    for(int i = 0; i < MAX_ITEMS; i++){
        if(!this->items[i].get_isValid()){
            this->items[i] = item;
            return i;
        }
    }

    return -1;
}

int Hero::add_Equipment_Item(const Item &item){
    for(int i = 0; i < MAX_GEAR; i++){
        if(!this->gear[i].get_isValid()){
            this->gear[i] = item;
            return i;
        }
    }

    return -1;
}

Item* Hero::remove_Inventar_Item(const int slot){
    if(this->items[slot].get_isValid()){
        this->items[slot].set_isValid(false);
        return &this->items[slot];
    }
    return nullptr;
}

Item* Hero::remove_Equipment_Item(const int slot){
    if(this->gear[slot].get_isValid()){
        this->gear[slot].set_isValid(false);
        return &this->gear[slot];
    }
    return nullptr;
}

void Hero::set_LP(const int damage){
    this->lifepoints += damage;
}

std::string Hero::get_name(){
    return this->name;
}