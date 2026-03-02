#include <iostream>
#include "Cat.h"

int Cat::count = 0;

Cat::Cat(const std::string& name, int age, const std::string& color)
    : name(name), age(age), color(color)
{
    ++count;
    std::cout << "Cat " << name << " created" << std::endl;
}

void Cat::printInfo() const {
    std::cout << "Cat: " << name << ", age=" << age << ", color=" << color << std::endl;
}

void Cat::sound() const {
    std::cout << "Cat makes a sound: Meow!" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat " << name << " destroyed" << std::endl;
    --count;
}

int Cat::getCount() {
    return count;
}

HouseCat::HouseCat(const std::string& name, int age, const std::string& color, const std::string& owner)
    : Cat(name, age, color), ownerName(owner)
{
    std::cout << "HouseCat " << name << " created" << std::endl;
}

void HouseCat::sound() const {
    std::cout << name << " purrs: Mrrr-mrrr" << std::endl;
}

void HouseCat::printInfo() const {
    Cat::printInfo();
    std::cout << "Owner: " << ownerName << std::endl;
}

void HouseCat::play() const {
    std::cout << name << " plays with a ball" << std::endl;
}

HouseCat::~HouseCat() {
    std::cout << "HouseCat " << name << " destroyed" << std::endl;
}

WildCat::WildCat(const std::string& name, int age, const std::string& color, const std::string& habitat)
    : Cat(name, age, color), habitat(habitat)
{
    std::cout << "WildCat " << name << " created" << std::endl;
}

void WildCat::sound() const {
    std::cout << name << " growls: Rrrr!" << std::endl;
}

void WildCat::printInfo() const {
    Cat::printInfo();
    std::cout << "Habitat: " << habitat << std::endl;
}

void WildCat::hunt() const {
    std::cout << name << " is hunting" << std::endl;
}

WildCat::~WildCat() {
    std::cout << "WildCat " << name << " destroyed" << std::endl;
}

PersianCat::PersianCat(const std::string& name, int age, const std::string& color, int woolLength)
    : Cat(name, age, color), woolLength(woolLength)
{
    std::cout << "PersianCat " << name << " created" << std::endl;
}

void PersianCat::sound() const {
    std::cout << name << " says softly: Meow" << std::endl;
}

void PersianCat::printInfo() const {
    Cat::printInfo();
    std::cout << "Wool length: " << woolLength << " cm" << std::endl;
}

void PersianCat::groom() const {
    std::cout << name << " needs grooming" << std::endl;
}

PersianCat::~PersianCat() {
    std::cout << "PersianCat " << name << " destroyed" << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    HouseCat hc1("Molly", 3, "white", "Alex");
    WildCat wc1("Shadow", 4, "black", "forest");
    PersianCat pc1("Luna", 2, "gray", 5);
    HouseCat hc2("Snow", 2, "white", "Mia");

    std::cout << "Инфо и поведение через объекты производных: ";
    hc1.printInfo();
    hc1.sound();
    hc1.play();

    pc1.printInfo();
    pc1.sound();
    pc1.groom();

    wc1.printInfo();
    wc1.sound();
    wc1.hunt();

    std::cout << "Общее число кошек: " << Cat::getCount() << std::endl;

    std::cout << "Конец программы";
    return 0;


}