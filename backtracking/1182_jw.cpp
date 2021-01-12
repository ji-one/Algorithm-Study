#include <iostream>
#include <vector>
using namespace std;
int a[21];
int n, s;
bool visited[21];
int rst;
void dfs(int idx, int sum)
{
    if (idx == n)
    {
        if (sum == s)
            ++rst;
        return;
    }

    dfs(idx + 1, sum + a[idx]);
    dfs(idx + 1, sum);
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0);
    if (s == 0)
        --rst;
    cout << rst;
    return 0;
}