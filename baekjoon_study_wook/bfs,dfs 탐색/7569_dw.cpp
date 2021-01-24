// 7569 ≈‰∏∂≈‰
#include <iostream>
#include <queue>
using namespace std;

int m,n, h;
int arr[101][101][101];
int visit[101][101][101];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

queue<pair<int, pair<int,int>>> q;

bool isInside(int x, int y, int z){
	return (x>=0 && x<h && y>=0 && y<n && z>=0 && z<m);
}

void bfs(){
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second.first;
		int cz = q.front().second.second;
		q.pop();
		for(int i=0; i<6; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nz = cz + dz[i];
			if(isInside(nx,ny,nz) && !arr[nx][ny][nz]){
				q.push({nx,{ny,nz}});
				arr[nx][ny][nz] = arr[cx][cy][cz] + 1;
			}
		}
	}
	return ;
} 
int main(){
	cin >> m >> n >> h;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				cin >> arr[i][j][k];
				if(arr[i][j][k] == 1){
					q.push({i,{j,k}});
				}
					
			}
		}
	}
	
	bfs();
	
	int rst = 0;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(arr[i][j][k] == 0){
					cout << -1;
					return 0;
				}
				else{
					rst = max(rst,arr[i][j][k]);
				}
			}
		}
	}
	cout << rst-1;
	return 0;
} 
