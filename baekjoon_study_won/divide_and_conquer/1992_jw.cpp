#include <iostream>
#include <string>
using namespace std;
int a[64][64];
bool check(int x, int y, int l)
{
    int tmp = a[y][x];
    for (int i = y; i < y + l; i++)
        for (int j = x; j < x + l; j++)
            if (a[i][j] != tmp)
                return false;

    return true;
}
string div(int x, int y, int l)
{
    if (check(x, y, l))
    {
        return to_string(a[y][x]);
    }

    string s = "(";

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            s += div(x + j * (l / 2), y + i * (l / 2), l / 2);

    s += ")";
    return s;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%1d", &a[i][j]);

    string rst = div(0, 0, n);
    cout << rst;
    return 0;
}