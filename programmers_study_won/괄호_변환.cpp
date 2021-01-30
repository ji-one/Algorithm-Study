#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int isCorrect(string p)
{
    stack<char> st;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            st.push(p[i]);
        }
        else
        {
            if (!st.empty())
                st.pop();
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
string makeCorrect(string p)
{
    /* 1단계 */
    if (p == "")
        return "";
    if (isCorrect(p))
        return p;

    int cnt1 = 0; // ( 개수
    int cnt2 = 0; // ) 개수
    string u = "";
    string v = "";

    /* 2단계 */
    if (!isCorrect(p))
    {
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == '(')
                ++cnt1;
            if (p[i] == ')')
                ++cnt2;

            if (cnt1 == cnt2)
            {
                u = p.substr(0, i + 1);
                v = p.substr(i + 1, p.length() - i - 1);
                break;
            }
        }
    }

    /* 3단계 */
    if (isCorrect(u))
    {
        string tmp = u + makeCorrect(v);
        return tmp;
    }
    else
    { /* 4단계*/
        string tmp = "";
        tmp += "(";
        tmp += makeCorrect(v);
        tmp += ")";
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.length(); i++)
        {
            if (u[i] == ')')
                tmp += "(";
            if (u[i] == '(')
                tmp += ")";
        }
        return tmp;
    }
}
string solution(string p)
{
    string answer = "";
    answer = makeCorrect(p);
    return answer;
}