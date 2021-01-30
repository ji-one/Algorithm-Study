// 4963 ¼¶ÀÇ °³¼ö
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w,h;
int map[51][51];
int visit[51][51];
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,-1,1,1,-1,1,-1};

bool isInside(int x, int y){
	return (x>=0 && x<h && y>=0 && y<w);
}

void bfs(int x, int y){
	visit[x][y] = 1;
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<8; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(isInside(nx,ny) && !visit[nx][ny] && map[nx][ny]){
				q.push({nx,ny});
				visit[nx][ny] = 1;
			}
		}
	}
}
int main(){
	
	while(1){
		cin >> w >> h;
		if(w == 0 && h == 0) break;
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> map[i][j];
			}
		}
		
		int sum = 0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(!visit[i][j] && map[i][j]){
					bfs(i,j);
					sum++;
				}
			}
		}
		cout << sum <<'\n';
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
	}
	return 0;
}
