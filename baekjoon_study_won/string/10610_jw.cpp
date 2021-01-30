#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[100000];
int main()
{
    // 3*10  0 1개 필수 나머지 수의 합이 3의 배수
    string n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n.length(); i++)
    {
        sum += (n[i] - '0');
        a[i] = (n[i] - '0');
    }
    sort(a, a + n.length());
    if (sum % 3 == 0 && a[0] == 0)
    {
        for (int i = n.length() - 1; i >= 0; i--)
        {
            cout << a[i];
        }
    }
    else
        cout << -1;
}
