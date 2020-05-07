/*
 * Title:		Inheritance Lab 2
 * Purpose:		Construct vectors of Person/Person subclass objects to practice inheritance concepts
 * Author:		Andrew McLain
 * Date:		05/01/2020
 */

#include "date.h"
#include "student.h"

//Student constructor
//Parameters:
//  const string &name - name of student
//  const Date &birthday - birth date of student
//Returns:
//  nothing
Student::Student(const string &name, const Date &birthday) : Person(name, birthday), _major(" "),
                                                             _credits(0), _gpa(0.0)
{

}

//Student constructor
//Parameters:
//  const string &name - name of student
//  const Date &birthday - birth date of student
//  const string &major - major of student
//Returns:
//  nothing
Student::Student(const string &name, const Date &birthday, const string &major) : Person(name, birthday),
                                                                                  _major(major), _credits(0),
                                                                                  _gpa(0.0)
{

}

//Student destructor
//Parameters:
//  none
//Returns:
//  nothing
Student::~Student() {

}

//ToString
//returns string of student information
//Parameters:
//  none
//Returns:
//  string - student's information
string Student::ToString() const {
    std::stringstream ss;
    ss << "{Person: " << Person::ToString() << ", major: " << _major << ", gpa: " << _gpa << ", credits: "
       << _credits << "}";
    return ss.str();
}

//Read
//Reads information from input stream to mutate student data members
//Parameters:
// istream &input - input containing new data member values
//Returns:
//  nothing
void Student::Read(istream &input) {
    Person::Read(input);
    input >> _major;
    if (input.fail()){
        _major  = "";
    }
    input >> _credits;
    if (input.fail()){
        _credits = 0.0;
    }
    input >> _gpa;
    if (input.fail()){
        _gpa = 0.0;
    }
}

//Write
//Writes student's data members into output stream
//Parameters:
//  ostream &output - output to read data members into
//Returns:
//  nothing
void Student::Write(ostream &output) const {
    Person::Write(output);
    output << " " << _major << " " << _credits << " " << _gpa;
}

//AddGrade
//add a grade/credit amount for a course taken by the student
//Parameters:
//  float grade - grade earned by student
//  size_t credits - credits for the course
//Returns:
//  nothing
void Student::AddGrade(float grade, size_t credits) {
    float totalPts = (_gpa * _credits) + (grade * credits);
    _credits += credits;
    _gpa = totalPts / _credits;
}

//GetGPA
//returns GPA of the student
//Parameters:
//  none
//Returns:
//  float - student gpa
float Student::GetGPA() const {
    return _gpa;
}

//GetGPA
//returns number of credits taken by the student
//Parameters:
//  none
//Returns:
//  size_t - credits taken by the student
size_t Student::GetCredits() const {
    return _credits;
}
