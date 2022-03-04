#include "hero.h"


int main(){

    std::srand(std::time(nullptr));
    Hero hero;
    Character enemy;
    int random_item;

    // initiere eine Heldin und einen Gegner
    hero.init_Hero("Annina", 300, 100);
    enemy.init_Character("Matthias", 50, 100);

    //Story Textzeilen:
    std::cout << "\nUnsere Heldin " << hero.get_name() << " ist auf einem Abenteuer unterwegs! Sie hat " << hero.get_LP() << " Lebenspunkte und " << hero.get_gold() << " Goldstücke " << std::endl;

    std::cout << "Unsere Heldin trifft auf einen Feind. Sein Name ist " << enemy.get_name() << " und er hat " << enemy.get_LP() << " Lebenspunkte!" << std::endl << std::endl;
    
    //fügt ein beliebiges Item dem Inventar des Gegners hinzu
    enemy.init_Item_Slots();

    //initiert den Kampf und druckt dessen Resultate
    hero.print_fight_result(hero.fight(enemy), enemy);

    //entfernt einen zufälligen Gegenstand aus dem Inventar des Gegners und fügt ihn zum Inventar der Heldin hinzu
    random_item = rand()%10;
    hero.add_Inventar_Item(*enemy.remove_Inventar_Item(random_item));

    //initiere einen neuen Gegner
    enemy.init_Character("Pascal", 100, 100);

    //Story Textzeile:
    std::cout << "Unsere Heldin trifft auf einen weiteren Feind. Sein Name ist " << enemy.get_name() << " und er hat " << enemy.get_LP() << " Lebenspunkte!" << std::endl << std::endl;

    //fügt ein beliebiges Item dem Inventar des Gegners hinzu
    enemy.init_Item_Slots();
    // enemy.get_Inventory(0)->init_Item("items", enemy.get_name());

    //initiert den Kampf und druckt dessen Resultate
    hero.print_fight_result(hero.fight(enemy), enemy);

    //entfernt einen zufälligen Gegenstand aus dem Inventar des Gegners und fügt ihn zum Inventar der Heldin hinzu
    random_item = rand()%10;
    hero.add_Inventar_Item(*enemy.remove_Inventar_Item(random_item));


    //verkauft alle Items des Helden
    hero.sell_Items();

}