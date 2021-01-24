//1764 µË∫∏¿‚

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,answer;
string a[500001];
string b[500001];
vector<string> v;

void binarySearch(string k){
	int left = 0;
	int right = n-1;
	while(left<=right){

		int mid = (left + right)/2;
		if(a[mid] == k){
			v.push_back(k);
			break;
		}
		else if(a[mid] < k){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	return ;
}
int main(){
	cin >> n>>m;
	
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);

	for(int i=0; i<m; i++){
		cin >> b[i];
		binarySearch(b[i]);
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << '\n';
	for(int i=0; i<v.size(); i++){
		cout << v[i] << '\n';
	}
	return 0;
} 
