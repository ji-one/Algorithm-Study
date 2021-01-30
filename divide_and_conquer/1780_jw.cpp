#include <iostream>
using namespace std;
int p1, p2, p3;
int a[3000][3000];
bool check(int x, int y, int l) // 전체 종이가 모두 같은 색인지 check
{
    int tmp = a[y][x];
    for (int i = y; i < y + l; i++)
        for (int j = x; j < x + l; j++)
            if (a[i][j] != tmp)
                return false;

    return true;
}
void div(int x, int y, int l)
{
    if (check(x, y, l))
    {
        int tmp = a[y][x];
        if (tmp == -1)
            ++p1;
        if (tmp == 0)
            ++p2;
        if (tmp == 1)
            ++p3;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            div(x + j * (l / 3), y + i * (l / 3), l / 3);
        }
    }
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
    cout << p1 << '\n'
         << p2 << '\n'
         << p3;
    return 0;
}