#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int a[51][51];
int comb[14];
int n, m;
int rst = INT_MAX;
vector<pair<int, int>> h; // home (r,c)
vector<pair<int, int>> c; // chicken
int distance(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2);
}
void dfs(int idx, int cnt)
{
    if (cnt == m)
    {
        int sum = 0;
        for (int i = 0; i < h.size(); i++)
        {
            int r1 = h[i].first;
            int c1 = h[i].second;
            int min_dist = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                int r2 = c[comb[j]].first;
                int c2 = c[comb[j]].second;
                min_dist = min(min_dist, distance(r1, c1, r2, c2));
            }
            sum += min_dist;
            if (sum >= rst)
                return;
        }
        rst = min(rst, sum);
        return;
    }

    for (int i = idx; i < c.size(); i++)
    {
        comb[cnt] = i;
        dfs(i + 1, cnt + 1);
        dfs(i + 1, cnt);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                h.push_back({i, j});
            if (a[i][j] == 2)
                c.push_back({i, j});
        }
    }
    dfs(0, 0);
    cout << rst;
    return 0;
}
