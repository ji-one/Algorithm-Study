#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
string map[25];
bool visited[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<int> rst;
void bfs(int x, int y)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        ++cnt;
        for (int i = 0; i < 4; i++)
        {
            int nx = q.front().first + dx[i];
            int ny = q.front().second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (map[nx][ny] == '1' && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        q.pop();
    }
    rst.push_back(cnt);
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '1' && !visited[i][j])
            {
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }
    sort(rst.begin(), rst.end());
    cout << rst.size() << '\n';
    for (int i = 0; i < rst.size(); i++)
    {
        cout << rst[i] << '\n';
    }
    return 0;
}