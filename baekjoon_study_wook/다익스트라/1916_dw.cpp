// 1916 최소비용 구하기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int INF = 100000000; // 가중치 * 정점 수
int n,m;
vector<pair<int, int>> v[1001];
int dist[1001];


void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int current = pq.top().second;
        int cost = -pq.top().first;
        
        pq.pop();

        if(dist[current] < cost) continue;
        for(int i=0;i<v[current].size(); i++){
            int nextNode = v[current][i].first;
            int nextCost = v[current][i].second + cost;

            if(nextCost < dist[nextNode]){
                
                dist[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
        
    }
    
    return ;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, e;
        cin >> x >> y >>e;
        v[x].push_back({y, e});
    }
    fill(dist,dist+n+1,INF);
    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << dist[end];
    return 0;
}