#include <iostream>
#include <vector>
using namespace std;
// solution
int res;
vector<int> know;
int parent[51];
vector<int> v[51];
int getParent(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y)
{
    x = getParent(x);
    y = getParent(y);

    if (x > y)
        parent[x] = y;
    else
        parent[y] = x;
}
int main()
{
    int n, m, t; // 사람 수, 파티 수, 진실 아는 사람 수
    cin >> n >> m >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        know.push_back(x);
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        int num;
        int prev;
        for (int j = 0; j < p; j++)
        {
            cin >> num;
            if (j == 0)
                prev = num;
            else
            {
                unionParent(prev, num);
                prev = num;
            }
            v[i].push_back(num);
        }
    }
    res = m;
    for (int i = 0; i < m; i++)
    {
        bool flag = false;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (flag)
                break;
            for (int k = 0; k < know.size(); k++)
            {
                if (getParent(know[k]) == getParent(v[i][j]))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            res--;
    }
    cout << res;
    return 0;
}