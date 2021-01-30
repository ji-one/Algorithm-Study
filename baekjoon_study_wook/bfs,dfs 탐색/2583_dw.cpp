// 2583 영역 구하기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int m,n,k;
int arr[101][101];
int visit[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> v;

bool isInside(int x, int y){
	return (x>=0 && x<m && y>=0 && y<n);
}

void bfs(int x, int y){
	int cnt = 1;
	visit[x][y] = 1;
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(isInside(nx,ny) && !visit[nx][ny] && !arr[nx][ny]){
				q.push({nx,ny});
				visit[nx][ny] = 1;
				cnt++;
			}
		}
	}
	v.push_back(cnt);
	
	return ;
}
void square(int a, int b, int c, int d){
	for(int i=d; i<c; i++){
		for(int j=a; j<b; j++){
			arr[i][j] = 1;
		}
	}
}

int main(){
	cin >> m >> n >> k;
	for(int i=0; i<k; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//       0   4    5 - 2   5 - 4
		square(x1, x2, m - y1, m - y2);
		
	}
	for(int i=0 ; i<m; i++){
		for(int j=0; j<n; j++){
			if(!visit[i][j] && arr[i][j] == 0){
				bfs(i,j);
			}
		}
	}
//	for(int i=0; i<m; i++){
//		for(int j=0; j<n; j++){
//			cout << arr[i][j] <<' ';
//		}
//		cout << '\n';
//	}

	sort(v.begin(),v.end());
	cout << v.size() << '\n';
	for(int i=0;i<v.size();i++){
		cout << v[i] << ' ';
	}
	return 0;
} 
