#include <iostream>
using namespace std;
class stack
{
private:
    int size;
    int top;
    char *data;
public:
    stack()
    {
        size=100;
        top=-1;
        data=new char[size];
    }
    stack(int s)
    {
        size=s;
        top=-1;
        data=new char[size];
    }
    ~stack()
    {
        delete [] data;
    }
    bool isempty()
    {
        return (top==-1);
    }
    bool isfull()
    {
        return (top+1==size);
    }
    void push(char x)
    {
        if (isfull())
        {
            cout<<"Stack Overflow"<<endl;
            return ;
        }
        data[++top]=x;
        return ;
    }
    char pop()
    {
        if (isempty())
        {
            cout<<"Stack Underflow"<<endl;
            return '\0';
        }
        return data[top--];
    }
    void display()
    {
        if (isempty())
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }else
        {
            for (int i=top;i>=0;i--)
            {
                cout<<data[i]<<" ";
            }
        }
        return ;
    }
    char gettop()
    {
        if (isempty())
        {
            cout<<"Stack Underflow"<<endl;
            return '\0';
        }
        return data[top];
    }

};
