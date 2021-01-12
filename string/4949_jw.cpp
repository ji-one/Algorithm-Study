// 균형잡힌 세상
// cin, getline 차이?
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    while (1)
    {
        string s;
        vector<char> v;
        getline(cin, s);
        if (s == ".")
            break;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                v.push_back(s[i]);
            }
            if (s[i] == ')')
            {
                if (!v.empty() && v.back() == '(')
                {
                    v.pop_back();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (s[i] == ']')
            {
                if (!v.empty() && v.back() == '[')
                {
                    v.pop_back();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (v.empty() && flag)
        {
            cout << "yes\n";
        }
        else
            cout << "no\n";
    }

    return 0;
}