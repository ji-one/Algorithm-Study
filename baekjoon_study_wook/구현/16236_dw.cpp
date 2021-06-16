// 16236 아기상어
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
int level=2;
int map[21][21];
int visit[21][21];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int a, b;

bool isInside(int x, int y){
    return x>=0 && x<n && y>=0 &&y<n;
}
int bfs(int x, int y){
    map[x][y] = 0;  // 이동전 지우기
    visit[x][y] = 1;    
    queue<pair<int,int>> q;
    q.push({x,y});
    int c = 1000;  // 이동할 수 있는 최소거리
    a=n;        // 최소거리 x 좌표
    b=n;        // 최소거리 y 좌표

    bool flag = false;  // 이동할 수 있는지 확인
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        // 아기상어보다 작은 물고기이면서 최소거리이면
        if(map[cx][cy] < level && map[cx][cy]!=0 && c >=visit[cx][cy]){
            if(a > cx){ // 상단에 있는 물고기 선택
                flag = true;    
				a=cx;
                b=cy;
                c = visit[cx][cy];
			}
            if(a == cx && b > cy){  // 같은 줄에 있다면 좌측에 있는 물고기 선택
                flag = true;
                a=cx;
                b=cy;
                c = visit[cx][cy];
            }
        }

        q.pop();
        for(int i=0 ;i <4 ;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx,ny) && level >= map[nx][ny] && !visit[nx][ny]){
                visit[nx][ny] = visit[cx][cy]+1;
                q.push({nx,ny});
            }
        }
    }
    if(flag) return c-1;
    else     return 0;
    
}
int main(){
    cin >> n;
    int cx, cy;
    for(int i=0 ;i <n; i++ ){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    int ans=0;
    int exp=0;

    int cnt=0;
    while(1){
        int t = 0;
        // 이동거리 초기화
        memset(visit,0,sizeof(visit));

        // 먹을 수 있는 물고기가 없다면 종료
        bool exit =true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] != 0 &&level > map[i][j] && map[i][j] != 9 ){
                    exit = false;
                    break;
                }
                
            }
        }        
        if(exit) break;

        // 현재 상어 위치 저장
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == 9)
                {
                    cx = i;
                    cy = j;
                }
                
            }
        }
        // 최소이동거리 
        t = bfs(cx, cy);
        // 이동할 수 없다면 종료
        if(t == 0) break;
        // 이동한 좌표에 아기상어 배치
        map[a][b] = 9;
        // 이동거리만큼 추가
        ans+=t;
        // 물고기 한마리 먹음으로 경험치 상승
        exp+=1;

        // 상어 크기와 먹은 물고기 수가 같으면 크기 증가
        if(exp == level){
            exp=0;
            level++;
        }
        
    }
    cout << ans;
    return 0 ;
}