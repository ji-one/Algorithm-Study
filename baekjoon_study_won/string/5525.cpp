#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int res = 0;
    for (int i = 0; i < m - 2; i++)
    {
        string tmp = "";
        if (s[i] == 'I')
        {
            tmp += 'I';
            ++i;
            while (i + 1 < m && s[i] == 'O' && s[i + 1] == 'I')
            {
                tmp += "OI";
                i += 2;
            }
            --i;
            if (tmp.length() >= 2 * n + 1)
            {
                res += ((tmp.length() - (2 * n + 1)) / 2 + 1);
            }
        }
    }
    cout << res;
    return 0;
}