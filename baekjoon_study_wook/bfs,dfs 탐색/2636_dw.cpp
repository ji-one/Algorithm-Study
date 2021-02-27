// 2636 치즈
/*
    솔루션 봄
    치즈가 잇으면 0->1로 변경
    변경되는게 없을 때 까지 찾는다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int cheeze[101][101];
int visit[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
bool isInside(int x, int y){
    return x>=0 &&x<n && y>=0 && y<m;
}
vector<int> v;
int bfs(int x, int y){
    int cnt = 0;;
    queue<pair<int,int>> q;
    q.push({x,y});
    visit[x][y] = 1;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(isInside(nx,ny) &&!visit[nx][ny] ){
                if( cheeze[nx][ny] == 0 ){
                    q.push({nx,ny});
                }
                else if(cheeze[nx][ny] == 1){
                    cheeze[nx][ny] = 0;
                    cnt++;
                }
                visit[nx][ny]=1;
            }            
        }
    }
    return cnt;
}
int main(){

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> cheeze[i][j];
        }
    }
    int rst=0;

    while(1){
        memset(visit, 0, sizeof(visit));
        rst = bfs(0,0);
        if(rst) v.push_back(rst);
        else break;
    }
    cout << v.size() << '\n' << v.back();

    return 0;
}