// 1339 단어 수학
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> v;
int alpa[26];
int main(){
	cin >> n;
	
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}	
	for(int i=0; i<n; i++){
		int tmp=1;
		for(int j=v[i].size()-1; j>=0; j--){
			alpa[v[i][j] - 'A'] += tmp;
			tmp*=10;
		}
	}
	sort(alpa, alpa+26, greater<int>());
	int ans=0;
	for(int i=0; i<10 ; i++){
		ans+= alpa[i]*(9-i);
//		cout << alpa[i] << ' ';
	}
	cout << ans;
	return 0;
} 
