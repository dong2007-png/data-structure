#include<iostream>
using namespace std;
struct node
{
    char data;
    node* next;
};
class linkstack
{
    private:
    node* first;
public:
    linkstack()
    {
        first = NULL;
    }
    ~linkstack()
    {
        node *temp;
        while (first != NULL)
        {
            temp=first;
            first=first->next;
            delete temp;
        }
    }
    void push(char x)
    {
        node *temp=new node;
        temp->data=x;
        temp->next=first;
        first=temp;
    }
    bool isempty()
    {
        return first==NULL;
    }
    char pop()
    {
        if (isempty())
        {
            cout<<"Stack is Empty";
            return '\0';
        }
        node *temp=first;
        first=first->next;
        char c=temp->data;
        delete temp;
        return c;
    }
};
