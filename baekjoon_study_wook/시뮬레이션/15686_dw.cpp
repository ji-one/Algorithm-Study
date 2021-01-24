// 15686 ġŲ ���
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

 
int n,m;
int map[51][51];
int rst = INT_MAX;

vector<pair<int,int>> vec; // ���õ� ġŲ 
vector<pair<int, int>> v1; // ��ü ġŲ 
vector<pair<int, int>> v2; // ��ü �� 

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
	
	// ġŲ�� m �� ���� �� �ִ밪 �� 
	if(cnt == m){
		rst = min(rst,dis());
		return ;
	}
	// ġŲ�� ���� 
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
