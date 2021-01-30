#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int rst = 0;

    while (n--)
    {
        bool visited['z' + 1] = {
            false,
        };
        bool flag = true;
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++)
        {
            if (!visited[s[i]])
            {
                visited[s[i]] = true;
            }
            else if (i > 0 && s[i] != s[i - 1])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ++rst;
        }
    }
    cout << rst;

    return 0;
}