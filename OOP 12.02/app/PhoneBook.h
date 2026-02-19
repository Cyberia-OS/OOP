#pragma once

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <vector>
#include <fstream>

class Contact {
private:
    char* fullName;
    std::string homePhone, workPhone, mobilePhone, info;

public:
    Contact();
    Contact(const char* name, std::string home, std::string work, std::string mobile, std::string extra);
    Contact(const Contact& other);
    Contact& operator=(const Contact& other);
    ~Contact();

    inline const char* getFullName() const { return fullName; }
    void display() const;
    void saveToFile(std::ofstream& out) const;
};

class PhoneBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact();
    void showAll() const;
    void findByName(std::string name) const;
    void deleteContact(int index);
    void save(std::string filename);
    void load(std::string filename);
};

#endif
