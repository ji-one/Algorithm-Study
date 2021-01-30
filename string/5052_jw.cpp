#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s[100000];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        sort(s, s + n);
        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i + 1].substr(0, s[i].length()) == s[i])
            {
                flag = false;
                break;
            }
        }
        flag ? cout << "YES\n"
                    : cout<< "NO\n";
    }
    return 0;
}