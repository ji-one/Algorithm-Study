// 5014 스타트 링크
#include<iostream>
#include<queue>
using namespace std;

int f,s,g,u,d;
int visit[1000001];
int rst;
bool bfs(){
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        // 원하는 층에 도착한다면
        if(cx == g){
            rst = visit[cx] - 1;
            return true;
        }
        int ux = cx + u;
        int dx = cx - d;
        // 올라갈수 있는지
        if(ux>=1 && ux<=f && !visit[ux]){
            q.push(ux);
            visit[ux] = visit[cx] + 1;
        }
        // 내려갈수 있는지
        if(dx>=1 && dx<=f && !visit[dx]){
            q.push(dx);
            visit[dx] = visit[cx] + 1;
        }
    }

    return false;
}
int main(){
    cin >> f >>s >>g >>u>>d;
    
    if(bfs()) cout << rst;
    else    cout <<"use the stairs";
    return 0;
}