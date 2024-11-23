//
// Created by Kamil on 17.11.2024.
//

#include <set>
#include "Contacts.h"

void Contacts::uniqueSurrnames() {
    cout << "Unikalne nazwiska: " <<endl;
    set <string> uniqueSurrnames;
    for (const auto&contact : contacts){
        uniqueSurrnames.insert(contact.surrname);
    }
    for (const auto&surrname: uniqueSurrnames){
        cout << surrname <<endl;
    }
}

void Contacts::show() {
    cout <<"Polecenie show()" << endl;
    for (const auto & contact : contacts) {
        std::cout << contact.name << " " << contact.surrname << " " << contact.age << " " << contact.phone << contact.street <<std::endl;
    }
}

void Contacts::addContact(const Contact &contact) {
    phone_type &phone_index = contacts.get<3>();
    auto it = phone_index.find(contact.phone);
    if (!(it->phone == contact.phone)) {
        contacts.insert(contact);
    } else {
        cout << "Ten kontakt juz istnieje!" <<endl;
    }
}

void Contacts::showRangeAge(int beginRange, int endRange) {
    auto &ageIndex = contacts.get<4>();
    auto iterStart = ageIndex.equal_range(beginRange);
    auto iterEnd = ageIndex.equal_range(endRange);
    for (auto it=iterStart.first; it!=iterEnd.second; ++it)
    {it->show();
    };
}

void Contacts::removeContact(int phone) {
    cout << "Usuwanie kontaktu";
    auto &phone_type = contacts.get<3>();
    auto it = phone_type.find(phone);
    if(it!=phone_type.end()){
        it->show();
        phone_type.erase(it);
    }
}

void Contacts::changeStreetName(const string &street, const string &newStreet) {
    cout << "Osoby na ulicy: " << street << endl;

    auto &street_type = contacts.get<2>();
    auto range = street_type.equal_range(street);

    for (auto it = range.first; it != range.second;) {
        auto current = it++;
        street_type.modify(current, [&](Contact &contact) {
            contact.street = newStreet;
        });
    }
}

void Contacts::findByPhone(int phone) {
    cout << "Szukanie po numerze telefonu " <<  phone;
    auto &phone_type = contacts.get<3>();
    auto it = phone_type.find(phone);
    if (it!=phone_type.end()){
        it->show();
    }
}

void Contacts::findAllOnStreet(const string &street) {
    cout << "Osoby na ulicy: " << street << endl;
    auto &street_type = contacts.get<2>();
    auto range = street_type.equal_range(street);
    for (auto it = range.first; it != range.second; ++it)
        it->show();
}
