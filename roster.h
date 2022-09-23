//
//  roster.h
//  C867_AdityaPallipati
//
//  Created by Aditya Pallipati on 4/12/22.
//

#pragma once
#include "student.h"
class Roster
{
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    
public:
    void parse(string row);
    void add(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        double daysInCourse1,
        double daysInCourse2,
        double daysInCourse3,
        DegreeProgram degreeprogram);
    void printAll(); /*calls print method*/
    void printByDegreeProgram(DegreeProgram degreeprogram);/*prints by degree program*/
    void printInvalidEmails();/*prints invalid emails*/
    void printAverageDaysInCourse(string studentID);/*prints average days in course*/
    void remove(string studentID);/*removes student by id*/
    ~Roster();
};
