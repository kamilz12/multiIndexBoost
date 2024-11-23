#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <wsman.h>
#include <map>

/*Zadanie 5.1. Duplikat
Napisz funkcję, która jako argument przyjmuje kontener vector przechowujący liczby
całkowite. Zakładamy, że vektor przechowuje unikatowe wartości oprócz jednej, która została
zduplikowana. Zadaniem funkcji jest znalezienie wartości, która została zduplikowana oraz
policzenie sumy unikatowych elementów. Funkcja powinna zwrócić obiekt klasy pair.
W zadaniu należy wykorzystać kontener set. W funkcji main należy przetestować funkcję.*/
std::pair<int,int> zad51(std::vector <int>v) {
    std::sort(v.begin(),v.end());
    int suma = 0;

    std::pair <int,int> pair;
    for(auto it=v.begin();it!=v.end();it++) {
        if (v[*it] == v[*it+1]) {
            pair={*it,*it};
        }else {
            suma+=*it;

        }

    }std::cout << suma;
    return pair;
}

template<typename T>
void zad52(std::set <T> &s1, std::set <T> &s2) {
//     T sum1=0, sum2=0;
//     for(auto it=s1.begin();it!=s1.end();it++)
//         sum1+=*it;
//     for(auto it=s2.begin();it!=s2.end();it++)
//         sum2+=*it;
//     if (sum1>sum2) {
//         std::cout << "suma elementow znajdujace sie w 1 zbiorze" <<  sum1 - sum2 << std::endl;
//     }else {
//         std::cout << "suma elementow w 2 zbiorze" <<  sum2 - sum1 << std::endl;
//     }
// }
    std::set<T> result;
    T resultSum;
    std::set_difference(s1.begin(),s1.end(), s2.begin(), s2.end(),std::inserter(result,result.begin()));
    for (auto it=result.begin();it!=result.end();it++) {
        std::cout << *it << "\n";
    }
}

//Zadanie 5.3. Różnica
//        Napisz funkcję, która dostaje jako argumenty dwa napisy typu string. Drugi napis jest o jest
//        o jeden znak dłuższy od pierwszego. Drugi napis zawiera te same znaki co pierwszy napis tylko
//w różnej kolejności i dodatkowo jeszcze jeden znak. Zadaniem funkcji jest znalezienie znaku,
//który został dodany do drugiego napisu i zwrócenie go. W zadaniu należy wykorzystać
//kontener map. W main należy przetestować funkcję
/*
 *
 * s1: kolka, s2: lokkas
 * po sortowaniu*/
void zad53(std::string napis1, std::string napis2){
    std::sort(napis1.begin(), napis1.end());
    std::sort(napis2.begin(), napis2.end());
    std::cout << napis1 << " " << napis2;
}

int main() {
//    // std::vector<int> v ={1,2,3,4,5,2};
//    // std::pair <int   , int> pair = zad51(v);
//    std::set <int> s1, s2;
//    s1={1,2,3,4,5,6,7,8,9,10};
//    s2={2,3,4,5,6,7,8,9};
//    zad52(s2,s1);

    std::string napis1 = "kulka";
    std::string napis2 = "lukaku";
    zad53(napis1, napis2);
    return 0;
}
