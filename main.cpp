#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"


#include <iostream>
#include <vector>
#include <fstream>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

size_t Menu();

int main(int argc, char* argv[]) {
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15){
		if (userOption == 1){			// Add Person
            //declare variables
		    string name;
		    size_t year, month, day;
            //assign variables from user input
            cout << "Name: ";
            cin >> name;
            cout << "Birth date yyyy mm dd: ";
            cin >> year;
            cin >> month;
            cin >> day;
            //Construct date object
            Date date(year, month, day);
            //if date is invalid, prompt user until valid date entered
            while(date.IsInvalidDate()){
                cerr << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> year;
                cin >> month;
                cin >> day;
                date = Date(year, month, day);
            }
            //add person object to people vector and print confirmation message
            people.push_back(new Person(name, date));
            cout << "Person inserted in position: " << people.size() - 1 << endl << endl;

		}else if (userOption == 2){		// Add Student
            //declare variables
            string name, major;
            size_t year, month, day;
            //assign variables from user input
            cout << "Name: ";
            cin >> name;
            cout << "Birth date yyyy mm dd: ";
            cin >> year;
            cin >> month;
            cin >> day;
            //construct date object
            Date date(year, month, day);
            //if date is invalid, prompt user until valid date entered
            while(date.IsInvalidDate()){
                cerr << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> year;
                cin >> month;
                cin >> day;
                date = Date(year, month, day);
            }

            cout << "Major: ";
            cin >> major;
            //add student object to people vector and print confirmation message
            people.push_back(new Student(name, date, major));
            cout << "Student inserted in position: " << people.size() - 1 << endl << endl;

		}else if (userOption == 3){		// Add Professor
            //declare variables
            string name, department;
            size_t year, month, day, hireYear, hireMonth, hireDay;
            //assign variables from user input
            cout << "Name: ";
            cin >> name;
            cout << "Birth date yyyy mm dd: ";
            cin >> year;
            cin >> month;
            cin >> day;
            //construct date object
            Date date(year, month, day);
            //if date is invalid, prompt user until valid date entered
            while(date.IsInvalidDate()){
                cerr << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> year;
                cin >> month;
                cin >> day;
                date = Date(year, month, day);
            }
            //assign variables from user input
            cout << "Department: ";
            cin >> department;
            cout << "Hire date yyyy mm dd: ";
            cin >> hireYear;
            cin >> hireMonth;
            cin >> hireDay;
            //Construct hireDate object
            Date hireDate(hireYear, hireMonth, hireDay);

            while(date.IsInvalidDate()){
                cerr << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> year;
                cin >> month;
                cin >> day;
                hireDate = Date(year, month, day);
            }
            //add professor object to people vector and print confirmation message
            people.push_back(new Professor(name, date, department,
                             hireDate));
            cout << "Professor inserted in position: " << people.size() - 1 << endl << endl;

		}else if (userOption == 4){		// List All People

            for(Person* person : people){
                cout << person->ToString() << endl;
            }

		}else if (userOption == 5){		// Show Students Report

            for(Person* person : people){
                if(dynamic_cast<Student*>(person) != nullptr){
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 6){		// Show Professor Report

            for(Person* person : people){
                if(dynamic_cast<Professor*>(person) != nullptr){
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 7){		// Show !Professor !Student

            for(Person* person : people){
                if(dynamic_cast<Student*>(person) == nullptr && dynamic_cast<Professor*>(person) == nullptr){
                    cout << person->ToString() << endl;
                }
            }

		}else if (userOption == 8){		// Calculate Average GPA

		    float gpa = 0.0;
		    size_t numStudents = 0;

            for(Person* person : people){
                if(dynamic_cast<Student*>(person) != nullptr){
                    Student* student = dynamic_cast<Student*>(person);
                    numStudents++;
                    gpa += student->GetGPA();
                }
            }

            cout << "The average GPA of the students is: " << gpa / numStudents << endl;

		}else if (userOption == 9){		// Calculate Average Salary
            //initialize variables
            float salary = 0.0;
            size_t numProfs = 0;
            //traverse through list, iterating num of profs and adding to total salary
            for(Person* person : people){
                if(dynamic_cast<Professor*>(person) != nullptr){
                    Professor* professor = dynamic_cast<Professor*>(person);
                    numProfs++;
                    salary += professor->GetSalary();
                }
            }

            cout << "The average salary of the professors is: " << salary / numProfs << endl;

		}else if (userOption == 10){	// Input Grades to Student
            //declare variables
		    size_t index, credits;
		    float grade;
		    //list students with index in people vector so user can see valid options
            for(size_t i = 0; i < people.size(); i++){
                if(dynamic_cast<Student*>(people[i]) != nullptr){
                    cout << i << " " << people[i]->ToString() << endl;
                }
            }
            //prompt user for index
            cout << "Number of student to input grades to: ";
            cin >> index;
            //continue prompting user if invalid index is entered
            while(cin.fail() || index >= people.size() || index < 0 ||
                  dynamic_cast<Student*>(people[index]) == nullptr){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                }
                else if(index >= people.size() || index < 0){
                    cerr << "Position out of range!" << endl;
                }
                else{
                    string type;
                    if(dynamic_cast<Professor*>(people[index]) != nullptr){
                        type = "Professor";
                    }
                    else{
                        type = "Person";
                    }
                    cerr << type << " " << people[index]->ToString() << " is not a student" << endl;
                }
                cout << "Number of student to input grades to: ";
                cin >> index;
            }
            //prompt user for grade for student
            cout << "Grade of the student [0.0 to 4.0 scale]: ";
            cin >> grade;
            //continue prompting user if invalid grade entered
            while (cin.fail() || grade < 0.0 || grade > 4.0){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                }
                else{
                    cerr << "Invalid grade value, make sure [0.0, 4.0]" << endl;
                }
                cout << "Grade of the student [0.0 to 4.0 scale]: ";
                cin >> grade;
            }
            //prompt user for credits for student
            cout << "Credits {1, 2, 3, 4, 5}: ";
            cin >> credits;
            //continue prompting user if invalid credits entered
            while (cin.fail() || credits < 1 || credits > 5){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                }
                else{
                    cerr << "Invalid credits value, make sure {1, 2, 3, 4, 5}" << endl;
                }
                cout << "Credits {1, 2, 3, 4, 5}: ";
                cin >> credits;
            }
            //add grade to student at given index
            dynamic_cast<Student*>(people[index])->AddGrade(grade, credits);

        }else if (userOption == 11){	// Promote Professor
            //declare variables
		    size_t index;
		    //print valid indexes and professors so user can choose
            for(size_t i = 0; i < people.size(); i++){
                if(dynamic_cast<Professor*>(people[i]) != nullptr){
                    cout << i << " " << people[i]->ToString() << endl;
                }
            }
            //prompt user for index
            cout << "Number of professor to promote: ";
            cin >> index;
            //continue prompting user for index if invalid index entered
            while(cin.fail() || index >= people.size() || index < 0 ||
                  dynamic_cast<Professor*>(people[index]) == nullptr){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                    cin >> index;
                }
                else if(index >= people.size() || index < 0){
                    cerr << "Position out of range!" << endl;
                }
                else{
                    string type;
                    if(dynamic_cast<Student*>(people[index]) != nullptr){
                        type = "Student";
                    }
                    else{
                        type = "Person";
                    }
                    cerr << type << " " << people[index]->ToString() << " is not a professor" << endl;
                }
                cout << "Number of professor to promote: ";
                cin >> index;
            }
            //promote professor at given index
            dynamic_cast<Professor*>(people[index])->Promote();

		}else if (userOption == 12){	// Give Raise to Professor
            //declare variables
            size_t index;
            float percentage;
            //print valid indexes and professors for user to choose
            for(size_t i = 0; i < people.size(); i++){
                if(dynamic_cast<Professor*>(people[i]) != nullptr){
                    cout << i << " " << people[i]->ToString() << endl;
                }
            }
            //prompt user for professor index
            cout << "Number of professor to give raise: ";
            cin >> index;
            //continue prompting user for index if invalid index entered
            while(cin.fail() || index >= people.size() || index < 0 ||
                  dynamic_cast<Professor*>(people[index]) == nullptr){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                    cin >> index;
                }
                else if(index >= people.size() || index < 0){
                    cerr << "Position out of range!" << endl;
                }
                else{
                    string type;
                    if(dynamic_cast<Student*>(people[index]) != nullptr){
                        type = "Student";
                    }
                    else{
                        type = "Person";
                    }
                    cerr << type << " " << people[index]->ToString() << " is not a professor" << endl;
                }
                cout << "Number of professor to give raise: ";
                cin >> index;
            }
            //prompt user for raise percentage
            cout << "Raise to the professor ]0.0, 50.0] ";
            cin >> percentage;
            //continue prompting user for percentage if invalid percentage entered
            while (cin.fail() || percentage < 0.0 || percentage > 50.0){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                }
                else{
                    cerr << "Invalid raise percentage, must be [0.0, 50.0]" << endl;
                }
                cout << "Raise to the professor [0.0, 50.0] ";
                cin >> percentage;
            }
            //give raise to professor at given index
            dynamic_cast<Professor*>(people[index])->Raise(percentage);

        }else if (userOption == 13){	// Load from File
            //declare variables
            string fileName, prefix, line;
            std::ifstream fin;
            //prompt user for file name
            cout << "Input Filename: ";
            cin >> fileName;
            fin.open(fileName);
            //if file cannot be opened, leave menu option, else proceed
            if(!fin.is_open()){
                cerr << "Unable to open file " << fileName << endl;
            }
            //read file line by line
            else{
                while(getline(fin, line)){
                    //get a line
                    std::stringstream ss(line);
                    ss >> prefix;
                    //create object based on prefix from line and add to vector
                    if(prefix == "S"){
                        people.push_back(new Student("", Date(2000, 1, 1)));
                        people[people.size() - 1]->Read(ss);
                    }
                    else if(prefix == "R"){
                        people.push_back(new Professor("", Date(2000, 1, 1), ""));
                        people[people.size() - 1]->Read(ss);
                    }
                    else{
                        people.push_back(new Person("", Date(2000, 1, 1)));
                        people[people.size() - 1]->Read(ss);
                    }
                }
                fin.close();
            }

		}else if (userOption == 14){	// Write to File
            //declare variables
            string fileName;
            std::ofstream fout;
            //prompt user for filename
            cout << "Output filename: ";
            cin >> fileName;
            fout.open(fileName);
            //traverse list, adding person information to output file
            for(Person* person : people){
                std::stringstream ss;
                person->Write(ss);
                if(dynamic_cast<Student*>(person) != nullptr){
                    fout << "S ";
                }
                else if(dynamic_cast<Professor*>(person) != nullptr){
                    fout << "R ";
                }
                else{
                    fout << "P ";
                }
                fout << ss.str() << endl;
            }
            fout.close();

		}

    }
	//deallocate memory in people vector
	for(Person* person : people){
	    delete person;
	}
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}
