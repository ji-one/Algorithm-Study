#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 암호 길이가 5000 이하이므로 DFS로는 풀 수 없다
string s;
int d[5001];
int main()
{
    cin >> s;

    if (s[0] != '0')
    {
        d[1] = 1;
        d[0] = 1;
    }
    for (int i = 1; i < s.length(); i++)
    {
        int n1 = s[i] - '0';
        if (n1 >= 1 && n1 <= 9)
        {
            d[i + 1] += d[i];
            d[i + 1] %= 1000000;
        }

        int n2 = (s[i - 1] - '0') * 10 + s[i] - '0';
        if (n2 >= 10 && n2 <= 26)
        {
            d[i + 1] += d[i - 1];
            d[i + 1] %= 1000000;
        }
    }
    cout << d[s.length()];
    return 0;
}