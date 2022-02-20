#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"

int main(){

    Hero_t hero;
    Character_t enemy;
    bool fight_won;

    initHero(&hero, (char*) "Annina", 300, 100);

    std::cout << "\nUnsere Heldin " << hero.hero_name << " ist auf einem Abenteuer unterwegs! Sie hat " << hero.lifepoints << " Lebenspunkte und " << hero.gold << " Goldstücke " << std::endl;

    initCharacter(&enemy, (char*) "Matthias", 50, 100);

    std::cout << "Unsere Heldin trifft auf einen Feind. Sein Name ist " << enemy.char_name << " und er hat " << enemy.lifepoints << " Lebenspunkte!" << std::endl << std::endl;

    fight_won = fight(&hero, &enemy);

    if(fight_won){
        std::cout << enemy.char_name << " fiel in Ohnmacht! " << hero.hero_name << " hat noch " << hero.lifepoints << " Lebenspunkte!" << std::endl << std::endl;
    } else {
        std::cout << hero.hero_name << " fiel in Ohnmacht! " << enemy.char_name << " hat noch " << enemy.lifepoints << " Lebenspunkte!" << std::endl << std::endl;
        return 0;
    }

    initItem(&hero.hero_items[1],(char*) "Zaubertrank", 50);
    initCharacter(&enemy, (char*) "Pascal", 100, 100);

    std::cout << "\nUnsere Heldin trifft auf einen Feind. Sein Name ist " << enemy.char_name << " und er hat " << enemy.lifepoints << " Lebenspunkte!" << std::endl << std::endl;

    fight_won = fight(&hero, &enemy);

        if(fight_won){
        std::cout << enemy.char_name << " fiel in Ohnmacht! " << hero.hero_name << " hat noch " << hero.lifepoints << " Lebenspunkte!" << std::endl << std::endl;
    } else {
        std::cout << hero.hero_name << " fiel in Ohnmacht! " << enemy.char_name << " hat noch " << enemy.lifepoints << " Lebenspunkte!" << std::endl << std::endl;
        return 0;
    }

    initItem(&hero.hero_items[2],(char*) "Zaubertrank", 50);

    sellItem(&hero, 1);
    sellItem(&hero, 2);

    return 0;

}