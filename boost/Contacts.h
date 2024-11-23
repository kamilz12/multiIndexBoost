//
// Created by Kamil on 17.11.2024.
//

#ifndef LAB6_DOMOWE_CONTACTS_H
#define LAB6_DOMOWE_CONTACTS_H

#include <boost/multi_index_container.hpp>
#include "Contact.h"
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/bind.hpp>

#include <iostream>

using namespace boost::multi_index;

class Contacts {
    typedef boost::multi_index_container<Contact, indexed_by<
            hashed_non_unique<member<Contact, string, &Contact::name>>,
            hashed_non_unique<member<Contact, string, &Contact::surrname>>,
            hashed_non_unique<member<Contact, string, &Contact::street>>,
            hashed_unique<member<Contact, int, &Contact::phone>>,
            ordered_non_unique <member<Contact, int, &Contact::age>>
    >> contact_multi;

    typedef contact_multi::nth_index<3>::type phone_type;
    typedef contact_multi::nth_index<2>::type street_type;
    typedef contact_multi::nth_index<4>::type ageType;
    contact_multi contacts;
public:

    void findAllOnStreet(const string& street);
    void findByPhone(int phone);
    void changeStreetName(const string& street, const string& newStreet);
    void removeContact(int phone);
    void showRangeAge(int beginRange, int endRange);
    void addContact(const Contact &contact);
    void show();
    void uniqueSurrnames();
};


#endif //LAB6_DOMOWE_CONTACTS_H
