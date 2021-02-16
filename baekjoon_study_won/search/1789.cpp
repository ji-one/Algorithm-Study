#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long s;
    cin >> s;

    long long sum = 0;
    for (long long i = 1; i <= s; i++)
    {
        sum += i;

        if (sum == s)
        {
            cout << i;
            break;
        }
        if (sum > s)
        {
            cout << i - 1;
            break;
        }
    }

    return 0;
}