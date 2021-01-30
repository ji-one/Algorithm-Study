#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    string s, e;
    cin >> s >> e;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
        int idx = e.length() - 1;
        stack<char> tmp;
        while (!st.empty() && idx >= 0 && st.top() == e[idx])
        {
            --idx;
            tmp.push(st.top());
            st.pop();
        }
        if (tmp.size() != e.length())
        {
            while (!tmp.empty())
            {
                st.push(tmp.top());
                tmp.pop();
            }
        }
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    res == "" ? cout << "FRULA" : cout << res;

    return 0;
}