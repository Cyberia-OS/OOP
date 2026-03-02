#pragma once
#include <string>

class Cat {
protected:
    std::string name;
    int age;
    std::string color;
    static int count; 

public:
    Cat(const std::string& name, int age, const std::string& color);
    void printInfo() const;
    void sound() const;
    ~Cat();

    static int getCount();


};

class HouseCat : public Cat {
private:
    std::string ownerName;

public:
    HouseCat(const std::string& name, int age, const std::string& color, const std::string& owner);
    void printInfo() const;
    void sound() const;
    void play() const;
    ~HouseCat();
};

class WildCat : public Cat {
private:
    std::string habitat;

public:
    WildCat(const std::string& name, int age, const std::string& color, const std::string& habitat);
    void printInfo() const;
    void sound() const;
    void hunt() const;
    ~WildCat();
};

class PersianCat : public Cat {
private:
    int woolLength;

public:
    PersianCat(const std::string& name, int age, const std::string& color, int woolLength);
    void printInfo() const;
    void sound() const;
    void groom() const;
    ~PersianCat();
};