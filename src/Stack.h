#include <iostream>
using namespace std;


class StackNode
{
public:
    int data;
    StackNode *next;
    StackNode(int da)
    {
        data = da;
        next = nullptr;
    }
};


class Stack
{
    private:
        StackNode *node;
    public:
    
    Stack(){node = nullptr;}
    bool isEmpty()
    {
        if(node == nullptr)
        {
            return true;
        }
        return false;
    }

    StackNode* begin()
    {
        return node;
    }

    StackNode*  end()
    {
        return nullptr;
    }
    
    void push(int var)
    {
        StackNode* newNode = new StackNode(var);
        newNode->next = node;
        node = newNode;
    }
    
    void pop()
    {
        if(isEmpty() != 1){
            StackNode * temp = node;
            node = node->next;
            delete temp;
        }
        else 
        {
            cout<<"Pop Empty !!"<<endl;
        }
    }
    
    void top()
    {
        if(isEmpty() != 1)
        {
            cout<<node->data<<endl;
        }
        else
        {
            cout<<"Top Empty !!"<<endl;
        }
    }
    
    void clearStack()
    {
        while(isEmpty() != 1)
        {
            pop();
        }
    }
    
    int returnSize()
    {
        StackNode *beginPtr = begin();
        StackNode *endPtr = end();
        int counter = 0; 
        while(beginPtr != endPtr)
        {
            beginPtr = beginPtr->next;
            counter++;
        }
        return counter;
    }
};
