#ifndef PERSON_HPP_INCLUDED
#define PERSON_HPP_INCLUDED

#include "datasimdate.hpp"
#include <string>
using namespace std;
class Person{
public:
    string nam;
    DatasimDate dob;
    DatasimDate createDate;
public:
    Person(const string& name, const DatasimDate& DateofBirth);
    void print() const;
    int age() const;

};


#endif // PERSON_HPP_INCLUDED
