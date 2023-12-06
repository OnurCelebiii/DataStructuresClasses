#include <iostream>
using namespace std;


class Stack
{
    private:
        static const int maxSize = 100; 
        int arry[maxSize];
        int topIndex;
    public:
        Stack()
        {
            topIndex = -1;
        }

        int topIndexReturn(){return topIndex;}

        bool isFull()
        {
            return topIndex == maxSize - 1;
        }

        void push(int var)
        {
            if(isFull() != 1)
            {
                topIndex++;
                arry[topIndex] = var;
            }
            else{
                cout<<"arr full";
            }
        }

        void pop()
        {
            if(isFull() != 1 && topIndex != -1)
            {
                arry[topIndex] = 0 ;
                topIndex --;
            }
            else
            {
                cout<<"Arr Full or empty";
            }
        }

        void top()
        {
            if(isFull() != 1 && topIndex != -1)
            {
                cout<<arry[topIndex]<<endl;
            }
                        else
            {
                cout<<"Arr Full or empty";
            }
        }

};
