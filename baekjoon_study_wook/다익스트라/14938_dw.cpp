// 14938 서강그라운드

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m,r;
int map[101];
vector<pair<int,int>> edge[101];
int dist[101][101];
int INF = 987654321;
void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start][start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist[start][node] < cost) continue;
        for(int i=0; i<edge[node].size(); i++){
            int nextCost = edge[node][i].second + cost;
            int nextNode = edge[node][i].first;
            if(nextCost < dist[start][nextNode]){
                dist[start][nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}
int main(){
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++){
        cin >> map[i];
    }
    for(int i=0; i<r; i++){
        int a, b, l;
        cin >> a >> b >> l;
        edge[a].push_back({b,l});
        edge[b].push_back({a,l});
    }
    fill(&dist[0][0], &dist[100][101], INF);

    // 각 시작점부터 모든 거리 최솟값 구하기
    for(int i=1; i<=n; i++){
        dijkstra(i);
    }


    int ans=0;
    for(int i=1; i<=n; i++){
        int tmp = 0;
        for(int j=1; j<=n; j++){
            // 수색범위 안이면 아이템 개수를 더함
            if(dist[i][j] > m) continue;
            tmp += map[j];
        }
        // 각 시작점마다 아이템을 가장 많이 얻을 수 있는 지역을 확인
        ans = max(ans, tmp);
    }
    cout << ans;

    return 0;
}