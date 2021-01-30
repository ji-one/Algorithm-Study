#include <iostream>
#include <string>
#include <vector>
using namespace std;
int d[1001][1001];
int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    vector<char> v;

    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[i] == s2[j])
            {
                d[i + 1][j + 1] = d[i][j] + 1;
            }
            else
            {
                d[i + 1][j + 1] = max(d[i + 1][j], d[i][j + 1]);
            }
        }
    }

    int i = s1.length(), j = s2.length();
    while (1)
    {
        if (d[i][j] == 0)
            break;
        if (s1[i - 1] == s2[j - 1])
        {
            v.push_back(s1[i - 1]);
            --i, --j;
            
        }
        else
        {
            d[i - 1][j] > d[i][j - 1] ? --i : --j;
        }
    }
    cout << d[s1.length()][s2.length()] << '\n';
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
    }
}