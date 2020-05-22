
#include <fstream>
#include <iostream>
#include <vector>
#include "datastructure.h"
using namespace std;

class info_controller
{
public:

    static info_controller* getInstance();
    int add_record(student_info& stu);
    int add_record(string  id, string className,string name, string phoneNumber, string grade,string maleOrfemale);
    string find_record(string  id);
    bool del_record(string id);
    void print_all()const;
    void print_STATS()const;

private:
    explicit info_controller(int a);
    static info_controller* m_instance;
public:
    int boyCount;
    int girlCount;
    int totalCount;
    double totalGrade;
    double avgGrade;
    
};

