// 16927 배열 돌리기 2

#include <iostream>
#include <algorithm>

using namespace std;

int n,m,r;
int arr[301][301];

void rotate(int start, int x, int y, int rcnt) {

    while(rcnt--) {
        int temp = arr[start][start];
        for(int i = start; i<=y-1; i++) {
            arr[start][i] = arr[start][i+1];
        }

        for(int i = start; i<=x-1; i++) {
            arr[i][y] = arr[i+1][y];
        }

        for(int i = y; i>start; i--) {
            arr[x][i] = arr[x][i-1];
        }

        for(int i = x; i>start; i--) {
            arr[i][start] = arr[i-1][start];
        }

        arr[start+1][start] = temp;
    }
    
}

int main() {
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }

    
    int cnt = min(n,m)/2;
    int x = n, y = m;
    int idx = 1;
    while(cnt--) {
        int rcnt = r%((n+m-(idx-1)*4-2)*2);
        // cout << (n+m-(idx-1)*4-2)*2 << '\n';
        rotate(idx, x, y, rcnt);

        idx++;
        x--; y--;

        
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}