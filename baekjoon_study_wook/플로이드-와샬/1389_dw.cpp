// 1389 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int INF = 500001;
int graph[101][101];

void floyd(){
    for(int k=1; k<=n; k++){
       for(int i=1; i<=n; i++){
           for(int j=1; j<=n; j++){
               if(i == j) continue;
               if(graph[i][j] > graph[i][k] + graph[k][j]){
                   
                   graph[i][j] = graph[i][k] + graph[k][j];
               }
           }
       } 
    }
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            if(i==j) graph[i][j] = 0;
            else     graph[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int start, end;
        cin >> start >> end;
        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    floyd();
    int rst = INF;
    int idx=0;
    for(int i=1; i<=n ;i++){
        int sum = 0;
        for(int j=1; j<=n; j++){
            if(graph[i][j] == INF) graph[i][j] = 0;
            sum += graph[i][j];
        }
        if(rst > sum){
            rst = sum;
            idx = i;
        }
        // cout << sum << '\n';
    }

    cout << idx;
    return 0;
}