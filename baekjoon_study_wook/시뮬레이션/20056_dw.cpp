// 20056 마법사 상어와 파이어볼
#include <iostream>
#include <vector>

using namespace std;

struct Fireball
{
	int x;
	int y;
	int mass;
	int speed;
	int dir;
};

int N,M,K;
int dx[8]= {-1,-1,0,1,1,1,0,-1};
int dy[8]= {0,1,1,1,0,-1,-1,-1};

vector<Fireball> fireball;
vector<Fireball> map[55][55];

void move(){

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			map[i][j].clear();
		}
	}

	for(int i=0; i<fireball.size(); i++){
		int r = fireball[i].x;
		int c = fireball[i].y;
		int m = fireball[i].mass;
		int s = fireball[i].speed;
		int d = fireball[i].dir;
		
		int Move = s % N;
        int nx = r + dx[d] * Move;
        int ny = c + dy[d] * Move;
        if (nx > N) nx -= N;
        if (ny > N) ny -= N;
        if (nx < 1) nx += N;
        if (ny < 1) ny += N;
		
		map[nx][ny].push_back({nx,ny,m,s,d});
		fireball[i].x = nx;
		fireball[i].y = ny;
	}
	return ;
}

void sum(){

	vector<Fireball> tmp;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j].size() == 0) continue;
			if(map[i][j].size() == 1){
				tmp.push_back(map[i][j][0]);
			}
			else{
				int new_m=0, new_s=0;
				int num = map[i][j].size();
				bool even = true;
				bool odd = true;
				for(int k=0; k<num; k++){
					new_m += map[i][j][k].mass;
					new_s += map[i][j][k].speed;
					if(map[i][j][k].dir % 2 == 0) odd = false;
					else	even = false;
				}
				new_m/=5;
				new_s/=num;
				if(new_m == 0) continue;
				if(even || odd){
					for(int k=0; k<8; k+=2){
						tmp.push_back({i,j,new_m,new_s,k});
					}
				}
				else{
					for(int k=1; k<8; k+=2){
						tmp.push_back({i,j,new_m,new_s,k});
					}
				}
			}
		}
	}
	
	fireball = tmp;

	return ;
}
int main(){
	cin >> N >> M >> K;
	for(int i=0; i<M; i++){
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >>d;
		fireball.push_back({r,c,m,s,d});
		map[r][c].push_back({r,c,m,s,d});
	}

	
	while(K--){
	// 이동 전 파이어볼 제거
		
	//1.
	move();
		
	// 2.
	sum();

	}

	int sum_mass = 0;
	for(int i=0; i<fireball.size(); i++){
		sum_mass += fireball[i].mass;
		
	}
	cout << sum_mass;
	// for(int i=0; i<fireball.size(); i++){
	// 	cout << fireball[i].mass << ' ';
	// }
	return 0;
}