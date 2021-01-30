// µ¢Ä¡ 7568 
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> v;
vector<int> r;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	
	for(int i=0; i<n; i++){
		int cx = v[i].first;
		int cy = v[i].second;
		int rank = 1;
		for(int j=0; j<n; j++){
			if(cx < v[j].first && cy < v[j].second)
				rank++;
			
		}
		r.push_back(rank);
	}
	
	for(int i=0; i<r.size(); i++)
		cout << r[i] << ' ';
	return 0;
}
