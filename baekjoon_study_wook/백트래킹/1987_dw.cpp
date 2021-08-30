// 1987 알파벳

#include <iostream>
#include <string>

using namespace std;

int r,c;
int answer;
string board[21];
bool alpha[27];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
bool isInside(int x, int y) {
    return x>=0 && x<r && y>=0 && y<c;
}

void dfs(int x, int y, int cnt){
    if(answer < cnt) {
        answer = cnt;
    }
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(isInside(nx, ny) && !alpha[board[nx][ny]-'A']) {
            char a = board[nx][ny];
            alpha[a-'A'] = true;
            dfs(nx, ny, cnt+1);
            alpha[a-'A'] = false;

        }
    }
    return ;
}
int main() {
    
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        cin >> board[i];
    }
    alpha[board[0][0] - 'A'] = true;
    dfs(0,0, 1);
    cout << answer;
    return 0;
}