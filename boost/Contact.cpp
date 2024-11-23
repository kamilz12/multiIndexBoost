
//
// Created by Kamil on 17.11.2024.
//

#include "Contact.h"

Contact::Contact(const string &name, const string &street, int age, int phone, const string &surrname) : name(name),
                                                                                                         street(street),
                                                                                                         age(age),
                                                                                                         phone(phone),
                                                                                                         surrname(
                                                                                                                 surrname) {}

const string &Contact::getName() const {
    return name;
}

void Contact::setName(const string &name) {
    Contact::name = name;
}

const string &Contact::getStreet() const {
    return street;
}

void Contact::setStreet(const string &street) {
    Contact::street = street;
}

int Contact::getAge() const {
    return age;
}

void Contact::setAge(int age) {
    Contact::age = age;
}

int Contact::getPhone() const {
    return phone;
}

void Contact::setPhone(int phone) {
    Contact::phone = phone;
}

const string &Contact::getSurrname() const {
    return surrname;
}

void Contact::setSurrname(const string &surrname) {
    Contact::surrname = surrname;
}
