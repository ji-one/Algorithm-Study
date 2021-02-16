#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int a[500][500];
int n, m, b;
int min_t = INT_MAX;
int height;
void dfs(int h)
{
    // h: 현재 만들 높이
    int inven = b; // 가진 블록 수
    int use = 0;   // 사용 블럭 수
    // 가진 블록 >= 사용 블록이어야함
    int t = 0; // 걸린 시간
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (h > a[i][j]) // 현재 높이가 만들 높이보다 낮으면 블록 꺼내서 놓기 (+1초)
            {
                t += 1 * (h - a[i][j]);
                use += (h - a[i][j]);
            }

            if (h < a[i][j]) // 현재 높이가 만들 높이보다 높으면 블록 꺼내서 인벤토리에 넣기 (+2초)
            {
                t += 2 * (a[i][j] - h);
                inven += (a[i][j] - h);
            }
        }
    }

    if (inven >= use)
    {
        if (t <= min_t)
        {
            height = h;
            min_t = t;
        }
    }

    if (h + 1 <= 256)
        dfs(h + 1);
}
int main()
{
    cin >> n >> m >> b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(0);
    cout << min_t << ' ' << height;
}