// 2252 줄세우기
/*
위상 정렬 알고리즘 공부
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v[32001];
queue<int> q;
vector<int> line;

int edge[32001]; // 들어오는 간선의 수

void bfs(){
    while(!q.empty()){
        int x = q.front();
        line.push_back(x);
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            edge[v[x][i]]--;
            if(edge[v[x][i]] == 0){
                q.push(v[x][i]);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int A,B;
        cin >> A >> B;
        v[A].push_back(B);
        edge[B]++;
    }
    for(int i=1; i<=n; i++){
        // 진입 차수가 0인 정점 삽입
        if(edge[i] == 0)
            q.push(i);
    }

    bfs();

    for(int i=0; i<line.size(); i++){
        cout << line[i] << ' ';
    }
    return 0;
}
