//11404 플로이드
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int map[101][101];
int INF = 10000001;

void floyd(){
    for(int k=1; k<=n; k++){
       for(int i=1; i<=n; i++){
           for(int j=1; j<=n; j++){
               if(map[i][j] > map[i][k] + map[k][j]){
                   
                   map[i][j] = map[i][k] + map[k][j];
               }
           }
       } 
    }
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n ; j++){
            if(i==j) map[i][j] = 0;
            else     map[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        map[start][end] = min(map[start][end], cost);
        
    }
    floyd();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n ;j++){
            if(map[i][j] == INF) map[i][j] = 0;
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}