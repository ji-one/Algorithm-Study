// 16197 두 동전

#include <iostream>
#include <queue>

using namespace std;

int n,m;
char board[21][21];
int visit[21][21][21][21];  //coin1, coin2 의 위치 

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isInside(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(int coin1X, int coin1Y, int coin2X, int coin2Y) {
    queue<pair<int, pair<int, int> > > q1;
    queue<pair<int, pair<int, int> > > q2;
    q1.push({0, {coin1X, coin1Y}});
    q2.push({0, {coin2X, coin2Y}});
    visit[coin1X][coin1Y][coin2X][coin2Y] = 1;

    while(!q1.empty() && !q2.empty()) {
        int currentCoin1X = q1.front().second.first;
        int currentCoin1Y = q1.front().second.second;
        int currentCoin2X = q2.front().second.first;
        int currentCoin2Y = q2.front().second.second;
        int currentCoinMove = q1.front().first;
        q1.pop();
        q2.pop();

        // cout << "coin1 : " << currentCoin1X << ' ' << currentCoin1Y << '\n';
        // cout << "coin2 : " << currentCoin2X << ' ' << currentCoin2Y << '\n';
        // cout << '\n';
        if(currentCoinMove >= 10) continue;
        for(int i=0; i<4; i++) {
            int nextCoin1X = currentCoin1X + dx[i];
            int nextCoin1Y = currentCoin1Y + dy[i];
            int nextCoin2X = currentCoin2X + dx[i];
            int nextCoin2Y = currentCoin2Y + dy[i];
            bool passCoin1 = false;
            bool passCoin2 = false;

            
            if(!isInside(nextCoin1X, nextCoin1Y)) {
                passCoin1 = true;
            }

            if(!isInside(nextCoin2X, nextCoin2Y)) {
                passCoin2 = true;
            }

            
            if(passCoin1^passCoin2) {   // 하나만 통과
                return currentCoinMove+1;
            }
            
            if(visit[nextCoin1X][nextCoin1Y][nextCoin2X][nextCoin2Y]) continue; 

            if(!passCoin1 && !passCoin2) {  // 둘다 통과 못함
                visit[nextCoin1X][nextCoin1Y][nextCoin2X][nextCoin2Y] = 1;
                
                if(board[nextCoin1X][nextCoin1Y] != '#') {
                    q1.push({currentCoinMove+1, {nextCoin1X, nextCoin1Y}});
                } else {
                    q1.push({currentCoinMove+1, {currentCoin1X, currentCoin1Y}});
                }

                if(board[nextCoin2X][nextCoin2Y] != '#') {
                    q2.push({currentCoinMove+1, {nextCoin2X, nextCoin2Y}});
                } else {
                    q2.push({currentCoinMove+1, {currentCoin2X, currentCoin2Y}});
                }
            }

            // if(passCoin1 && passCoin2) {    // 둘다 통과
            // }

        }
        
    }

    return -1;
}

int main(){
    cin >> n >> m;
    int coin1X, coin1Y, coin2X, coin2Y;
    
    int c = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'o' && c == 0) {
                coin1X = i;
                coin1Y = j;
                c++;
            }

            if(board[i][j] == 'o' && c == 1) {
                coin2X = i;
                coin2Y = j;
            }
        }
    }

    cout << bfs(coin1X, coin1Y, coin2X, coin2Y);
    return 0;
}