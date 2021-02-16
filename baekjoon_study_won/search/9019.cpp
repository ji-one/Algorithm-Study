#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
bool visited[10001];
// solution
string bfs(int s, int e)
{
    memset(visited, false, sizeof(visited));
    queue<pair<int, string>> q;
    q.push({s, ""});
    visited[s] = true;
    while (!q.empty())
    {
        int cx = q.front().first;
        string cmd = q.front().second;
        q.pop();

        if (cx == e)
            return cmd;

        int nx;
        nx = (cx * 2) % 10000;
        if (!visited[nx])
        {
            visited[nx] = true;
            q.push({nx, cmd + "D"});
        }

        if (cx == 0)
            nx = 9999;
        else
            nx = cx - 1;
        if (!visited[nx])
        {
            visited[nx] = true;
            q.push({nx, cmd + "S"});
        }

        nx = (cx % 1000) * 10 + (cx / 1000);
        if (!visited[nx])
        {
            visited[nx] = true;
            q.push({nx, cmd + "L"});
        }

        nx = (cx % 10) * 1000 + (cx / 10);
        if (!visited[nx])
        {
            visited[nx] = true;
            q.push({nx, cmd + "R"});
        }
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--)
    {
        int s, e;
        cin >> s >> e;

        cout << bfs(s, e) << '\n';
    }

    return 0;
}