#include <iostream>

using namespace std;

int arr[51][51];
int n,m,r,c,d;
//		  �� �� �� �� 
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
//		1. ���� ��ġ û�� 
		if(arr[r][c] == 0){
			arr[r][c] = 3;
			result++;
			cnt = 0;
		}
		
//		a. ���� ��ġ���� ���ʹ������� ȸ���ϰ� ����  
		if(arr[r+dx[(d+3)%4]][c+dy[(d+3)%4]]==0){
			r += dx[(d+3)%4];
			c += dy[(d+3)%4];           
			d = (d+3)%4;
			cnt = 0;
		}
		
//		b. ���� ��ġ���� ȸ���� 
		else if(arr[r+dx[(d+3)%4]][c+dy[(d+3)%4]]==1 || arr[r+dx[(d+3)%4]][c+dy[(d+3)%4]] == 3){     
            d = (d+3)%4;
			cnt++;
		}
//		c. �׹��� ��� û��, ���� ��  

//		d. ���� ������ ���� ��� 
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
