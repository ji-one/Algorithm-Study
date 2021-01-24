// 14500 테트로미노
#include<iostream>

using namespace std;

int n,m;
int arr[501][501];
int rst;

void test1(){
	int sum = 0;
	for(int i=0; i<n; i++){
		for(int j = 0; j<m-3; j++){
			sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
			rst = max(rst, sum);
		}
	}
	
	for(int i=0; i<n-3; i++){
		for(int j=0; j<m; j++){
			sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
			rst = max(rst, sum);
		}
	}
	
	return ;
}

void test2(){
	int sum = 0;

	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
			rst = max(rst, sum);
		}
	}
	
	return ;
}

void test3(){
	int sum = 0;

	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i][j] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i+2][j] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+2];
			rst = max(rst, sum);
		}
	}
	return ;
}

void test4(){
	int sum = 0;

	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i][j+2];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1] + arr[i][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2];
			rst = max(rst, sum);
		}
	}
	return ;
}

void test5(){
	int sum = 0;

	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i][j+2];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			sum = arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j+2] + arr[i][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1];
			rst = max(rst, sum);
		}
	}
	for(int i=0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			sum = arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j];
			rst = max(rst, sum);
		}
	}
	
	return ;
}


int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	
	test1();
	test2();
	test3();
	test4();
	test5();
	
	cout << rst;
	return 0;
}
