#include "student.h"
#include <string>
#include <iostream>
using namespace std;
student::student()
{

}
void student::printinfo()
{
    cout<<"the student name : "<<sname<<endl;
    cout<<"the student department : "<<sDepartment<<endl;
    cout<<"the student id : "<<sID<<endl;
    if(vec_course.Size()==0)
        cout<<"you do not have any course you must enter one"<<endl;
    else
    {
        for(int i=0;i<vec_course.Size();i++)
        {
            cout<<"course number : "<<i+1<<endl;
            vec_course[i].printCourseInfo();
        }
    }
}

