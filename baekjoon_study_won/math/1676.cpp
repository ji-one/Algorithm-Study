#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int five = 0;

    for (int i = 1; i <= n; i++)
    {
        int num = i;
        while (num % 5 == 0)
        {
            num /= 5;
            ++five;
        }
    }

    cout << five;

    return 0;
}