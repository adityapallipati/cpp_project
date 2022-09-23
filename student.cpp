//
//  student.cpp
//  C867_AdityaPallipati
//
//  Created by Aditya Pallipati on 4/12/22.
//

#include "student.h"
Student::Student()/*parameterless constructor - default values*/
{
    this->studentID = "";/*empty string*/
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;/*int set to 0*/
    for (int i = 0; i < daysToCompleteArray; i++) this->days[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double days[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysToCompleteArray; i++) this->days[i] = days[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {}/*destructor*/

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() {return this->age; }
double* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) {this->emailAddress = emailAddress; }
void Student::setAge(int age) {this->age = age; }
void Student::setDays(double days[])
{
    for (int i = 0; i < daysToCompleteArray; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeProgram = degreeprogram; }


void Student::print()
{
    cout << this->getID() << '\t';
    cout << "First Name: ";
    cout << this->getFirstName() << '\t';
    cout << "Last Name: ";
    cout << this->getLastName() << '\t';
    cout << "Age: ";
    cout << this->getAge() << '\t';
    cout << "daysInCourse: {";
    cout << this->getDays()[0] << ',';
    cout << " ";
    cout << this->getDays()[1] << ',';
    cout << " ";
    cout << this->getDays()[2] << '}';
    cout << " Degree Program: ";
    cout << degreeProgramStrings[this->getDegreeProgram()] << std::endl;
}


