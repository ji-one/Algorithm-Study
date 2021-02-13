// 웜홀 1865
// 솔루션 봄
// 음의 가중치가 있는 경우는 벨만 포드 알고리즘으로 해결해야 한다고 한다
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int tc, n,m,w;
int dist[501];
int INF = 987654321;
vector<pair<pair<int, int>, int>> graph;

string bellman_ford(){
    dist[1] = 0;
    // 모든 정점을 가는데 최소 비용을 알기 위해서 
    // 'n-1'번 탐색 해봐야 한다.
    for(int i=0; i<n; i++){
        for(int j=0; j<graph.size(); j++){
            int from = graph[j].first.first;
            int to = graph[j].first.second;
            int time = graph[j].second;

            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + time)
                dist[to] = dist[from] + time;
        }
    }

    for(int i=0; i<graph.size(); i++){
        int from = graph[i].first.first;
        int to = graph[i].first.second;
        int time = graph[i].second;

        if(dist[from] == INF) continue;
        if(dist[to] > dist[from] + time)
            return "YES";
    }
    return "NO";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        // initialize
        fill(dist, dist+n+1, INF);
        memset(dist, -1, sizeof(dist));
        graph.clear();
        
        // input
        cin >> n >> m >> w;
        for(int i=0; i<m; i++){
            int s,e,t;
            cin >> s >>e >>t;
            graph.push_back({{s,e},t});
            graph.push_back({{e,s},t});   
        }
        for(int i=0; i<w; i++){
            int s,e,t;
            cin >> s >> e >>t;
            graph.push_back({{s,e},-t});
        }

        cout << bellman_ford() << '\n';
    }
    return 0;
}