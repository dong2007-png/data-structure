#include <iostream>
using namespace std;
class queue
{
private:
    int size;
    int front, rear;
    char *data;
public:
    queue()
    {
        size=100;
        front=rear=0;
        data=new char[size];
    }
    queue(int s)
    {
        size=s;
        front=rear=0;
        data=new char[size];
    }
    ~queue()
    {
        delete[] data;
    }
    bool empty()
    {
        return front==rear;
    }
    bool full()
    {
        return front==(rear+1)%size;
    }
    void enqueue(char c)
    {
        if (full())
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        data[rear]=c;
        rear=(rear+1)%size;
        return ;
    }
    char dequeue()
    {
        if (empty())
        {
            cout<<"Queue is empty"<<endl;
            return '\0';
        }else
        {
            char c=data[front];
            front=(front+1)%size;
            return c;
        }
    }
    void display()
    {
        if (empty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }else
        {
            for (int i=front;i!=rear;i=(i+1)%size)
            {
                cout<<data[i]<<" ";
            }
        }
        return ;
    }
    char getfront()
    {
        if (empty())
        {
            cout<<"Queue is empty"<<endl;
            return '\0';
        }else{
            return data[front];
        }
    }

};