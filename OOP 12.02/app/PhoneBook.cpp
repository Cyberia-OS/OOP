#define _CRT_SECURE_NO_WARNINGS
#include "PhoneBook.h"
#include <iostream>
#include <cstring>

using namespace std;

Contact::Contact() : fullName(nullptr) {}

Contact::Contact(const char* name, string home, string work, string mobile, string extra)
    : homePhone(home), workPhone(work), mobilePhone(mobile), info(extra) {
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

Contact::Contact(const Contact& other) : homePhone(other.homePhone), workPhone(other.workPhone),
mobilePhone(other.mobilePhone), info(other.info) {
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);
}

Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        delete[] fullName;
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);
        homePhone = other.homePhone; workPhone = other.workPhone;
        mobilePhone = other.mobilePhone; info = other.info;
    }
    return *this;
}

Contact::~Contact() { delete[] fullName; }

void Contact::display() const {
    cout << "ÔÈÎ: " << (fullName ? fullName : "---") << "\nÌîá: " << mobilePhone << "\nÈíôî: " << info << "\n\n";
}

void Contact::saveToFile(ofstream& out) const {
    out << fullName << "\n" << homePhone << "\n" << workPhone << "\n" << mobilePhone << "\n" << info << "\n";
}

// Ðåàëèçàöèÿ PhoneBook
void PhoneBook::addContact() {
    string n, h, w, m, i;
    cout << "ÔÈÎ: "; getline(cin >> ws, n);
    cout << "Ìîá: "; getline(cin, m);
    cout << "Èíôî: "; getline(cin, i);
    contacts.emplace_back(n.c_str(), h, w, m, i);
}

void PhoneBook::showAll() const {
    for (int i = 0; i < contacts.size(); i++) {
        cout << "[" << i << "] "; contacts[i].display();
    }
}

void PhoneBook::findByName(string name) const {
    for (const auto& c : contacts) if (string(c.getFullName()) == name) c.display();
}

void PhoneBook::deleteContact(int index) {
    if (index >= 0 && index < contacts.size()) contacts.erase(contacts.begin() + index);
}

void PhoneBook::save(string filename) {
    ofstream out(filename);
    for (const auto& c : contacts) c.saveToFile(out);
}

void PhoneBook::load(string filename) {
    ifstream in(filename);
    if (!in) return;
    contacts.clear();
    string n, h, w, m, i;
    while (getline(in, n) && getline(in, h) && getline(in, w) && getline(in, m) && getline(in, i))
        contacts.emplace_back(n.c_str(), h, w, m, i);
}
