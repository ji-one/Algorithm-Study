#include <iostream>
#include <queue>
using namespace std;

int t,n,m;
queue<pair<int,int>> q;
priority_queue<int> pq;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=0; i<n; i++){
			int tmp;
			cin >> tmp;
			pq.push(tmp);
			q.push({i,tmp});
			
		}
		
		int result = 0;
		while(!q.empty()){
			int a = pq.top();
			if(a == q.front().second){
				int b = q.front().first;
				q.pop();
				pq.pop();
				result++;
				if(b == m){
					cout << result << '\n';
					result = 0;	
				}
			}
			else{
				q.push(q.front());
				q.pop();
			}
		}
	}
	return 0;
}
