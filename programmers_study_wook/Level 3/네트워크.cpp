#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[201];
void bfs(int v, vector<vector<int>> computers){
    visit[v] = 1;
    queue<int> q;
    q.push(v);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<computers.size(); i++){
            if(visit[i] == 0 && computers[x][i] == 1){
                visit[i] = 1;
                q.push(i);
            }
        }
    }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<computers.size(); i++){
        if(visit[i] == 0){
            bfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}