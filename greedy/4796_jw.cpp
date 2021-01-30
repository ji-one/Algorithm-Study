#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t = 0;
    while (1)
    {
        ++t;
        int l, p, v, res = 0;
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)
            break;
        res += (v / p) * l;
        if (v % p <= l)
        {
            res += (v % p);
        }
        else
        {
            res += l;
        }

        cout << "Case " << t << ": " << res << '\n';
    }
}