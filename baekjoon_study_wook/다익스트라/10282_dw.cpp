// 10282 해킹
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int testcase;
int n,d,c;
vector<pair<int,int>> v[10001];
int dist[10001];
int INF = 987654321;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});    // 시간, 해킹컴퓨터
    dist[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dist[node] < cost) continue;
        for(int i=0; i<v[node].size(); i++){
            int nextcost = cost + v[node][i].second;
            int nextnode = v[node][i].first;
            if(dist[nextnode] > nextcost){
                dist[nextnode] = nextcost;
                pq.push({-nextcost, nextnode});
            }
        }

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> testcase;
    while(testcase--){
        int cnt = 0;
        int time= 0;
        cin >> n >> d >> c;
        fill(dist, dist+n+1, INF);
       
        
        for(int i=0; i<d; i++){
            int a, b, s;
            cin >> a >> b >> s;
            v[b].push_back({a, s}); // b가 감염되면 s초 후에 a 감염
        }
        
        dijkstra(c);
        for(int i=1; i<=n; i++){
            if(dist[i] != INF){
                cnt++;
                time = max(dist[i],time);
            }
        }
        cout << cnt << ' ' << time << '\n';
        for(int i=1; i<=n; i++){
            v[i].clear();
        }
    }
    return 0;
}