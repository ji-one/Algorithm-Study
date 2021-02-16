#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v[20001];
int visit[20001];
vector<int> rst;

bool isleaf(int x){
    for(int i=0; i<v[x].size(); i++){
        if(!visit[v[x][i]]) // 방문할 노드가 있다면
            return false;
    }
    return true;
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start]=1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(isleaf(x)){
            rst.push_back(visit[x]-1);
            continue;
        }
        for(int i=0; i<v[x].size();i++){
            if(!visit[v[x][i]]){
                visit[v[x][i]] = visit[x] + 1;
                q.push(v[x][i]);
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(1);
    sort(rst.begin(), rst.end(),greater<int>());
    answer=1;
    for(int i=1; i<rst.size(); i++){
        if(rst[i] != rst[0]) break;
        answer++;
    }
    return answer;
}