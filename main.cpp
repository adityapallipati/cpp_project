//
//  main.cpp
//  C867_AdityaPallipati
//
//  Created by Aditya Pallipati on 4/12/22.
//

#include "roster.h"

int main()
{
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Aditya,Pallipati,apallip@my.wgu.edu,23,18,20,24,SOFTWARE"
    };

    const int numStudents = 5;
    Roster classRoster;

    /*print out course, programming lang, wgu id, and name*/
    cout << "Scripting and Programming - Applications - C867, C++, #001532178, Aditya Pallipati\n" << std::endl;
    
    /*print all students*/
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    cout << std::endl;
    
    /*print invalid emails*/
    cout << "Displaying students by invalid emails: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    /*print average days to complete course*/
    cout << "Displaying average days to complete course: " << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << std::endl;
    
    /*print by degree program SOFTWARE*/
    cout << "Displaying students by degree program: " << degreeProgramStrings[SOFTWARE] << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    /*remove student with ID A3*/
    cout << "Removing student with ID A3:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    /*remove student with ID A3 to display not found message*/
    cout << "Removing student with ID A3:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    
    return 0;
}
