// 15685 �巡�� Ŀ�� ---- �ַ�� �� 

#include <iostream>
#include <vector>
using namespace std;

int n;
int x, y, d, g;
		
int map[101][101];
int dx[4] = {1, 0,-1, 0}; // ->    <-
int dy[4] = {0,-1, 0, 1}; //     ��   ��

vector<int> v; // ���� ���� 

//0
//0 1
//01 21
//0121 2321
//  �߰������� ���� ���⿡ +1�� 

void dragon(){ 

	for(int i= v.size()-1; i>=0; i--){
		int nd = (v[i]+1)%4;
		x += dx[nd];
		y += dy[nd];
		map[x][y] = 1;
		v.push_back(nd);
	}
	return;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x >> y >> d >> g;
		map[x][y] = 1;
		x += dx[d];
		y += dy[d];
		map[x][y] = 1;
		v.push_back(d);
		for(int j=1; j<=g; j++){
			dragon();
		}
		v.clear();
	}
	
	
	// ���簢�� ���� Ȯ�� 
	int rst=0;
	for(int i=0; i<100; i++){
		for(int j=0; j<100;j++){
			if(map[i][j] == 1 && map[i+1][j] == 1 &&
				map[i][j+1] == 1 && map[i+1][j+1] == 1)
				rst++;
		}
	}
	
	cout << rst;
	return 0;
}
