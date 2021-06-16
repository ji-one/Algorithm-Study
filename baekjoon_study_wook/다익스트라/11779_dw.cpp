// 11779 최소비용 구하기 2
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m;
vector<pair<int, int>> map[1001];
int dist[1001];
int pre[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start}); // 비용, 시작점
    dist[start] = 0;

    while(!pq.empty()) {
        int currentCost = -pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        
        
        if(dist[currentNode] < currentCost) continue;
        for(int i=0; i<map[currentNode].size(); i++) {
            int nextCost = currentCost + map[currentNode][i].second;
            int nextNode = map[currentNode][i].first;
            if(dist[nextNode] > nextCost) {
                pre[nextNode] = currentNode;
                dist[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        map[from].push_back({to, cost});

    }
    int start, end;
    cin >> start >> end;
    fill(dist, dist+n+1, INF);
    dijkstra(start);
    cout << dist[end] << '\n';

    vector<int> v;
    int x = end;
    while(1) {
        v.push_back(x);

        if(x == start) {
            break;
        }
        
        x = pre[x];
    }
    cout << v.size() << '\n';
    for(int i=v.size()-1; i>=0; i--) {
        cout << v[i] << ' ';
    }
    return 0;
}