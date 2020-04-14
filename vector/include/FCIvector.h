#ifndef FCIVECTOR_H
#define FCIVECTOR_H
#include <algorithm>
#include <exception>
#include<EXP.h>
#include<iostream>
using namespace std;
template <class t>
class FCIvector
{
    public:
        FCIvector()
        {
        capacity=0;
        numberOfElements=0;
        elements=nullptr;
        };
        FCIvector(int num)
        {
        capacity=num;
        numberOfElements=0;
        elements = new t[numberOfElements];
        };
        int Size()
        {
          return numberOfElements;
        };
        int Capacity()
        {
            return capacity;
        };
        bool Empty()
        {
            return numberOfElements==0;
        };
        void Push_back(t val )
        {
            if(numberOfElements==capacity)
            {
                capacity*=2;
                if(capacity==0)
                    capacity=1;
                t * ele = new t[capacity];
                for(int i=0;i<numberOfElements;i++)
                {
                    ele[i] = elements[i];
                }
                 if(numberOfElements!=0)
                    delete[] elements;
                elements=ele;
            }
            elements[numberOfElements]=val;
            numberOfElements++;
        };
        t& operator[](int index)
        {
            if(index<0||index>=numberOfElements)
            {
                outofrange out;
                throw out;
            }
            return elements[index];
        };
        t* Begin()
        {
            if(numberOfElements==0)
            {
                emptyy em;
                throw em;
            }
            return elements ;
        };
        t* End()
        {
            if(numberOfElements==0)
            {
                emptyy em;
                throw em;
            }
            return elements+(numberOfElements-1) ;
        };
        t& Front()
        {
            if(numberOfElements==0)
            {
                emptyy em;
                throw em;
            }
            return elements[0] ;
        };
        t& Back()
        {
            if(numberOfElements==0)
            {
                emptyy em;
                throw em;
            }
            return elements[numberOfElements-1] ;
        };
        void Insert(t* position,t val)
        {
            if(position-elements<0||position-elements>=numberOfElements)
            {
                emptyy em;
                throw em;
            }
            else if(numberOfElements==capacity)
            {
                capacity*=2;
                if(capacity==0)
                    capacity=1;
                t* ele = new t[capacity];
                for(int i=0,j=0;i<numberOfElements;i++,j++)
                {
                    if(ele+i==position)
                    {
                        ele[j] = val;
                        j++;
                    }
                    ele[j] = elements[i];
                }
                if(numberOfElements!=0)
                {
                    delete[] elements;
                }
                elements=ele;
            }
            else
            {
                elements[numberOfElements] = val;
                for(int i=numberOfElements;elements+i==position;i--)
                {
                    swap(elements[i-1],elements[i]);
                }
            }
            numberOfElements++;
        };
        void Pop_back()
        {
            if(numberOfElements==0)
            {
                emptyy em;
                throw em;
            }
            numberOfElements--;
        };
        void Clear()
        {
            if(capacity!=0)
            {
                numberOfElements=0;
                capacity=0;
                delete[]elements;
            }
        }
        void Erase(t* position)
        {
            if(position-elements<0||position-elements>=numberOfElements)
            {
                emptyy em;
                throw em;
            }
            for(int i=position-elements;i<numberOfElements;i++)
            {
                swap(elements[i+1],elements[i]);
            }
            numberOfElements--;
        };
        void reversee()
        {
            if(numberOfElements==0)
            {
                emptyy em;
                throw em;
            }
            else
            {
               t* n = new t[capacity];
               for(int i=0,p=numberOfElements-1;i<numberOfElements;i++,p--)
                {
                    n[i] = elements[p];
                }
                delete[] elements;
                elements=n;
            }
        }
    private:
        t * elements;
        int numberOfElements ,capacity;
};

#endif // FCIVECTOR_H
