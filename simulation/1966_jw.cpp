#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            q.push({x, i});
            pq.push(x);
        }
        int rst = 1;
        while (!q.empty())
        {
            if (pq.top() == q.front().first)
            {
                if (q.front().second == m)
                {
                    cout << rst << '\n';
                    break;
                }
                else
                {
                    ++rst;
                    pq.pop();
                    q.pop();
                }
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}