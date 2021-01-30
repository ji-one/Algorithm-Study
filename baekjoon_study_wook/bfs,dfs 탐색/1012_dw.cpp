// 1012 ¿Ø±‚≥Û πË√ﬂ 
 
#include <iostream>
#include <queue>

using namespace std;

int n, m, k, t;
int bachu[51][51];
int visit[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isInside(int x, int y){
	return (x>=0 && x<m && y>=0 && y<n);
}

void bfs(int y, int x){
	visit[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({y,x});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i=0; i<4 ; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(isInside(nx, ny) && !visit[ny][nx] && bachu[ny][nx]){
				q.push({ny,nx});
				visit[ny][nx] = 1;
				
			}
		}
		
	}
}

int main(){
	cin >> t;
	
	while(t--){
		int cnt=0;
		cin >> m >> n >> k;
		for(int i=0; i<k; i++){
			int x,y;
			cin >> x >> y;
			bachu[y][x] = 1;
		}
		for(int i=0; i<n;i++){
			for(int j=0; j<m; j++){
				if(bachu[i][j] && !visit[i][j]){
					bfs(i,j);
					cnt++;
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j =0; j<m; j++){
				bachu[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
} 
