#include <iostream>

using namespace std;

int arr[51][51];
int n,m,r,c,d;
//		  북 동 남 서 
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(){
	cin >> n >> m;
	cin >> r >> c >> d;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> arr[i][j];
			
	int result = 0;
	int cnt = 0;
	int exit = 1;
	while(exit){
//		1. 현재 위치 청소 
		if(arr[r][c] == 0){
			arr[r][c] = 3;
			result++;
			cnt = 0;
		}
		
//		a. 현재 위치에서 왼쪽방향으로 회전하고 전진  
		if(arr[r+dx[(d+3)%4]][c+dy[(d+3)%4]]==0){
			r += dx[(d+3)%4];
			c += dy[(d+3)%4];           
			d = (d+3)%4;
			cnt = 0;
		}
		
//		b. 현재 위치에서 회전만 
		else if(arr[r+dx[(d+3)%4]][c+dy[(d+3)%4]]==1 || arr[r+dx[(d+3)%4]][c+dy[(d+3)%4]] == 3){     
            d = (d+3)%4;
			cnt++;
		}
//		c. 네방향 모두 청소, 왼쪽 벽  

//		d. 뒤쪽 방향이 벽인 경우 
		if(cnt == 4){
			if(arr[r+dx[(d+2)%4]][c+dy[(d+2)%4]] != 1){
				r += dx[(d+2)%4];
				c += dy[(d+2)%4];
				cnt = 0;
			}
			else{
				exit = 0;
			}
		}
	} 
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	cout << result << '\n';
	return 0;
}
