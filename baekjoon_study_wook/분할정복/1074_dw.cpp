// 1074 Z
#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;	// r За c ї­ 
int rst;
int cnt;

void solve(int x, int y, int num){
	
	if(num == 2){
		for(int i=x; i<x+2; i++){
			for(int j =y; j<y+2; j++){
				
				if(i == r && j == c){
					rst = cnt;
					return ;
				}
				cnt++;
			}
		}
	}
	else{
		int k = num/2; 
		if(r < x+k && c < y+k){  
			
			solve(x, y, num/2);
		}
		if(r < x+k && c >= y+k){  
			cnt += k*k;
			solve(x, y+k, num/2);
		}
		if(r >= x+k && c < y+k){  
			cnt += 2*k*k;
			solve(x+k, y, num/2);
		}
		if(r >= x+k && c >= y+k){  
			cnt += 3*k*k;
			solve(x+k, y+k, num/2);
		}
//		for(int i=0; i<2; i++){
//			for(int j=0; j<2; j++){
//				solve(x+(i*num/2), y+(j*num/2), num/2);
//			}
//		}
	}
	
	
	return ;
}
int main(){
	cin >> n >> r >> c;
	
	solve(0,0,pow(2,n));
	
	
	cout << rst;
	return 0;
}
