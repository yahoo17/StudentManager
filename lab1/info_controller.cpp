#include "info_controller.h"
info_controller * info_controller::m_instance = NULL;

void info_controller::print_all() const
{
    ifstream file("data.txt",ios::in);
    string buffer;
    while (getline(file, buffer))
    {
        cout << buffer<<'\n';
    }
}
void info_controller::print_STATS() const
{
   /* fstream file("data.txt",ios::in);
    string buffer;
    while (getline(file, buffer))
    {
        int count = 0;
        int i;
        for (i = 0; i < buffer.size(); )
        {
            if (buffer[i] != '#')
                i++;
            else
            {
                count++;
                if (count == 4)
                    break;
            }
        }
        i++;
        string grade("");
        string maleOrfemale("");
        for (; i < buffer.size(); i++)
        {
            if (buffer[i] != '#')
                grade+= buffer[i];
            else
                break;
        }
        i++;
        for (; i < buffer.size(); i++)
            maleOrfemale +=buffer[i];
        cout << grade << " " << maleOrfemale << endl;
        
    }*/
    cout << "总人数有" << totalCount << "人" << ",其中男生" << boyCount<<"人,女生" <<girlCount<< "人" << endl;
    cout << "全班的平均分是" <<avgGrade ;
}
int info_controller::add_record(string id, string className, string name,  string phoneNumber, string grade,string maleOrfemale)
{
    ofstream dataFile;
    dataFile.open("data.txt", ios::out|ios::app);
    dataFile <<id<<'#'<< className << '#' << name  << '#' << phoneNumber << '#' << grade << '#'<<maleOrfemale<<endl;
    dataFile.close();
    if (maleOrfemale == "男")
        boyCount++;
    else
        girlCount++;
    totalCount++;
    totalGrade += stoi(grade);
    avgGrade = totalGrade / totalCount;
    return 1;

}
string info_controller::find_record(string id)
{
    fstream file("data.txt");
    string buffer;
    while (getline(file, buffer))
    {
        string temp("");
        int i = 0;
        while (buffer[i]!='#')
        {
            temp+= buffer[i];
            i++;
        }
        if (temp == id)
            return buffer;
    }
    return "";
}
bool info_controller::del_record(string id)
{
    
    fstream file("data.txt");
    string buffer;
    vector<string> fileVec;
    while (getline(file, buffer))
    {
        string::size_type idx;
        idx = buffer.find(id);//在a中查找b.
        if (idx == string::npos)//不存在
            fileVec.push_back(buffer);
        else
            ;
       
    }
    file.close();
    fstream file2("data.txt",ios::trunc|ios::out);
    for (auto x : fileVec)
    {
        file2 << x;
        file2 << endl;
    }
    file2.close();
    return false;
    
}
info_controller::info_controller(int a)
{
    boyCount=0;
    girlCount=0;
    totalCount=0;
    totalGrade=0;
    avgGrade=0;
}
info_controller* info_controller::getInstance()
{
    if (m_instance == NULL)
    {
        m_instance = new info_controller(1);
    }

    else
    {
        return m_instance;
    }

}
int info_controller::add_record(student_info& stu)
{
    ofstream dataFile;
    dataFile.open("data.txt", ios::out | ios::app);
    dataFile << stu.id << '#' << stu.className << '#' << stu.name << '#' << stu.phoneNumber << '#' << stu.grade << stu.maleOrfemale << '#' << endl;
    if (stu.maleOrfemale == "男")
        boyCount++;
    else
        girlCount++;
    totalCount++;
    totalGrade += stoi(stu.grade);
    avgGrade = totalGrade / totalCount;
    return 1;

}