#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x != 0)
        {
            pq.push({abs(x), x});
        }
        else
        {
            if (!pq.empty())
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}