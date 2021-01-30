// 문자열
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int min = b.length();
    for (int i = 0; i < b.length() - a.length() + 1; i++)
    {
        int cnt = 0;
        int k = 0;
        for (int j = i; j < i + a.length(); j++)
        {
            if (a[k++] != b[j])
            {
                ++cnt;
            }
        }
        min = min > cnt ? cnt : min;
    }
    cout << min;
    return 0;
}