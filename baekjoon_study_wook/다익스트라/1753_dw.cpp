// 1753 최단경로
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int INF = 200001;
int v, e, k;
vector<pair<int, int>> a[20001];
int dist[20001];

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;  // 출발노드, 비용
    pq.push({0, start});  // pair 는 first끼리 먼저 비교하므로 first에 거리가 들어가야 한다.

    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(dist[current] < cost) continue;
        for(int i=0; i<a[current].size(); i++){
            int nextNode = a[current][i].first;
            int nextCost = a[current][i].second + cost;

            if(dist[nextNode] > nextCost){
                pq.push({-nextCost, nextNode});
                dist[nextNode] = nextCost;
            }
        }

    }

    return ;
}
int main(){
    cin >> v >> e >> k;
    for(int i = 0; i<e; i++){
        int u, v, w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back({v,w});
    }
    for(int i=1; i<=v; i++){
        dist[i] = INF;
    }
    dijkstra(k);

    for(int i=1; i<=v; i++){
        if(dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }
    return 0;
}