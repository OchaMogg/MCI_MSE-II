#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"

#define OWN_STORY 1

int main(){

    Hero_t hero;
    Character_t enemy;

    initHero(&hero, (char*) "Annina", 300, 100);

    #if OWN_STORY
    std::cout << "\nUnsere Heldin " << hero.hero_name << " ist auf einem Abenteuer unterwegs! Sie hat " << hero.lifepoints << " Lebenspunkte und " << hero.gold << " Goldstücke " << std::endl;
    #endif 

    initCharacter(&enemy, (char*) "Matthias", 50, 100);
    
    #if OWN_STORY
    std::cout << "Unsere Heldin trifft auf einen Feind. Sein Name ist " << enemy.char_name << " und er hat " << enemy.lifepoints << " Lebenspunkte!" << std::endl << std::endl;
    #endif

    if(fight(&hero, &enemy)){
        std::cout << enemy.char_name << " fiel in Ohnmacht! " << hero.hero_name << " hat noch " << hero.lifepoints << " Lebenspunkte!" << std::endl;

        #if OWN_STORY
        std::cout << std::endl;
        #endif

    } else {
        std::cout << hero.hero_name << " fiel in Ohnmacht! " << enemy.char_name << " hat noch " << enemy.lifepoints << " Lebenspunkte!" << std::endl << std::endl;
        
        #if OWN_STORY
        std::cout << std::endl;
        #endif

        return 0;
    }

    initItem(&hero.hero_items[1],(char*) "Zaubertrank", 50);

    initCharacter(&enemy, (char*) "Pascal", 100, 100);

    #if OWN_STORY
    std::cout << "\nUnsere Heldin trifft auf einen Feind. Sein Name ist " << enemy.char_name << " und er hat " << enemy.lifepoints << " Lebenspunkte!" << std::endl << std::endl;
    #endif

    if(fight(&hero, &enemy)){
        std::cout << enemy.char_name << " fiel in Ohnmacht! " << hero.hero_name << " hat noch " << hero.lifepoints << " Lebenspunkte!" << std::endl;
        
        #if OWN_STORY
        std::cout << std::endl;
        #endif

    } else {
        std::cout << hero.hero_name << " fiel in Ohnmacht! " << enemy.char_name << " hat noch " << enemy.lifepoints << " Lebenspunkte!" << std::endl;
        
        #if OWN_STORY
        std::cout << std::endl;
        #endif

        return 0;
    }

    initItem(&hero.hero_items[2],(char*) "Schwert", 30);

    for( int i = 0; i < 10; i++ )
        sellItem(&hero, i);
    return 0;
}