// lab1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include "info_controller.h"
using namespace std;

int main()
{
   
    
        cout << endl;
        cout << "                 " << "Welcome to学生信息管理系统(Students Management System)" << endl << endl;
        while (true)
        {
            cout << " 请输入功能的编号" << endl;
            cout << "1.增加学生信息" << endl;
            cout << "2.查询学生信息" << endl;
            cout << "3.打印所有学生信息" << endl;
            cout << "4.删除记录" << endl;
            cout << "5.统计学生信息" << endl;
            cout << "6.输入6然后按回车退出程序" << endl;
            
            int functionNumber;
            cin >> functionNumber;
            switch (functionNumber)
            {

            
            case 1:
            {
                cout << endl;
                string b, c, f;
                long long a;
                long long d;
                int e;
                cout << "请输入学号,班级,姓名,手机号,成绩,性别(性别输入男或女)\n";
                while (!(cin >> a >> b >> c >> d >> e >> f).eof())
                {
                    if (cin.fail()) {
                        cout << "Invaild input." << endl;
                        cin.clear();
                        //忽略这一行后面的数据
                        cin.ignore(100, '\n');
                    }
                    else
                    {
                        info_controller::getInstance()->add_record(to_string(a), b, c, to_string(d), to_string(e), f);
                        cout << endl;
                        break;
                    }
                }
                
                
                /*while (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "输入错误，请重新输入" << endl;
                    cin >> a >> b >> c >> d >> e >> f;
                }*/
               
                break;
            }

            case 2:
            {
                cout << endl;
                string id;
                cin >> id;
                cout << endl;
                cout<< info_controller::getInstance()->find_record(id);
                cout << endl;
                break;
            }
            case 3:
            {
                cout << endl;
                info_controller::getInstance()->print_all();
                cout << endl;
                break;
            }
            case 4:
            {
                cout << endl;
                string id;
                cin >> id;
                info_controller::getInstance()->del_record(id);
                cout << endl;
                break;
            }
            case 5:

            {
                cout << endl;
                info_controller::getInstance()->print_STATS();
                cout << endl;
                break;

            }
            case 6:
            {
                return 0;
                break;
            } 
            default:
            {
                break;
            }

            }
            
        }


}

