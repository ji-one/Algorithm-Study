//1120 문자열
#include <iostream>
#include <vector>
using namespace std;

string a,b;
int main(){
	cin >> a >> b;
	int n = b.size() - a.size(); // 두 문자열 길이 차이 
	int rst = 51;
	for(int i=0; i<=n; i++){
		int cnt = 0;
		for(int j=i; j<a.size(); j++){
			if(a[j] != b[j]){
				cnt++;
//				cout << j << ' ' << j <<'\n';
			}
		}
//		cout << '\n';
		rst = min(rst, cnt);
		a='0'+a;
	}
	cout << rst<< '\n'; 
	
	return 0;
} 
