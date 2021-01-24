//¼ö Ã£±â1920 
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int a[100001];
int b[100001];

int bisearch(int start, int end, int key){
	int left = start;
	int right = end-1;
	
	while(left<=right){
		int mid = (left+right)/2;

		if(a[mid] == key){
			return 1;
		}
		else if(a[mid] < key){
			left = mid + 1;
			
		}
		else{
			right = mid - 1;
		}
	}
	return 0;
}

int main(){
	cin >>n;
	for(int i =0; i<n; i++)
		cin >> a[i];
	
	cin >>m;
	for(int i=0; i<m; i++)
		cin >> b[i];
	
	sort(a,a+n);
	for(int i=0; i<m; i++){
		cout << bisearch(0,n,b[i]) << '\n';
	}
	return 0;
}
