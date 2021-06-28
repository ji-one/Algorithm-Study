// 2210 숫자판 점프

#include <iostream>
#include <string>

using namespace std;

int num[6][6];
int check[1000000];
int rst;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isInside(int x, int y){
    return x>=0 && x<5 && y>=0 && y<5;
}
void dfs(int x, int y, int sum, int cnt) {
    if(cnt == 6) {
        if(!check[sum]) {
            check[sum] = 1;
            rst++;
        }
        return ;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isInside(nx, ny)) {
            dfs(nx, ny, sum*10 + num[nx][ny], cnt+1);
        }
    }
}
int main() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> num[i][j];
        }
    }

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            dfs(i,j, num[i][j], 1);
        }
    }

    cout << rst;
    return 0;
}