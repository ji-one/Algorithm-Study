// 17135 캐슬 디펜스

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n,m, d, rst;
int map[20][20];
int copyMap[20][20];
int visit[20][20];
set<pair<int, int>> s;

int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};
vector<int> archer;

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void attack(int x, int y){
    queue<pair<int, pair<int, int> >> q;
    q.push({0,{x, y}});
    visit[x][y] = 1;

    while(!q.empty()) {
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int cd = q.front().first;
        q.pop();

        if(copyMap[cx][cy] == 1) {
            s.insert({cx, cy});
            return ;
        }
        if(cd >= d) continue; // 거리 이상
        for(int i=0; i<3; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx, ny) && !visit[nx][ny]) {
                q.push({cd+1, {nx,ny}});
                visit[nx][ny];
            }
        }
    }

    return ;
}

void moveEnemy() {
    for(int i=n-1; i>0; i--) {
        for(int j=0; j<m; j++) {
            copyMap[i][j] = copyMap[i-1][j];
        }
    }
    for(int j=0; j<m; j++) {
        copyMap[0][j] = 0;
    }
}

int startGame() {
    int kill = 0;
    
    copy(&map[0][0], &map[n-1][m], &copyMap[0][0]);
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) {
            attack(n, archer[j]);
            
            fill(&visit[0][0], &visit[n][m-1], 0);
        }
        kill += s.size();
        set<pair<int,int>>::iterator it;
        for(it = s.begin(); it!=s.end(); it++) {
            int x = it->first;
            int y = it->second;
            copyMap[x][y] = 0;
        }
        s.clear();
        moveEnemy();
    }
    return kill;
}

void makeGame(int idx, int cnt){ // 궁수 수
    if(cnt == 3) {
        int x = startGame();
        if(rst < x) {
            rst = x;
        }
        return ;
    }

    for(int i=idx; i<m; i++) {
        archer.push_back(i);
        makeGame(i+1, cnt+1);
        archer.pop_back();
    }
    return ;
}
int main() {
    cin >> n >> m >> d;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    makeGame(0, 0);

    cout << rst;
    return 0;
}