#include "course.h"
#include <string>
using namespace std;
course::course()
{
}
void course::printCourseInfo()
{
    cout<<"the course name : "<<courseName<<endl;
    cout<<"the course code : "<<courseCode<<endl;
    cout<<"the course grade : "<<courseGrade<<endl;
    cout<<"the course point : "<<coursePoint<<endl;
    cout<<"the course year : "<<courseYear<<endl;
    cout<<"the course semester : "<<courseSemester<<endl;
}
