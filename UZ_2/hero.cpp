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
void Hero::sell_Items(){
    for(int i=0; i < MAX_ITEMS; i++){
        this->sell_Item(i);
    }
}
void Hero::sell_gear(const int index){
    if(this->gear[index].get_isValid()){
        this->gear[index].set_isValid(false);
        this->gold += this->gear[index].get_gold();
        std::cout << "Gegenstand " << this->gear[index].get_name() << " wurde verkauft. " << this->name << " bezitzt nun " << this->gold << " Goldstücke." << std::endl;
    }
}
void Hero::sell_gears(){
    for(int i=0; i < MAX_GEAR; i++){
        this->sell_gear(i);
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

void Hero::print_fight_result(bool result, Character &enemy){ 
    if(result){
        std::cout << enemy.get_name() << " fiel in Ohnmacht! " << this->name << " hat noch " << this->lifepoints << " Lebenspunkte!" << std::endl << std::endl;
    } else {
        std::cout << this->name << " fiel in Ohnmacht! " << enemy.get_name() << " hat noch " << enemy.get_LP() << " Lebenspunkte!" << std::endl << std::endl << std::endl;
        exit(0);
    }
}

int Hero::add_Inventar_Item(Item &item){
    for(int i = 0; i < MAX_ITEMS; i++){
        if(this->items[i].get_isValid() == false){
            this->items[i].set_name(item.get_name());
            this->items[i].set_gold(item.get_gold());
            this->items[i].set_isValid(true);
            std::cout << "Der Gegenstand " << this->items[i].get_name() << " wurde dem Inventar von " << this->name << " hinzugefügt." << std::endl;
            return i;
        }
    }
    std::cout << "Kein Platz mehr vorhanden" << std::endl;
    return -1;
}

int Hero::add_Equipment_Item(Item &item){
    for(int i = 0; i < MAX_GEAR; i++){
        if(!this->gear[i].get_isValid()){
            this->gear[i].set_name(item.get_name());
            this->gear[i].set_gold(item.get_gold());
            this->gear[i].set_isValid(true);
            std::cout << "Der Gegenstand " << this->items[i].get_name() << " wurde dem Inventar von " << this->name << " hinzugefügt." << std::endl;
            return i;
        }
    }
    std::cout << "Kein Platz mehr vorhanden" << std::endl;
    return -1;
}

Item* Hero::remove_Inventar_Item(const int slot){
    if(this->items[slot].get_isValid()){
        this->items[slot].set_isValid(false);
        std::cout << "Der Gegenstand " << this->items[slot].get_name() << " wurde aus dem Inventar von " << this->name << " entfernt." << std::endl;
        return &this->items[slot];
    }
    return nullptr;
}

Item* Hero::remove_Equipment_Item(const int slot){
    if(this->gear[slot].get_isValid()){
        this->gear[slot].set_isValid(false);
        std::cout << "Der Gegenstand " << this->items[slot].get_name() << " wurde aus dem Inventar von " << this->name << " entfernt." << std::endl;
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

int Hero::get_LP(){
    return this->lifepoints;
}
int Hero::get_gold(){
    return this->gold;
}

Item* Hero::get_Inventory(int index){
    return &this->items[index];
}