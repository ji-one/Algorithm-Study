#include <iostream>
#include <algorithm>
using namespace std;
int a[10];
int p[10];
bool visited[10];
int n, m;
void permutation(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << p[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            p[cnt] = a[i];
            visited[i] = true;
            permutation(cnt + 1);
            visited[i] = false;
        }
    }
}
int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    permutation(0);
    return 0;
}