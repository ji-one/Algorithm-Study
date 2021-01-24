//1946 신입 사원 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t,n;
vector<pair<int, int>> v;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			v.push_back({a,b});
		}
		sort(v.begin(), v.end());
		int rst=1;
		int tmp = v[0].second;
		
		for(int i=1; i<n; i++){
			if(v[i].second < tmp){
				rst++;
				tmp = v[i].second;
			}
				
		}
		cout << rst<< '\n';
		v.clear();
	}
	return 0;
}
