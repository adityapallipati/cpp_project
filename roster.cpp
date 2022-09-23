//
//  roster.cpp
//  C867_AdityaPallipati
//
//  Created by Aditya Pallipati on 4/12/22.
//

#include "roster.h"
void Roster::parse(string row)
{
    DegreeProgram degreeprogram = SECURITY;
    if (row.back() == 'E') degreeprogram = SOFTWARE;
    else if (row.back() == 'K') degreeprogram = NETWORK;

    int rhs = row.find(",");
    string sID = row.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string fN = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string lN = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string eA = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    double dC1 = stod(row.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    double dC2 = stod(row.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    double dC3 = stod(row.substr(lhs, rhs - lhs));


    add(sID, fN, lN, eA, age, dC1, dC2, dC3, degreeprogram);
    
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram degreeprogram )
{
    double days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);

}

/* this has been updated for submission two - calls print()*/
void Roster::printAll()
{
    
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        classRosterArray[i]->print();
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
    }
    cout << std::endl;
}

/*email must contain @ and . with no spaces*/

void Roster::printInvalidEmails() {
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string invalidEmail = (classRosterArray[i]->getEmailAddress());
        if ((invalidEmail.find(' ') != string::npos) || (invalidEmail.find('@') == string::npos || invalidEmail.find('.') == string::npos)) {

            any = true;
            cout << classRosterArray[i]->getID() << ": " << classRosterArray[i]->getEmailAddress() << std::endl;
        }
    }
    if (!any) cout << "All emails are valid!" << std::endl;

}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i<= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID()==studentID)
        {
        cout << studentID << ": ";
        cout << (classRosterArray[i]->getDays()[0]
        + classRosterArray[i]->getDays()[1]
        + classRosterArray[i]->getDays()[2])/3.0 << std::endl;
        }
    }
}

void Roster::remove(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if(classRosterArray[i]->getID() == studentID)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " removed student from roster." << std::endl << std::endl;
        this->printAll();
    }
    else cout << studentID << " student with this ID was not found." << std::endl << std::endl;
}

Roster::~Roster()
{
    cout << "DESTRUCTOR HAS BEEN CALLED!" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destroying Student: " << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

