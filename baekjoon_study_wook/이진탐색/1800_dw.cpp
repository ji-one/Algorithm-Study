// 1800 인터넷 설치
// 솔루션 봄

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 987654321

using namespace std;

int n, p, k;
int dist[1001];
vector<pair<int, int>> cable[1001];

bool dijkstra(int x) {
    fill(dist, dist+n+1, MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        int curCount = -pq.top().first; // 기준 값보다 비싼 개수
        int curNode = pq.top().second;
        pq.pop();

        if(dist[curNode] < curCount) continue;
        for(int i=0; i<cable[curNode].size(); i++) {
            int nextCount = curCount + (cable[curNode][i].second > x);
            int nextNode = cable[curNode][i].first;

            if(dist[nextNode] > nextCount) {
                dist[nextNode] = nextCount;
                pq.push({-nextCount, nextNode});
            }
        }
    }

    return dist[n] <= k;
}
int main() {
    cin >> n >> p >> k;
    
    int l=0, r=0, rst = -1;

    for(int i=0; i<p; i++) {
        int c1, c2, cost;
        cin >> c1 >> c2 >> cost;
        cable[c1].push_back({c2, cost});
        cable[c2].push_back({c1, cost});
        r = max(r, cost);
    }

    while(l<=r) {
        int mid = (l+r)/2;
        if(dijkstra(mid)) {
            rst = mid;
            r = mid -1;
        } else {
            l = mid +1;
        }
    }

    cout << rst;
    return 0;
}