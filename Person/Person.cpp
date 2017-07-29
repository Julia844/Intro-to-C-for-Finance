#include "person.hpp"
// defining the things for the class
// the class person functions
Person::Person(const string&name, const DatasimDate& DateofBirth){
    nam = name;
    dob = DateofBirth;
    createDate = DatasimDate();
}
void Person:: print() const{
    cout << "\ n** Person Data **\ n";
    cout << "Name: " << nam << ", Date of birth: " << dob<< ", Age: " << age() << endl;

}
int Person:: age()const{

    return int(double(DatasimDate()-dob)/365.0);
}
