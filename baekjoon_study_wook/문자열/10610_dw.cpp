// 10610 30  --- �ַ��  �� 
#include <iostream>
#include <algorithm>
using namespace std;
/*
30�� ����̱� ���� ����

1. ���� �ڸ����� 0�̾�� �Ѵ�.
2. �� �ڸ��� ���� ���� 3�� ������� �Ѵ�. 
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
