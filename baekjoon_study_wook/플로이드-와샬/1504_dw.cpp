// 1504 특정한 최단 경로

#include <iostream>

using namespace std;

int n,e,v1,v2;
int INF = 800000;
int graph[1000][1000];

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                if(graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}
int main(){
    cin >> n >> e;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            else graph[i][j] = INF;
        }
    }
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    cin >> v1 >> v2;

    floyd();
    
    int rst1 = graph[1][v1] + graph[v1][v2] + graph[v2][n];
    int rst2 = graph[1][v2] + graph[v2][v1] + graph[v1][n];

    if(rst1 >= INF && rst2>= INF) cout << -1;
    else if(rst1 < rst2){
        cout << rst1;
    }
    else{
        cout << rst2;
    }
    return 0;
}