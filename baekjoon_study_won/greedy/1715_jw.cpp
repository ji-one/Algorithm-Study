#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// solution 봄
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int res = 0;
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        res += (x + y);
        pq.push(x + y);
    }
    cout << res;
    return 0;
}