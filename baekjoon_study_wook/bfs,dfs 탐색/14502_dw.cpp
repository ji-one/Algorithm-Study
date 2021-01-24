// 14502 楷备家 --  贾风记 曼绊 

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[9][9];
int tmp[9][9];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int rst;

bool isInside(int x, int y){
	return (x>=0 && x<n && y>=0 && y<m);
}

void bfs(){
	int vir[9][9];  
	memcpy(vir, tmp, sizeof(tmp));
	queue<pair<int,int>> q;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(vir[i][j] == 2){
				q.push({i,j});
			}
		}
	}
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(isInside(nx,ny) && vir[nx][ny]==0){
				q.push({nx,ny});
				vir[nx][ny] = 2;
			}
		}
	}
	
	int c=0;
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(vir[i][j] == 0){
				c++;
			}
		}
	}

	rst = max(rst, c);
	return ;
}

void dfs(int cnt){
	if(cnt == 3){
		bfs();
		return ;
	}
	
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(tmp[i][j] == 0){
				tmp[i][j] = 1;
				dfs(cnt+1);
				tmp[i][j] = 0;
			}
			
		}
	}
}
int main(){
	cin >> n >> m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j] == 0){
				memcpy(tmp, map, sizeof(map));
				tmp[i][j] = 1;
				dfs(1);
				tmp[i][j] = 0;
			}
		}
	}
	
	cout << rst <<'\n';
	return 0;
} 
