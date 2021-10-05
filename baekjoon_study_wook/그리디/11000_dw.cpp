// 11000 강의실 배정

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cl;
    for(int i=0; i<n; i++) {
        int s, t;
        cin >> s>> t;
        cl.push_back({s,t});
    }

    sort(cl.begin(), cl.end());
    priority_queue<int> pq;
    pq.push(-cl[0].second);

    for(int i=1; i<n; i++) {
        if(-pq.top() <= cl[i].first) {
            pq.pop();
        }
        pq.push(-cl[i].second);
    }
    cout << pq.size();
    return 0;
}