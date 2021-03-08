#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, k;
int checked[100001];
bool finded;
int res, min_time;
int dx[3] = {-1, 1};
int isValid(int x)
{
    return x >= 0 && x <= 100000;
}
void bfs(int s)
{
    queue<pair<int, int>> q;
    q.push({s, 0});
    checked[s] = true;
    while (!q.empty())
    {
        int cx = q.front().first;
        int t = q.front().second;
        if (cx == k)
        {
            ++res;
            min_time = t;
        }
        q.pop();
        dx[2] = cx;
        for (int i = 0; i < 3; i++)
        {
            int nx = cx + dx[i];
            if (isValid(nx) && (!checked[nx] || checked[nx] == t + 1))
            {
                checked[nx] = t + 1;
                q.push({nx, t + 1});
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    bfs(n);
    cout << min_time << '\n'
         << res;
}