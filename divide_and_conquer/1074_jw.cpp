#include <iostream>
#include <cmath>
using namespace std;
int r, c;
int order;

void div(int x, int y, int l)
{
    if (x == c && y == r)
    {
        cout << order;
        exit(0);
    }

    if (l == 1)
        return;

    // 사분면 판단
    if (r < y + l / 2 && c < x + l / 2) // 1사분면
    {
        div(x, y, l / 2);
    }
    if (r < y + l / 2 && c >= x + l / 2) // 2사분면
    {
        order += pow(l / 2, 2);
        div(x + (l / 2), y, l / 2);
    }
    if (r >= y + l / 2 && c < x + l / 2) // 3사분면
    {
        order += 2 * pow(l / 2, 2);
        div(x, y + (l / 2), l / 2);
    }
    if (r >= y + l / 2 && c >= x + l / 2) // 4사분면
    {
        order += 3 * pow(l / 2, 2);
        div(x + (l / 2), y + (l / 2), l / 2);
    }
}
int main()
{
    int n;
    cin >> n >> r >> c;
    n = pow(2, n);
    div(0, 0, n);
    return 0;
}