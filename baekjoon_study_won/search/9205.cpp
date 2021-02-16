#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
// solution
vector<pair<int, int>> v;
int n;
int map[102][102];
bool visited[102];
bool isPossible;
void dfs(int start, int end)
{
    visited[start] = true;
    if (start == end)
    {
        isPossible = true;
        return;
    }
    for (int i = 0; i < n + 2; i++)
    {
        if (map[start][i] == 1 && !visited[i])
            dfs(i, end);
        // visited 다시 false 해줄 필요 없음. 
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
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        v.clear();
        isPossible = false;

        cin >> n;
        for (int i = 0; i < n + 2; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if ((abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) <= 1000)
                {
                    map[i][j] = 1;
                }
            }
        }
        dfs(0, n + 1);
        if (isPossible)
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }

    return 0;
}