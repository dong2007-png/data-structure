#include <iostream>
using namespace std;
struct node
{
    char data;
    node* next;
};
class linkqueue
{
private:
    node* head;
    public:
    linkqueue()
    {
        head = NULL;
    }
    ~linkqueue()
    {
        while (head != NULL)
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
