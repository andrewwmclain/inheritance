/*
 * Title:		Inheritance Lab 2
 * Purpose:		Construct vectors of Person/Person subclass objects to practice inheritance concepts
 * Author:		Andrew McLain
 * Date:		05/01/2020
 */

#include "date.h"
#include "person.h"
#include "professor.h"

//Professor constructor
//Parameters:
//  const string &name - name of professor
//  const Date &birthday - birth date of professor
//  const string &department - department of professor
//Returns:
//  nothing
Professor::Professor(const string &name, const Date &birthday, const string &department) :
                     Person(name, birthday),
                     _department(department),
                     _hireDate(Date::Now()),
                     _rank(ASSISTANT_PROFESSOR),
                     _salary(60000)
{

}

//Professor constructor
//Parameters:
//  const string &name - name of professor
//  const Date &birthday - birth date of professor
//  const string &department - department of professor
//  const Date &hireDate - hire date of professor
//Returns:
//  nothing
Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate) :
                     Person(name, birthday),
                     _department(department),
                     _hireDate(hireDate)
{
    if((Date::Now().Difference(_hireDate)/365) < 5){
        _rank = ASSISTANT_PROFESSOR;
        _salary = 60000;
    }
    else if((Date::Now().Difference(_hireDate)/365) < 10){
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000;
    }
    else{
        _rank = PROFESSOR;
        _salary = 75000;
    }
}

//Professor constructor
//Parameters:
//  const string &name - name of professor
//  const Date &birthday - birth date of professor
//  const string &department - department of professor
//  Rank rank - rank of professor
//  float salary - salary of professor
//Returns:
//  nothing
Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate,
                     Rank rank, float salary) :  Person(name, birthday),
                                                _department(department),
                                                _hireDate(hireDate),
                                                _rank(rank),
                                                _salary(salary)

{

}

//Professor destructor
//Parameters:
//  none
//Returns:
//  nothing
Professor::~Professor() {

}

//ToString
//returns string of professor information
//Parameters:
//  none
//Returns:
//  string - professor's information
string Professor::ToString() const {
    std::stringstream ss;
    ss << "{Person: " << Person::ToString() << ", department: " << _department << ", rank: " << _rank
        << ", hire-date: {year: "  << _hireDate.GetYear() << ", month: " << _hireDate.GetMonth() <<
        ", day: " << _hireDate.GetDay() << "}, salary: " << _salary << "}";
    return ss.str();
}

//Read
//Reads information from input stream to mutate professor data members
//Parameters:
// istream &input - input containing new data member values
//Returns:
//  nothing
void Professor::Read(istream &input) {
    Person::Read(input);
    input >> _department;
    if (input.fail()){
        _department  = "";
    }
    input >> _hireDate;
    string rank;
    input >> rank;
    if (input.fail()){
        _rank = ASSISTANT_PROFESSOR;
    }
    else if(rank == "0"){
        _rank = ASSISTANT_PROFESSOR;
    }
    else if(rank == "1"){
        _rank = ASSOCIATE_PROFESSOR;
    }
    else{
        _rank = PROFESSOR;
    }
    input >> _salary;
    if (input.fail()){
        _salary  = 60000;
    }
}

//Write
//Writes professor's data members into output stream
//Parameters:
//  ostream &output - output to read data members into
//Returns:
//  nothing
void Professor::Write(ostream &output) const {
    Person::Write(output);
    output << " " << _department << " " << _hireDate << " " << _rank << " " << _salary;
}

//Raise
//Increases professor's salary by given percentage
//Parameters:
//  float percentage - percentage by which to raise professor's salary
//Returns:
//  nothing
void Professor::Raise(float percentage) {
    _salary += _salary * (percentage * 0.01);
}

//Promote
//Promotes professor to next rank
//Parameters:
//  none
//Returns:
//  nothing
void Professor::Promote() {
    if(_rank == ASSISTANT_PROFESSOR){
        _rank = ASSOCIATE_PROFESSOR;
    }
    else if(_rank == ASSOCIATE_PROFESSOR){
        _rank = PROFESSOR;
    }
    else{
        return;
    }
}

//GetRank
//get professor's rank
//Parameters:
//  none
//Returns:
//  Rank - professor's rank
Rank Professor::GetRank() const {
    return _rank;
}

//GetSalary
//get professor's salary
//Parameters:
//  none
//Returns:
//  float - professor's salary
float Professor::GetSalary() const {
    return _salary;
}
