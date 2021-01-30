// 11656 접미사 배열

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;
vector<string> v;
int main(){
	cin >> str;
	int n = str.size();
	for(int i=0; i<n; i++){
		v.push_back(str.substr(i,n));
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++){
		cout << v[i] << '\n';
	}
	return 0;
} 
