#include <iostream>
#include <vector>
using namespace std;

int N,M,K;
int r, c, m, s, d;
int arr[51][51];

int dx[8]= {-1,-1,0,1,1,1,0,-1};
int dy[8]= {0,1,1,1,0,-1,-1,-1};

int main(){
	cin >> N >> M >> K;
	
	vector<pair<int,int>> v;	// 위치 
	vector<int> v1[N][N];	// 질량 
	vector<int> v2[N][N];	// 속력 
	vector<int> v3[N][N];	// 방향 
	for(int i=0; i<M; i++){
		cin>> r >> c >> m >> s >> d;
		arr[r][c] = 1;
		v.push_back({r,c});
		v1[r][c].push_back(m);
		v2[r][c].push_back(s);
		v3[r][c].push_back(d);	
	}
	
//	for(int i=1; i<=N; i++){
//		for(int j=1; j<=N; j++){
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';

	while(K--){
		int total = 0;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				total+=arr[i][j];
			}
		}
		cout << "total : "<<total<< '\n';
		for(int i=0; i<total; i++){
			int x = v[i].first;
			int y = v[i].second;
			int dir = v3[x][y][0];
			int spe = v2[x][y][0];
			int mas = v1[x][y][0];
			arr[x][y]--;
			v.erase(v.begin());
			v1[x][y].erase(v1[x][y].begin());
			v2[x][y].erase(v2[x][y].begin());
			v3[x][y].erase(v3[x][y].begin());
			
			for(int j=0; j<spe; j++){
				x = (x +dx[dir])%(N);
				if(x == 0) 
					x = N;
				y = (y +dy[dir])%(N);
				if(y == 0) 
					y = N;
			}
			cout << "AAAAAAAa" <<'\n';
			
			arr[x][y]++;
			v1[x][y].push_back(mas);
			v2[x][y].push_back(spe);
			v3[x][y].push_back(dir);
			cout << "x : " << x << " y : " << y << " d : " << dir << '\n';
			v.push_back({x,y});
		}
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(arr[i][j] >=2){
					
					int tmp1=0;  // 질량 합 
					int tmp2=0;  // 속력 합 
					int tmp3=0;  // 방향 합 
					int num= arr[i][j]; // 합쳐진 파이어볼 개수 
					for(int k=0; k<num; k++){
						tmp1 += v1[i][j][k];
						tmp2 += v2[i][j][k];
						tmp3 += v3[i][j][k];
					}
					v1[i][j].clear();
					v2[i][j].clear();
					v3[i][j].clear();
					if(tmp1 > 0){
						if(tmp3%2 == 0){  // 합이 짝수이므로 모두 홀수이거나 짝수  
							for(int k=0; k<4; k++){
								v1[i][j].push_back(tmp1/5);
								v2[i][j].push_back(tmp1/num);
								v3[i][j].push_back(k*2);
							}
						}
						else{
							for(int k=0; k<4; k++){
								v1[i][j].push_back(tmp1/5);
								v2[i][j].push_back(tmp1/num);
								v3[i][j].push_back(k*2+1);
							}
						}
						arr[i][j] = 4;
						
					}
					else{
						arr[i][j] = 0;
					}
				}
			}
		}
	}
	int sum=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(arr[i][j] != 0)
				for(int k=0; k<arr[i][j]; k++){
					sum += v1[i][j][k];
				}
		}
	}
	cout << sum;
	return 0;
}
