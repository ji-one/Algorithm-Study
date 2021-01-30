#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        vector<char> v;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                v.push_back(s[i]);
            }
            else if (!v.empty() && s[i] == ')')
            {
                v.pop_back();
            }
            else
            {
                flag = false;
                break;
            }
        }

        (v.empty() && flag) ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}