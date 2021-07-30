// 13460 구슬 탈출 2
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n,m;
char board[11][11];
bool rvisit[11][11];
bool bvisit[11][11];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(int rx, int ry, int bx, int by) {
    queue<pair<int, pair<int, int>>> rq;   // 빨간 구슬 큐
    queue<pair<int, pair<int, int>>> bq;   // 파란 구슬 큐
    rq.push({0,{rx, ry}});
    bq.push({0,{bx, by}});
    rvisit[rx][ry] = true;
    bvisit[bx][by] = true;
    bool pass = false;
    bool fail = false;
    while(!rq.empty()) {
        int currentRedX = rq.front().second.first;
        int currentRedY = rq.front().second.second;
        int currentBlueX = bq.front().second.first;
        int currentBlueY = bq.front().second.second;
        int currentCount = rq.front().first;
        rq.pop();
        bq.pop();

        if(currentCount >= 10) {
            return -1;
        }
        for(int i=0; i<4; i++) {
            int nextRedX = currentRedX + dx[i];
            int nextRedY = currentRedY + dy[i];
            int nextBlueX = currentBlueX + dx[i];
            int nextBlueY = currentBlueY + dy[i];
            bool redPass = false;
            bool bluePass = false;

            while(board[nextRedX][nextRedY] != '#') {
                if(board[nextRedX][nextRedY] == 'O') {
                    redPass = true;
                    break;
                }
                if(nextRedX == currentBlueX && nextRedY == currentBlueY) {
                    break;
                }
                nextRedX += dx[i];
                nextRedY += dy[i];
                // cout << 1 << ' ';
            }
            if(board[nextRedX][nextRedY] != 'O'){
                nextRedX -= dx[i];
                nextRedY -= dy[i];
            }
            int tmpRedX = nextRedX;
            int tmpRedY = nextRedY;

            while(board[nextBlueX][nextBlueY] != '#') {
                if(board[nextBlueX][nextBlueY] == 'O') {
                    bluePass = true;
                    break;
                }
                if(nextBlueX == currentRedX && nextBlueY == currentRedY) {
                    break;
                }
                nextBlueX += dx[i];
                nextBlueY += dy[i];
                // cout << 2 << ' ';
            }
            if(board[nextBlueX][nextBlueY] != 'O') {
                nextBlueX -= dx[i];
                nextBlueY -= dy[i];
            }
            int tmpBlueX = nextBlueX;
            int tmpBlueY = nextBlueY;

            while(board[nextRedX][nextRedY] != '#') {
                if(board[nextRedX][nextRedY] == 'O') {
                    redPass = true;
                    break;
                }
                if(nextRedX == tmpBlueX && nextRedY == tmpBlueY) {
                    break;
                }
                nextRedX += dx[i];
                nextRedY += dy[i];
                // cout << 3 << ' ';
            }
            if(board[nextRedX][nextRedY] != 'O'){
                nextRedX -= dx[i];
                nextRedY -= dy[i];
            }
            
            while(board[nextBlueX][nextBlueY] != '#') {
                if(board[nextBlueX][nextBlueY] == 'O') {
                    bluePass = true;
                    break;
                }
                if(nextBlueX == tmpRedX && nextBlueY == tmpRedY) {
                    break;
                }
                nextBlueX += dx[i];
                nextBlueY += dy[i];
                // cout << 4 << ' ';
            }
            if(board[nextBlueX][nextBlueY] != 'O') {
                nextBlueX -= dx[i];
                nextBlueY -= dy[i];
            }
            
            if(redPass && !bluePass) {
                pass = true;
            }
            if(!((currentRedX == nextRedX && currentRedY == nextRedY) && (currentBlueX == nextBlueX && currentBlueY == nextBlueY))) {
                // rvisit[nextRedX][nextRedY] = true;
                // cout << nextRedX << ' ' << nextRedY << '|' << nextBlueX << ' ' << nextBlueY << '\n';
                if(!redPass && !bluePass) {
                    rq.push({currentCount+1, {nextRedX, nextRedY}});
                    bq.push({currentCount+1, {nextBlueX, nextBlueY}});
                }
                
            }
            // cout << 5 << ' ';
        }
        if(pass) {
            return currentCount + 1;
        }
    }
    return -1;
}
int main() {
    cin >> n >> m;
    int rx, ry, bx, by;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;        
        for(int j=0; j<m; j++) {
            if(s[j] == 'R') {
                rx = i;
                ry = j;
            }
            if(s[j] == 'B') {
                bx = i;
                by = j;
            }
            board[i][j] = s[j];
        }
    }
    // cout << rx << ' ' << ry << ' ' << bx << ' ' << by << ' ';
    cout << bfs(rx, ry, bx, by);

    return 0;
}