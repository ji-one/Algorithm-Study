#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int cnt = 0;
    if (s1.length() >= s2.length())
    {
        for (int i = 0; i <= s1.length() - s2.length(); i++)
        {
            int j;
            for (j = 0; j < s2.length(); j++)
            {
                if (s1[i + j] != s2[j])
                {
                    break;
                }
            }
            if (j == s2.length())
            {
                i += (j - 1);
                ++cnt;
            }
        }
    }

    cout << cnt;
}