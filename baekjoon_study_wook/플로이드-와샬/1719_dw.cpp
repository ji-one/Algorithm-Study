// 1719 택배

#include <iostream>

#define INF 10000000

using namespace std;

int n,m;
int road[201][201]; 
int map[201][201];

void floyd() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i==j) continue;
                if(road[i][j] > road[i][k] + road[k][j]) {
                    road[i][j] = road[i][k] + road[k][j];
                    map[i][j] = k;
                }
            }
        }
    }
}
int main() {
    cin >> n >> m;
    
    fill(&road[0][0], &road[n][n+1], INF);
    for(int i=0; i<m; i++) {
        int u,v, cost;
        cin >> u >> v >> cost;
        road[u][v] = cost;
        road[v][u] = cost;
    }
    
    floyd();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) cout << '-' << ' ';
            else if(map[i][j] == 0) {
                cout << j << ' ';
            } else {
                int k = j;
                while(map[i][k] != 0) {
                    k = map[i][k];
                }
                cout << k << ' ';
            } 
            
        }
        cout << '\n';
    }

    return 0;
}