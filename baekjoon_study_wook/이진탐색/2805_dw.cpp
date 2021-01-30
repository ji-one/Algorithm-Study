// 나무 자르기2805 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long m, result;
vector<long long> v;

void bisearch(long long start, long long end, long long key){
	long long left = start;
	long long right = end;

	while(left<=right){
		long long mid = (left+right)/2;
		
		long long tmp = 0;
		for(int i=0; i<n; i++){
			if(v[i]-mid>0)
				tmp += v[i] - mid;
		}
		if(tmp >= key){
			left = mid+1;
			result = max(mid, result);
		}
		else{
			right = mid -1;
		}
	}
}
int main(){
	cin >>n >> m;
	for(int i=0; i<n; i++){
		int h;
		cin >> h;
		v.push_back(h);
	}

	sort(v.begin(),v.end());

	bisearch(0, v[n-1], m);
	cout << result << '\n';
	return 0;
}
