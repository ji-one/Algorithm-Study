// 1238 파티

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 987654321;
int n , m, x;
int dist[1001][1001]; //dist[a][b] a에서 b까지 최소 비용
vector<pair<int,int>> edge[1001]; // edge[a] {b,c} a->b  c 정보

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start][start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist[start][node] < cost) continue;
        for(int i=0; i<edge[node].size(); i++){
            int nextCost = cost + edge[node][i].second;
            int nextNode = edge[node][i].first;
            if(nextCost < dist[start][nextNode]){
                dist[start][nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}

int main(){
    cin >> n >> m >> x;
    fill(&dist[0][0], &dist[1000][1001], INF);

    for(int i=0; i<m; i++){
        int from, to, t;
        cin >> from >> to >> t;
        edge[from].push_back({to,t});
    }
    for(int i=1; i<=n; i++){
        dijkstra(i);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        int tmp = dist[i][x] + dist[x][i];
        if(tmp > ans){
            ans = tmp;
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << ans;

    return 0;
}