// 16935 배열 돌리기 3

#include <iostream>

using namespace std;

int n,m, r;
int a[101][101];
int b[101][101];
int main() {
    cin >> n>>m>>r;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    while(r--) {
        int c;
        cin >> c;
        copy(&a[0][0], &a[n-1][m], &b[0][0]);
        switch (c)
        {
        case 1:
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    a[n-i-1][j] = b[i][j];
                }
            }
            break;
        case 2:
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    a[i][m-j-1] = b[i][j];
                }
            }
            break;
        case 3:
            swap(n,m);
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    a[i][m-j-1] = b[j][i];
                }
            }
            break;
        case 4:
            swap(n,m);
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    a[i][m-j-1] = b[m-j-1][n-i-1];
                }
            }
            break;
        case 5:
            for(int i=0; i<n/2; i++) {
                for(int j=0; j<m/2; j++) {
                    a[i][j+m/2] = b[i][j];
                }
            }
            for(int i=0; i<n/2; i++) {
                for(int j=m/2; j<m; j++) {
                    a[i+n/2][j] = b[i][j];
                }
            }
            for(int i=n/2; i<n; i++) {
                for(int j=m/2; j<m; j++) {
                    a[i][j-m/2] = b[i][j];
                }
            }
            for(int i=n/2; i<n; i++) {
                for(int j=0; j<m/2; j++) {
                    a[i-n/2][j] = b[i][j];
                }
            }
            break;
        case 6:
            for(int i=0; i<n/2; i++) {
                for(int j=0; j<m/2; j++) {
                    a[i+n/2][j] = b[i][j];
                }
            }
            for(int i=0; i<n/2; i++) {
                for(int j=m/2; j<m; j++) {
                    a[i][j-m/2] = b[i][j];
                }
            }
            for(int i=n/2; i<n; i++) {
                for(int j=m/2; j<m; j++) {
                    a[i-n/2][j] = b[i][j];
                }
            }
            for(int i=n/2; i<n; i++) {
                for(int j=0; j<m/2; j++) {
                    a[i][j+m/2] = b[i][j];
                }
            }
            break;
        default:
            break;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0 ;j<m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}