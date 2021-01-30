// 14499 주사위 굴리기 
#include <iostream>

using namespace std;

int n,m,r,c,k;
int arr[21][21];
int dise[6];
//  	    동 서 북 남 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isInside(int x, int y){
	return (x>=0 && x<n && y>=0 && y<m); 
}


int main(){
	
	cin >> n >> m >> r >> c >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	
	int d;
	int up = 1; // 주사위 첫 윗면 
	while(k--){
		cin >> d;
		
		if(!isInside(r+dx[d-1],c+dy[d-1])) continue;
		
		r = r+dx[d-1];
		c = c+dy[d-1];
		
		if(d == 1){
			int tmp = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = dice[1];
			dice[1] = tmp;
		}
		if(d == 2){
			int tmp = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = dice[1];
			dice[1] = tmp;
		}
		if(d == 3){
			int tmp = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = dice[1];
			dice[1] = tmp;
		}
		if(d == 4){
			int tmp = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = dice[1];
			dice[1] = tmp;
		}
		
		if(arr[r][c] == 0){
			arr[r][c] = dice[7-up];
		}
		else{
			dice[7-up] = arr[r][c];
			arr[r][c] = 0;
		}
		
		cout << dice[up] << '\n';
	}
	
	return 0;
}
