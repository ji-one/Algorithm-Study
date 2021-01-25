// 1715 카드 정렬하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
// 우선순위 큐 작은 수부터 정렬 
priority_queue<int, vector<int>,greater<int>> pq;
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	
	int sum=0;
	while(pq.size() != 1){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum +=(a+b);
		pq.push(a+b);
	}
	
	cout << sum;
	
	
	return 0;
} 
