#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;
// solution 봄
int main()
{
    string s;
    stack<char> st;
    cin >> s;
    int rst = 0;
    int tmp = 1;
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
            tmp *= 2;
        }
        else if (s[i] == '[')
        {
            st.push('[');
            tmp *= 3;
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                flag = true;
                break;
            }
            if (st.top() == '(')
            {
                if (s[i - 1] == '(')
                    rst += tmp;
                st.pop();
                tmp /= 2;
            }
            else
            {
                flag = true;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (st.empty())
            {
                flag = true;
                break;
            }
            if (st.top() == '[')
            {
                if (s[i - 1] == '[')
                {
                    rst += tmp;
                }
                st.pop();
                tmp /= 3;
            }
            else
            {
                flag = true;
                break;
            }
        }
    }
    if (flag || !st.empty())
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << rst << '\n';
    }
}
