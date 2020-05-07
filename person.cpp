/*
 * Title:		Inheritance Lab 2
 * Purpose:		Construct vectors of Person/Person subclass objects to practice inheritance concepts
 * Author:		Andrew McLain
 * Date:		05/01/2020
 */

#include "person.h"
#include "date.h"


//Person constructor
//Parameters:
//  const string &name - name of person
//  const Date &birthday - birth date of person
//Returns:
//  nothing
Person::Person(const string &name, const Date &birthday) :  _name(name),
                                                            _birthday(birthday.GetYear(), birthday.GetMonth(),
                                                                      birthday.GetDay())
{

}

//Person constructor
//Parameters:
//  const string &name - name of person
//  size_t year - birth year
//  size_t month - birth month
//  size_t day - birth day
//Returns:
//  nothing
Person::Person(const string &name, size_t year, size_t month, size_t day) :  _name(name),
                                                                             _birthday(year, month, day)
{

}

//Person destructor
//Parameters:
//  none
//Returns:
//  nothing
Person::~Person() {

}

//ToString
//returns string of person information
//Parameters:
//  none
//Returns:
//  string - person's information
string Person::ToString() const {
    std::stringstream ss;
    ss << "{name: " << _name << ", birthday: {year: " << _birthday.GetYear() << ", month: "
       << _birthday.GetMonth() << ", day: " << _birthday.GetDay() << "}}";
    return ss.str();
}

//Read
//Reads information from input stream to mutate person data members
//Parameters:
// istream &input - input containing new data member values
//Returns:
//  nothing
void Person::Read(istream &input) {
    input >> _name;
    if (input.fail()){
        _name = "";
    }
    input >> _birthday;
}

//Write
//Writes person's data members into output stream
//Parameters:
//  ostream &output - output to read data members into
//Returns:
//  nothing
void Person::Write(ostream &output) const {
    output << _name << " " << _birthday;
}

//GetName
//returns name of the person
//Parameters:
//  none
//Returns:
//  string - person name
string Person::GetName() const {
    return _name;
}

//GetAge
//returns age of the person
//Parameters:
//  none
//Returns:
//  size_t - person's age
size_t Person::GetAge() const {
    return _birthday.Difference(_birthday.Now()) / 365;
}
