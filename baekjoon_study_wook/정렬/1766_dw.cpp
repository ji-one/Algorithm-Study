// 1766 문제집
// 위상정렬

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> line;

int edge[32001]; // 들어오는 간선의 수

void bfs(){
    while(!pq.empty()){
        int cx = pq.top();
        cout << cx << ' ';
        pq.pop();
        for(int i=0; i<v[cx].size(); i++){
            int nx = v[cx][i];
            edge[nx]--;
            if(edge[nx] == 0)
                pq.push(nx);
        }
    }
    return ;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a>> b;
        v[a].push_back(b);
        edge[b]++;
    }
    for(int i=1; i<=n; i++){
        if(edge[i] == 0) pq.push(i);
    }

    bfs();

    return 0;
}