#include "item.h"
#include <fstream>

void Item::init_Item(const std::string type){
    
    std::ifstream myfile;
    std::string line;
    std::string delimiter = ";";
    std::srand(std::time(nullptr));
    int rand_item = 1 + rand()%15;
    int i = 0;
    
    if(type == "items"){
        myfile.open("items");
    } else if (type == "gear"){
        myfile.open("gear");
    }

    for( std::string line; getline(myfile,line); i++){
        if(i == rand_item){
            //parse it
            std::string token = line.substr(0, line.find(delimiter));
            this->name = token;
            line.erase(0, line.find(delimiter) + delimiter.length());
            this->gold = stoi(line);
            break;
        }
    }
    std::cout << "Der Gegenstand " << name << " wurde dem Inventar der Heldin hinzugefügt!" << std::endl;

    myfile.close();

}


bool Item::get_isValid(){
    return this->isValid;
}
void Item::set_isValid(bool value){
    this->isValid = value;
}

int Item::get_gold(){
    return this->gold;
}
std::string Item::get_name(){
    return this->name;
}