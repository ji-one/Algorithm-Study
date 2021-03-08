#include <iostream>
using namespace std;
int res = 1;
// solution
int a, b, c;
long long power(int n, int k)
{
    if (k == 0)
        return 1;
    long long tmp = power(n, k / 2);
    if (k % 2)
        return (tmp * tmp % c) * (n % c) % c;
    else
        return tmp * tmp % c;
}
int main()
{
    cin >> a >> b >> c;
    cout << power(a, b);
}
