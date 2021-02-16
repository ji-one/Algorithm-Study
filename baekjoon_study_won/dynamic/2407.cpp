#include <iostream>
#include <algorithm>
using namespace std;
string d[101][101]; // d[i][j] : iCj
// nCm = n!/(n-m)!*m! = n-1Cr-1 + n-1Cr
// solution
string string_add(string a, string b)
{
    int sum = 0;
    string res;
    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        res.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string comb(int n, int m)
{
    if (n == m || m == 0)
        return "1";
    if (d[n][m] != "")
        return d[n][m];
    return d[n][m] = string_add(comb(n - 1, m - 1), comb(n - 1, m));
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << comb(n, m);
    return 0;
}