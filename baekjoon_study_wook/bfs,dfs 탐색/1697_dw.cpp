//1697 ¼û¹Ù²ÀÁú
 
#include <iostream>
#include <queue>

using namespace std;

int n,k;
int visit[100001];
int dx[2] = {-1,1};

bool isInside(int x){
	return (x>=0 && x<=100000);
}

void bfs(){

	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<3; i++){
			int nx;
			if(i==2){
				nx = x * 2;
			}
			else{
				nx = x + dx[i];
			}
			if(isInside(nx) && visit[nx] == 0){
				visit[nx] = visit[x] + 1;
				q.push(nx);
			}
		}
	}
	
	return ;
}
int main(){
	cin >>n >>k;
	bfs();
	if(n == k){
		cout << 0;
	}
	else{
		cout << visit[k] ;
	}
	return 0;
}
