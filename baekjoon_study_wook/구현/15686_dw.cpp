// 15686 치킨 배달
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

 
int n,m;
int map[51][51];
int rst = INT_MAX;

vector<pair<int,int>> vec; // 선택된 치킨 
vector<pair<int, int>> v1; // 전체 치킨 
vector<pair<int, int>> v2; // 전체 집 

int dis(){
	
	int d=0;
	
	for(int i=0; i<v2.size(); i++){
		int tmp1 = (abs(v2[i].first - vec[0].first) 
				+ abs(v2[i].second - vec[0].second));
		for(int j=1; j<vec.size(); j++){
			int tmp2 = (abs(v2[i].first - vec[j].first) 
				+ abs(v2[i].second - vec[j].second));;
			tmp1 = min(tmp1,tmp2); 
		}
		d+=tmp1;
	}
	return d;
}

void dfs(int cnt, int x){
	
	// 치킨집 m 개 선택 후 최대값 비교 
	if(cnt == m){
		rst = min(rst,dis());
		return ;
	}
	// 치킨집 선택 
	for(int i=x; i<v1.size(); i++){
		vec.push_back(v1[i]);
		dfs(cnt+1, i+1);
		vec.pop_back();
	}
}

int main(){
	cin >> n >> m;
	for(int i =0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> map[i][j];
			if(map[i][j] == 1)
				v2.push_back({i,j});
			if(map[i][j] == 2)
				v1.push_back({i,j});
		}
	}
	
	dfs(0,0);
	
	cout << rst;
	return 0;
} 
