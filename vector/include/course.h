#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;

class course
{
    public:
        course();
        friend istream& operator >>(istream &in, course& c1);
        friend ostream& operator <<(ostream &out,const course& c);
        void printCourseInfo();
    protected:

    private:
        string courseName,courseCode;
        char courseGrade;
        float coursePoint;
        int courseYear,courseSemester;
};

#endif // COURSE_H
