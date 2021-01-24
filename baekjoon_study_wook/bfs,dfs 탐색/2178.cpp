// 2178 ¹Ì·ÎÅ½»ö 
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int map[101][101];
int visit[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isInside(int x, int y){
	return (x>=0 && x<n && y>=0 & y<m);
}

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	visit[x][y] = 1;
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(map[nx][ny] != 0 && visit[nx][ny] == 0 &&isInside(nx,ny)){
				q.push({nx,ny});
				visit[nx][ny] = 1;
				map[nx][ny] = map[cx][cy] + 1;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		for(int j=0; j<m; j++){
			map[i][j] = str[j] - '0';
		}
	}
	
	bfs(0,0);

	cout << map[n-1][m-1] << '\n';
	return 0;
}
