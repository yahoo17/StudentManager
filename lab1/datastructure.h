#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <string>
using namespace std;
class student_info
{
public:
    student_info(string id, string className, string name,  string phoneNumber, string grade,string maleOrfemale) :className(className), name(name), id(id), phoneNumber(phoneNumber), grade(grade),maleOrfemale(maleOrfemale)
    {}
public:
    string id;
    string className;
    string name;  
    string phoneNumber;
    string grade;
    string maleOrfemale;

};


#endif // !DATASTRUCTURE_H

