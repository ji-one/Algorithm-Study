#include <iostream>
using namespace std;
int a[129][129];
int white, blue;
bool check(int x, int y, int l) // 전체 종이가 모두 같은 색인지 check
{
    int color = a[y][x];
    for (int i = y; i < y + l; i++)
        for (int j = x; j < x + l; j++)
            if (a[i][j] != color)
                return false;

    return true;
}
void div(int x, int y, int l)
{
    if (check(x, y, l))
    {
        if (a[y][x] == 0)
            ++white;
        if (a[y][x] == 1)
            ++blue;
        return;
    }

    div(x, y, l / 2);
    div(x + l / 2, y, l / 2);
    div(x, y + l / 2, l / 2);
    div(x + l / 2, y + l / 2, l / 2);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    div(0, 0, n);
    cout << white << '\n'
         << blue;

    return 0;
}