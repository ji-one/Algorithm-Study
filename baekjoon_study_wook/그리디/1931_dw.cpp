//1931 회의실 배정 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> v;
bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main(){
	cin >>n;
	for(int i=0; i<n; i++){
		int start, end;
		cin >> start >> end;
		v.push_back({start, end});
	}
	sort(v.begin(),v.end(),cmp);
	
	int e = v[0].second;
	int rst = 1;
	for(int i=1; i<n; i++){
		if(v[i].first >= e){
			e = v[i].second;
			rst++;
		} 
	}
	cout << rst;
	return 0;
}
