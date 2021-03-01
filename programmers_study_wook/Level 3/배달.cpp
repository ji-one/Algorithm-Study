// 다익스트라

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dist[51];
int INF = 987654321;
vector<pair<int, int>> edge[51];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[node] < cost) continue;
        for(int i=0; i< edge[node].size(); i++){
            int nextNode = edge[node][i].first;
            int nextCost = cost + edge[node][i].second;
            if(dist[nextNode] > nextCost){
                dist[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
    
        
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i=0; i<road.size(); i++){
        int start = road[i][0];
        int end = road[i][1];
        int cost = road[i][2];
        edge[start].push_back({end, cost});
        edge[end].push_back({start, cost});
    }
    
    fill(dist, dist+N+1, INF);
    dijkstra(1);
    
    for(int i=1; i<=N; i++){
        if(dist[i] <=K)
            answer++;
    }
    return answer;
}