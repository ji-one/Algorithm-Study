#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, k;
bool checked[100001];
int dx[3] = {-1, 1};
int isValid(int x)
{
    return x >= 0 && x <= 100000;
}
int bfs(int s)
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
            return t;
        }
        q.pop();
        dx[2] = cx;
        for (int i = 0; i < 3; i++)
        {
            int nx = cx + dx[i];
            if (isValid(nx) && !checked[nx])
            {
                checked[nx] = true;
                q.push({nx, t + 1});
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    cout << bfs(n);
}