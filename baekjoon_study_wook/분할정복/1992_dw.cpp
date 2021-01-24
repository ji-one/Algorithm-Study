// 1992 ÄõµåÆ®¸®
#include <iostream>

using namespace std;

int n;
string arr[65];

bool isOneZero(int x, int y, int num){
	char tmp = arr[x][y];
			
	for(int i=x; i<x+num; i++){
		for(int j=y; j<y+num; j++){
			if(tmp != arr[i][j])
				return false;
		}
	}
	return true;
}
string solve(int x, int y, int num){
	string w = "";
	if(isOneZero(x,y,num)){
		if(arr[x][y] == '1')
			return "1";
		else
			return "0";
	}
	else{
		w = ("(" + solve(x,y,num/2) + 
				   solve(x,y+num/2,num/2) + 
				   solve(x+num/2,y,num/2) + 
				   solve(x+num/2,y+num/2,num/2) +
				")");
		return w;
	}
	
//	return ;
}
int main(){
	cin >> n;
	string answer= "";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	answer = solve(0,0,n);
	cout << answer;
	return 0;
} 
