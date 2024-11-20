#include <iostream>
#include "Contacts.h"
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <string>
#include <typeinfo>
#include <iostream>
#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/include/size.hpp>
#include <boost/fusion/container/vector.hpp>

using namespace std;


struct TypeCounter {
    std::map<std::string, int>& typeCounts;

    TypeCounter(std::map<std::string, int>& counts) : typeCounts(counts) {}

    template<typename T>
    void operator()(const T& element) const {
        std::string typeName = typeid(element).name();
        typeCounts[typeName]++;
    }
};

std::map<std::string, int> countTypesInFusionVector(const boost::fusion::vector<>& fusionVector) {
    std::map<std::string, int> typeCounts;
     boost::fusion::for_each(fusionVector, TypeCounter(typeCounts));

    return typeCounts;
}

template <typename T>
void statistic(vector <T> vec){
    T sum = std::accumulate(vec.begin(), vec.end(),T(0));
    double avg = static_cast <double>(sum)/vec.size();
    double median;
    std::vector<T> sortedVec = vec;

    std::sort(sortedVec.begin(), sortedVec.end());
    size_t n = sortedVec.size();
    if (n % 2 == 0) {
        median = (sortedVec[n / 2 - 1] + sortedVec[n / 2]) / 2.0;
    } else {
        median = sortedVec[n / 2];
    }

    // Elementy mniejsze niż średnia arytmetyczna
    std::cout << "Elements smaller than the average (" << avg << "): ";
    std::for_each(vec.begin(), vec.end(), [&](T element) {
        if (element < avg) std::cout << element << " ";
    });
    std::cout << "\n";

    // Elementy między średnią a medianą
    std::cout << "Elements between the average (" << avg << ") and the median (" << median << "): ";
    std::for_each(vec.begin(), vec.end(), [&](T element) {
        if (element >= avg && element <= median) std::cout << element << " ";
    });
    std::cout << "\n";

    // Elementy dodatnie
    std::cout << "Positive elements: ";
    std::for_each(vec.begin(), vec.end(), [](T element) {
        if (element > 0) std::cout << element << " ";
    });
    std::cout << "\n";

}


int main() {

/*    Contacts contacts;
    contacts.addContact( {"Kamil", "Bazyliowa", 15,22222222, "Bonk"});
    contacts.addContact({"Kamil", "Bazyliowa", 20,12222222, "Bonk"});
    contacts.addContact({"Kamil", "Bazyliowa", 17, 23222222, "Wonk"});
    contacts.addContact({"Kamil", "Bazyliowa", 13,22242222, "Bonk"});
    contacts.addContact({"Kamil", "Kraftowa", 11,222242222, "Bonk"});
    contacts.addContact({"Kamil", "Bazyliowa", 13,22242222, "Bonk"});
    //contacts.findAllOnStreet("Bazyliowa");
    //contacts.showRangeAge(15,20);
    //contacts.show();
    //contacts.changeStreetName("Bazyliowa", "LovaLowa");
    //contacts.uniqueSurrnames();
    //contacts.show();
    */

    std::vector<int> vec = {1, 3, -5, 7, 9, 2, -4, 6};
    statistic(vec);

    std::vector<double> vecD = {1.5, -2.3, 3.7, 0.0, 4.4};
    statistic(vecD);
    return 0;
}
