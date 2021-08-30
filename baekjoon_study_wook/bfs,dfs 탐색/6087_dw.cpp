// 6087 레이저 통신

#include <iostream>
#include <queue>

using namespace std;

int w,h, answer = 987654321;
char map[101][101];
int visit[101][101];
int mirror[101][101];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool isInside(int x, int y) {
    return x>=0 && x<h && y>=0 && y<w;
}

struct info {
    int x;
    int y;
    int m;  // 거울 개수
    int d;  // 전 방향
};

void bfs(int x, int y) {
    queue<info> pq;
    pq.push({x,y,-1,-1});
    visit[x][y] = 1;

    while(!pq.empty()) {
        int cx = pq.front().x;
        int cy = pq.front().y;
        int cm = pq.front().m;
        int cd = pq.front().d;
        pq.pop();
        // cout <<  '(' << cx << ',' << cy << ')' << "mirror : " << cm << " dir : " << cd << '\n';
        if(map[cx][cy] == 'C' && !(cx == x && cy ==y)) {
            if(answer > cm) {
                answer = cm;
            }
            continue;
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(isInside(nx, ny) && map[nx][ny] != '*') {
                if(visit[nx][ny] == 0) {
                    visit[nx][ny] = 1;
                    if(cd == i) {
                        mirror[nx][ny] = cm;
                        pq.push({nx, ny, cm, i});
                    } else {
                        mirror[nx][ny] = cm + 1;
                        pq.push({nx, ny, cm + 1, i});
                    }
                } else {
                    if(cd == i) {
                        if(mirror[nx][ny] >= cm) {
                            mirror[nx][ny] = cm;
                            pq.push({nx, ny, cm, i});
                        }
                    } else {
                        if(mirror[nx][ny] >= cm +1) {
                            mirror[nx][ny] = cm + 1;
                            pq.push({nx, ny, cm +1, i});
                        }
                    }
                }
            }
        }
    }
}
int main() {
    cin >> w >> h;
    int a,b;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'C') {
                a =i;
                b =j;
            }
        }
    }
    bfs(a, b);
    cout << answer;
    return 0;
}