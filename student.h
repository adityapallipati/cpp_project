//
//  student.h
//  C867_AdityaPallipati
//
//  Created by Aditya Pallipati on 4/12/22.
//

#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;


class Student
    {
    public:
        const static int daysToCompleteArray = 3;
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        double days[daysToCompleteArray];
        DegreeProgram degreeProgram;
    public:
        Student();/*sets default values*/
        Student(string studentId, string firstName, string lastName,
        string emailAddress,int age, double days[], DegreeProgram degreeProgram);/*full constructor*/
        ~Student();/*destructor*/
        
        /*getters - accessor*/
        string getID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        double* getDays();
        DegreeProgram getDegreeProgram();

        /*setters - mutator*/
        void setID(string ID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDays(double days[]);
        void setDegreeProgram(DegreeProgram degreeprogram);

        static void printHeader();/*header for data*/

        void print();/*prints this student's data*/
    };
