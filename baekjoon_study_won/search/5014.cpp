#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int visited[1000000];
int f, s, g, u, d;
bool isPossible;
bool isValid(int x)
{
    return x >= 1 && x <= f;
}
void bfs(int x)
{
    queue<pair<int, int>> q;
    q.push({x, 0});

    while (!q.empty())
    {
        int cx = q.front().first;
        int t = q.front().second;
        q.pop();

        if (cx == g)
        {
            isPossible = true;
            return;
        }

        int nx = cx + u;
        if (isValid(nx) && !visited[nx])
        {
            visited[nx] = t + 1;
            q.push({nx, t + 1});
        }
        nx = cx - d;
        if (isValid(nx) && !visited[nx])
        {
            visited[nx] = t + 1;
            q.push({nx, t + 1});
        }
    }
}
int main()
{
    // 츙 f층 현재 s층, g층으로 가고픔
    // 위로 u층, 아래로 d층
    cin >> f >> s >> g >> u >> d;
    bfs(s);
    if (isPossible)
        cout << visited[g];
    else
        cout << "use the stairs";
    return 0;
}