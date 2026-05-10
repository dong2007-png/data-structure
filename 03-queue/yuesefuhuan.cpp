#include <iostream>
#include <queue>
using namespace std;

void yuesefuhuan(int n,int m)
{
    queue<int> q;
    for (int i=1;i<n;i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        for (int i=1;i<m;i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        q.pop();
    }
}