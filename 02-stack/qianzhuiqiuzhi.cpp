#include <iostream>
#include <stack>
#include <string>
using namespace std;

int qianzhuiqiuzhi(string s)
{
    stack<char> st;
    for (int i=s.size()-1;i>=0;i--)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i]-'0');
        }else
        {
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if (s[i]=='+') st.push(a+b);
            else if (s[i]=='-') st.push(a-b);
            else if (s[i]=='*') st.push(a*b);
            else if (s[i]=='/') st.push(a/b);
        }
        return st.top();
    }
}
