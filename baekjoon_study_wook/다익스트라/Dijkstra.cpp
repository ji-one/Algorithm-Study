// 하나의 정점에서 다른 모든 정점들의 최단 경로를 구한다.
// c++ 우선순위 큐 다익스트라 알고리즘

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int number = 6;
int INF = 10000000;
vector<pair<int, int>> a[7]; // 간선 정보(연결 정점, 비용)
int dis[7]; // 최소 비용

void dijkstra(int start){
    dis[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});

    // 가까운 순서대로 처리
    while(!pq.empty()){
        int current = pq.top().first;
        // 짧은 것이 먼저 오도록 음수화한다.
        int d = -pq.top().second;
        pq.pop();
        // 최단거리가 아니면 스킵
        if(dis[current] < d) continue;
        for(int i=0; i<a[current].size(); i++){
            // 선택된 노드의 인접 노드
            int nextNode = a[current][i].first;
            int nextCost = a[current][i].second + d;
            if(nextCost < dis[nextNode]){
                dis[nextNode] = nextCost;
                pq.push({nextNode, -nextCost});
            }
        }
    }

    return ;
}
int main(){

    // 연결되지 않으면 무한으로 초기화
    for(int i=1; i<=number; i++){
        dis[i] = INF;
    }

    a[1].push_back({2,2});
    a[1].push_back({3,5});
    a[1].push_back({4,1});

    a[2].push_back({1,2});
    a[2].push_back({3,3});
    a[2].push_back({4,2});

    a[3].push_back({1,5});
    a[3].push_back({2,3});
    a[3].push_back({4,3});
    a[3].push_back({5,1});
    a[3].push_back({6,5});

    a[4].push_back({1,1});
    a[4].push_back({2,2});
    a[4].push_back({3,3});
    a[4].push_back({5,1});
    
    a[5].push_back({3,1});
    a[5].push_back({4,1});
    a[5].push_back({6,2});

    a[6].push_back({3,5});
    a[6].push_back({5,2});

    dijkstra(1);

    for(int i = 1; i<= number; i++){
        cout << dis[i] << ' ';
    }
    return 0;
}