#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int INF = 20000;
vector<pair<int, int>> v[201];
int dist[201][201];

void dijkstra(int s){
    priority_queue<pair<int, int>> pq; // 가중치, 노드
    pq.push({0,s});
    dist[s][s] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(cost > dist[s][node]) continue;
        for(int i=0; i<v[node].size(); i++){
            int nextnode = v[node][i].first;
            int nextcost = v[node][i].second + cost;
            if(dist[s][nextnode] > nextcost){
                dist[s][nextnode] = nextcost;
                pq.push({-nextcost, nextnode});
            }
        }
    }
    return ;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    for(int i=0; i<fares.size(); i++){
        v[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        v[fares[i][1]].push_back({fares[i][0], fares[i][2]});
        
    }
    memset(dist, INF, sizeof(dist));
    for(int i=1; i<=n; i++){
        dijkstra(i);
    }
    
    int fee = 987654321;
    for(int i=1; i<=n; i++){
        fee = min(dist[s][i] + dist[i][a] + dist[i][b], fee);
    }
    return fee;
}