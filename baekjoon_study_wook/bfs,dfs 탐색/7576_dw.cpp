// 7576 ≈‰∏∂≈‰
#include <iostream>
#include <queue>

using namespace std; 

int n,m, rst;
int box[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<int,int>> q;

bool isInside(int x, int y){
	return (x>=0 && x<n && y>=0 && y<m);
}

void bfs(){
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(isInside(nx,ny) && box[nx][ny] == 0){
				q.push({nx,ny});
				box[nx][ny] = box[cx][cy] + 1;
			}
		}
	}
	return ;
}
int main(){
	cin >> m >>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> box[i][j] ;
			if(box[i][j] == 1) 
				q.push({i,j});
		}
	}
	
	bfs();
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout << visit[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(box[i][j] == 0){
				cout << -1;
				return 0;
			}
			rst=max(rst,box[i][j]);
		}
	}

	cout << rst-1;
	return 0;
}
