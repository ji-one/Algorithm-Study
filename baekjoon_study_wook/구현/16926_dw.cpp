// 16926 배열 돌리기 1

#include <iostream>
#include <algorithm>
using namespace std;

int n,m,r;
int a[301][301];
int b[301][301];

void rotated(int x1, int y1, int x2, int y2) {

    
    for(int i=y1; i<y2; i++) {
        a[x1][i] = b[x1][i+1];
    }

    for(int i=x1; i<x2; i++) {
        a[i][y2] = b[i+1][y2];
        // cout << "x1 : " <<  i << " y2 : " << y2 << " x2 : " << x2 << '\n';
    }

    for(int i=y2; i>y1; i--) {
        a[x2][i] = b[x2][i-1];
    }

    for(int i=x2; i>x1; i--) {
        a[i][y1] = b[i-1][y1];
    }

}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> m >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    int c = min(n,m)/2;
    // r %= ((n+m-2)*2);
    while(r--) {
        copy(&a[0][0], &a[n-1][m], &b[0][0]);
        for(int i=0, j=0; i<c; i++, j++) {
            rotated(i,j, n-i-1, m-j-1);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << a[i][j] <<' ';
        }
        cout << '\n';
    }
    return 0;
}