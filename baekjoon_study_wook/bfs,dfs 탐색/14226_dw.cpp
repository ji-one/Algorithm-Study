// 14226 이모티콘
// solution
#include <iostream>
#include <queue>

using namespace std;

int visit[1001][1001]; // (화면에 있는 개수, 클립보드에 저장된 개수)
int s, rst;

void bfs(int v){
    queue<pair<pair<int,int>,int>> q;
    q.push({{v,0},0});  // (현재,클립) 개수, 시간
    visit[v][0] = 1;
    
    while(!q.empty()){
        int cx = q.front().first.first; // 현재 화면에 이모티콘 개수
        int cc = q.front().first.second; // 클립보드에 저장된 개수
        int ct = q.front().second;  // 현재까지 시간
        q.pop();

        if(cx == s) {   // 이모티콘 개수가 같으면 종료
            rst = ct;
            break;
        }

        // 클립보드에 현재 개수만큼 저장
        q.push({{cx, cx}, ct+1});

        // 클립보드에 있는 개수만큼 화면에 붙여넣기
        if(!visit[cx+cc][cc] && cc != 0 && (cx+cc <= 1000)){
            visit[cx+cc][cc] = 1;
            q.push({{cx+cc, cc}, ct+1});
        }

        // 화면에 이모티콘 하나를 삭제
        if(!visit[cx-1][cc] && cx>1){
            visit[cx-1][cc] = 1;
            q.push({{cx-1, cc}, ct+1});
        }
        
    }
}
int main(){
    cin >> s;
    bfs(1);

    cout << rst;

    return 0;
}