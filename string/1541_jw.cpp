// 잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sum = 0;
    string num = "";
    bool minus = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num += s[i];
        }
        if (s[i] == '-' || s[i] == '+' || i == s.length() - 1)
        {
            minus ? sum -= stoi(num) : sum += stoi(num);
            if (s[i] == '-')
            {
                minus = true;
            }
            num = "";
        }
    }
    cout << sum;
    return 0;
}