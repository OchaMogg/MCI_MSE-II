#include "character.h"

void Character::init_Character(const std::string name, const int health, const int gold){
    this->name = name;
    this->lifepoints = health;
    this->gold = gold;
    for(int i = 0; i<10; i++){
        items[i].set_isValid(false);
    }
}


void Character::attack(Hero &hero){
    
    std::srand(std::time(nullptr));
    int damage = 5 + rand()%11;
    hero.set_LP(-damage);
    std::cout << this->name << " trifft " << hero.get_name() << " für " << damage << " Schadenspunkte" << std::endl;

}

int Character::add_Inventar_Item(const Item &item){
    for(int i = 0; i < MAX_ITEMS; i++){
        if(!this->items[i].get_isValid()){
            this->items[i] = item;
            return i;
        }
    }

    return -1;
}
Item* Character::remove_Inventar_Item(const int slot){
    if(this->items[slot].get_isValid()){
        this->items[slot].set_isValid(false);
        return &this->items[slot];
    }
    return nullptr;
}

void Character::set_LP(const int damage){
    this->lifepoints += damage;
}

int Character::get_LP(){
    return this->lifepoints;
}

std::string Character::get_name(){
    return this->name;
}