// ÇÑ¼ö 1065 
#include <iostream>
#include <vector>

using namespace std;

int n, result = 99;
vector<int> v;
int main(){
	cin >> n;
	
	if(n<100){
		cout << n << '\n';
		return 0;
	}
	
	for(int i=100; i<=n; i++){
		int m = i;
		while(m>0){
			v.push_back(m%10);
			m/=10;
		}
		int temp = v[1] - v[0];
		for(int j=1; j<v.size()-1; j++){
			if(v[j+1] - v[j] != temp) break;
			else if(v[j+1] - v[j] == temp && j == v.size()-2) {
				result++;
			}
		
		}
		v.clear();
	}
	cout << result <<'\n';
	return 0;
}
