// 12851 숨바꼭질 2
#include<iostream>
#include <queue>
#include <vector>
using namespace std;

int n,k;
int rst;
int cnt;
int dx[]={1,-1,2};
int visit[100001];
vector<int> v;
void bfs(){
    queue<pair<int,int>> q; // 위치, 몇초 후
    q.push({n,0});
    
    while(!q.empty()){
        int cx = q.front().first;
        int ct = q.front().second;
        visit[cx]=1;
        q.pop();
        if(cx == k){
            if(rst==0){ // 처음방문이면
                rst = ct;
                cnt++;
            }
            else if(rst == ct){ // 최소시간인지 확인
                cnt++;
            }
        }
        for(int i=0;i<3; i++){
            int nx;
            if(i == 2){
                nx = cx * dx[i];
            }
            else{
                nx = cx + dx[i];
            }
            if(nx>=0 && nx<=100000 && !visit[nx]){                
                q.push({nx, ct+1});
            }
        }
    }
    return ;
}
int main(){
    cin >> n >> k;
    bfs();
    cout << rst << '\n' << cnt;
    return 0;
}