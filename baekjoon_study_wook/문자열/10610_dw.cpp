// 10610 30  --- 솔루션  봄 
#include <iostream>
#include <algorithm>
using namespace std;
/*
30의 배수이기 위한 조건

1. 끝의 자리수가 0이어야 한다.
2. 각 자리의 수의 합이 3의 배수여야 한다. 
*/
bool cmp(char a, char b ){
	return a>b;
}
int main(){
	string num = "";
	cin >> num;
	int len = num.size();
	int sum =0;
 	for(int i=0; i<len; i++){
 		sum += num[i]-'0';
	}
	
	if(sum%3 == 0){
		sort(num.begin(),num.end(),cmp);
		if(num[len-1] == '0'){
			for(int i=0; i<len; i++){
				cout << num[i];
			}
		}
		else{
			cout << -1;
		}
	}
	else{
		cout << -1;
	}
	
	return 0;
} 
