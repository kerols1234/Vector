#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <FCIvector.h>
#include <course.h>
using namespace std;

class student
{
    public:
        student();
        void printinfo();
        friend istream& operator >>(istream &in, student& s);
        friend ostream& operator <<(ostream &out, student& s);
    protected:

    private:
        string sname,sDepartment;
        int sID;
        FCIvector<course> vec_course;
};

#endif // STUDENT_H

