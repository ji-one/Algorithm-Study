#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
int a[201];
vector<int> v; // 로봇 위치
void rotate()
{
    int tmp[201];
    a[0] = a[2 * n];
    for (int i = 1; i <= 2 * n; i++)
        tmp[i] = a[i - 1];

    for (int i = 1; i <= 2 * n; i++)
        a[i] = tmp[i];

    for (int i = 0; i < v.size(); i++)
    {
        int next = v[i] + 1;
        if (next == 2 * n + 1)
            next = 1;
        v[i] = next;
        if (next == n)
        {
            v.erase(v.begin() + i);
            --i;
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
    }
    int step = 1;
    while (1)
    {
        // 1번
        rotate();

        // 2번
        for (int i = 0; i < v.size(); i++)
        {
            int next = v[i] + 1;
            if (next == 2 * n + 1)
                next = 1;
            if (next == n && a[next] > 0)
            {
                v.erase(v.begin() + i);
                a[next]--;
                --i;
            }
            else if (a[next] > 0)
            {
                bool flag = false;
                for (int j = 0; j < v.size(); j++)
                {
                    if (j != i && next == v[j])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    v[i] = next;
                    a[next]--;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
            {
                flag = true;
                break;
            }
        }
        if (a[1] > 0 && !flag)
        {
            v.push_back(1);
            a[1]--;
        }
        int cnt = 0;

        for (int i = 1; i <= 2 * n; i++)
        {
            if (a[i] == 0)
                ++cnt;
        }
        if (cnt >= k)
            break;

        ++step;
    }
    cout << step;
}