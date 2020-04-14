#include <iostream>
#include <exception>
#include <FCIvector.h>
#include <EXP.h>
#include <student.h>
#include <course.h>
using namespace std;
template<class t>
void operation(FCIvector<t> &vec)
{
    int x;
    string z="y";
    do{
        cout<<"What kind of operation would you like to perform?"<<endl;
        cout<<"1. Add element."<<endl;
        cout<<"2. Remove last element."<<endl;
        cout<<"3. Insert element at certain position."<<endl;
        cout<<"4. Erase element from a certain position."<<endl;
        cout<<"5. Clear."<<endl;
        cout<<"6. Display first element."<<endl;
        cout<<"7. Display last element."<<endl;
        cout<<"8. Display element at certain position."<<endl;
        cout<<"9. Display vector size."<<endl;
        cout<<"10. Display vector capacity."<<endl;
        cout<<"11. Is empty?"<<endl;
        cin>>x;
        if(x==1)
        {
            t vec1;
            cout<<"Enter the element"<<endl;
            cin >> vec1;
            vec.Push_back(vec1);
        }
        else if(x==2)
        {
            vec.Pop_back();
        }
        else if(x==3)
        {
            cout<<"Enter the position"<<endl;
            cin>>x;
            t vec1;
            cout<<"Enter the element"<<endl;
            cin>>vec1;
            vec.Insert(vec.Begin()+x-1,vec1);
        }
        else if(x==4)
        {
            cout<<"Enter the position"<<endl;
            cin>>x;
            vec.Erase(vec.Begin()+x-1);
        }
        else if(x==5)
        {
            vec.Clear();
        }
        else if(x==6)
        {
            cout<<vec.Front()<<endl;
        }
        else if(x==7)
        {
            cout<<vec.Back()<<endl;
        }
        else if(x==8)
        {
            cout<<"Enter the position"<<endl;
            cin>>x;
            cout<<vec[x-1]<<endl;
        }
        else if(x==9)
        {
            cout<<vec.Size()<<endl;
        }
        else if(x==10)
        {
            cout<<vec.Capacity()<<endl;
        }
        else if(x==11)
        {
           cout<<vec.Empty()<<endl;
        }
        else
        {
            cout<<"Invalid input"<<endl;
            operation(vec);
        }
        while(true)
        {
            cout<<"Would you like to perform other operations? (Y/N)"<<endl;
            cin>>z;
            if(z=="Y"||z=="N"||z=="n"||z=="y")
                break;
            cout<<"invalid input"<<endl;
        }
    }while(z=="Y"||z=="y");
}
ostream& operator <<(ostream &out,const course& c)
{
    out<<"the course name : "<<c.courseName<<endl;
    out<<"the course code : "<<c.courseCode<<endl;
    out<<"the course grade : "<<c.courseGrade<<endl;
    out<<"the course point : "<<c.coursePoint<<endl;
    out<<"the course year : "<<c.courseYear<<endl;
    out<<"the course semester : "<<c.courseSemester<<endl;
    return out;
}
ostream& operator <<(ostream &out, student& s)
{
    out<<"the student name : "<<s.sname<<endl;
    out<<"the student department : "<<s.sDepartment<<endl;
    out<<"the student id : "<<s.sID<<endl<<endl;
    for(int i=0;i<s.vec_course.Size();i++)
    {
        out<<"course number : "<<i+1<<endl;
        out<<s.vec_course[i]<<endl;
    }
    return out;
}
istream& operator >>(istream &in, student& s)
{
    int x;
    cout<<"Enter the student name : ";
    cin.ignore();
    getline(in, s.sname);
    cout<<endl;
    cout<<"Enter the student department : ";
    in>>s.sDepartment;
    cout<<endl;
    cout<<"Enter the student id : ";
    in>>s.sID;
    cout<<endl;
    while(true)
    {
        cout<<"Enter the number of courses : ";
        in>>x;
        cout<<endl;
        if(x<1)
        {
            cout<<"you must enter course"<<endl;
        }
        else
        {
            course c;
            for(int i=0;i<x;i++)
            {
                cout<<"set information of course : "<<i+1<<endl;
                cin>>c;
                s.vec_course.Push_back(c);
           }

            break;
        }
    }
    return in;
}
istream& operator >>(istream &iin, course& c1)
{
    cout<<"Enter the course name : ";
    cin.ignore();
    getline(iin, c1.courseName);
    cout<<endl;
    cout<<"Enter the course code : ";
    iin>>c1.courseCode;
    cout<<endl;
    cout<<"Enter the course grade : ";
    iin>>c1.courseGrade;
    cout<<endl;
    cout<<"Enter the course point : ";
    iin>>c1.coursePoint;
    cout<<endl;
    cout<<"Enter the course year : ";
    iin>>c1.courseYear;
    cout<<endl;
    cout<<"Enter the course semester : ";
    iin>>c1.courseSemester;
    cout<<endl;
    return iin;
}
int main()
{
    try{
        int x;
        while(true)
        {
            cout<<"Insert type of vector you would like to create:"<<endl;
            cout<<"1. list of integer"<<endl;
            cout<<"2. list of character" <<endl;
            cout<<"3. list of string"<<endl;
            cout<<"4. list of float"<<endl;
            cout<<"5. list of students"<<endl;
            cout<<"6. Exit"<<endl;
            cin>>x;
            if(x==1)
            {
                FCIvector<int> obj;
                cout<<"A vector of integer was created successfully."<<endl;
                operation(obj);
            }
            else if(x==2)
            {
                FCIvector<char> obj;
                cout<<"A vector of character was created successfully."<<endl;
                operation(obj);
            }
            else if(x==3)
            {
                FCIvector<string> obj;
                cout<<"A vector of string was created successfully."<<endl;
                operation(obj);
            }
            else if(x==4)
            {
                FCIvector<float> obj;
                cout<<"A vector of float was created successfully."<<endl;
                operation(obj);
            }
            else if(x==5)
            {
                FCIvector<student> obj;
                cout<<"A vector of students was created successfully."<<endl;
                operation(obj);
            }
            else if(x==6)
            {
                break;
            }
            else
            {
                cout<<"Invalid input"<<endl;
            }
        }
    }
    catch(outofrange e)
    {
        cout<<e.what()<<endl;
    }
    catch(emptyy e)
    {
        cout<<e.what()<<endl;
    }
    return 0;
}
