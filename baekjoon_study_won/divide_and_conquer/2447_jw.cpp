#include <iostream>
using namespace std;
char a[7000][7000];
void div(int x, int y, int l)
{
    if (l == 3)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != 1 || j != 1)
                    a[y + i][x + j] = '*';

        return;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != 1 || j != 1)
                div(x + j * (l / 3), y + i * (l / 3), l / 3);
}
int main()
{
    int n;
    fill(&a[0][0], &a[6999][7000], ' ');
    cin >> n;
    div(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << '\n';
    }
}