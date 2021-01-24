//2468 안전 영역 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
int visit[101][101];
int n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool isInside(int x, int y){
	return x>=0 && x<n && y>=0 && y<n;
}


void bfs(int x, int y, int mh){
	visit[x][y] = 1;
	queue<pair<int, int>> q;
	q.push({x,y});
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(isInside(nx,ny) && map[nx][ny]>mh && !visit[nx][ny]){
				visit[nx][ny] = 1;
				q.push({nx,ny});
			}
		}
	}
	
	return ;
}

int main(){
	cin >> n;
	int h=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			h = max(h, map[i][j]);
		}
	}
	
	int rst=0;
	for(int i=0; i<=h; i++){
		int cnt =0;
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(!visit[j][k] && map[j][k] > i){
					bfs(j,k,i);
					cnt++;
				}
			}
		}
		rst = max(cnt, rst);
		memset(visit,0,sizeof(visit));
	}
	cout << rst;
	return 0;
}
