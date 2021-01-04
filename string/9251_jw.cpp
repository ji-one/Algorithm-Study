#include <iostream>
#include <string>
using namespace std;
int d[1001][1001];
int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;

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
    cout << d[s1.length()][s2.length()];
}