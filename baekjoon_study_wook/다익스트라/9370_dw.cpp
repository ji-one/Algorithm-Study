// 9370 미확인 도착지

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int T, n,m,t, s,g,h;
vector<pair< int, int> > map[2001];
int dist[2001][2001];

void dijkstra(int start){
    dist[start][start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int currentNode = pq.top().second;
        int currentCost = -pq.top().first;
        pq.pop();

        if(dist[start][currentNode] < currentCost) continue;
        for(int i=0; i<map[currentNode].size(); i++) {
            int nextNode = map[currentNode][i].first;
            int nextCost = currentCost + map[currentNode][i].second;
            if(dist[start][nextNode] > nextCost) {
                dist[start][nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}
int main() {
    cin >> T;
    
    while(T--) {

        cin >> n >> m >> t; // 교차로, 도로, 목적지 개수
        cin >> s >> g >> h; // 출발지, 이동한 지점
        
        for(int i=0; i<m; i++) {
            int a,b,d;
            cin >> a >> b>> d;
            map[a].push_back({b, d});
            map[b].push_back({a, d});

        }
        fill(&dist[0][0], &dist[n][n+1], INF);
        
        dijkstra(s);
        dijkstra(g);
        dijkstra(h);
        vector<int> v;
        for(int i=0; i<t; i++) {
            int x;
            cin >> x;
            int a = dist[s][g] + dist[h][x] + dist[g][h];
            int b = dist[s][h] + dist[g][x] + dist[g][h];
            int c = min(a,b);
            if(c == dist[s][x]) {
                v.push_back(x);
            }

        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        v.clear();
        for(int i=0; i<=n; i++) {
            map[i].clear();
        }
    }
    
    return 0;
}