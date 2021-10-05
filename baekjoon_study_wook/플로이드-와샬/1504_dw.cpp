// 1504 특정한 최단 경로

#include <iostream>
#include <algorithm>

#define MAX 8000001

using namespace std;

int n,e;
int dist[801][801];

void floyd() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j) dist[i][j] = 0;
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main() {
    cin >> n >> e;
    fill(&dist[0][0], &dist[n][n+1], MAX);

    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;                
    }

    floyd();
    int v1, v2;
    cin >> v1 >> v2;
    int d1 = dist[1][v1] + dist[v1][v2] + dist[v2][n];
    int d2 = dist[1][v2] + dist[v2][v1] + dist[v1][n];
    int rst = min(d1, d2);

    
    if(rst >=MAX) {
        cout << -1;
    } else {
        cout << rst;
    }
    return 0;
}