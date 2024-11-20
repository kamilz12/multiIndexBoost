//
// Created by Kamil on 17.11.2024.
//

#ifndef LAB6_DOMOWE_CONTACT_H
#define LAB6_DOMOWE_CONTACT_H
#include <boost/multi_index_container.hpp>
#include <iostream>

using namespace std;

class Contact {
public:
    string name;
    string surrname;
    int phone;
    int age;
    string street;
public:
    Contact(const string &name, const string &street, int age, int phone, const string &surrname);
    void show() const {
        std::cout << name << " " << surrname << " " << age << " " << phone << street <<std::endl;
    }

    const string &getName() const;

    void setName(const string &name);

    const string &getStreet() const;

    void setStreet(const string &street);

    int getAge() const;

    void setAge(int age);

    int getPhone() const;

    void setPhone(int phone);

    const string &getSurrname() const;

    void setSurrname(const string &surrname);
};


#endif //LAB6_DOMOWE_CONTACT_H
