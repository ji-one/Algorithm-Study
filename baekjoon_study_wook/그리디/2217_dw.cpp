// 2217 ทฮวม
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	int ans = 0;
	for(int i=0; i<n; i++){
		ans = max(ans, v[i]*(n-i));
	}
	cout << ans;
	return 0;
} 
