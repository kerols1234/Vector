#ifndef EXP_H
#define EXP_H
#include<exception>
using namespace std;

class outofrange : public exception{
public:
    virtual const char* what() const throw(){
        return "this index is out of range";
    }
};
class emptyy : public exception{
public:
    virtual const char* what() const throw(){
        return "this vector is empty";
    }
};

#endif // EXP_H
