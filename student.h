/*
 * Title:		Inheritance Lab 2
 * Purpose:		Construct vectors of Person/Person subclass objects to practice inheritance concepts
 * Author:		Andrew McLain
 * Date:		05/01/2020
 */

#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H

#include "date.h"
#include "person.h"

class Student : public Person{
    string _major;
    size_t _credits;
    float _gpa;
public:
    Student(const string& name, const Date& birthday);
    Student(const string& name, const Date& birthday, const string& major);
    virtual ~Student();
    virtual string ToString()const;
    virtual void Read(istream& input);
    virtual void Write(ostream& output)const;
    void AddGrade(float grade, size_t credits);
    float GetGPA()const;
    size_t GetCredits()const;
};
#endif
