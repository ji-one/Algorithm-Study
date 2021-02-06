// 11403 경로 찾기
#include <iostream>

using namespace std;

int graph[101][101];
int before[101][101];
int n;
int MAX = 101;

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    // 더 가까운 경로 최신화
                    graph[i][j] = graph[i][k] + graph[k][j];
                    // 직전 정점 행렬 최신화
                    // before[i][j] = before[k][j];
                }
            }
        }
    }
}
int main(){
    cin >> n;

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         graph[i][j] = MAX;
    //         if(i==j) graph[i][j] = 0;
    //         // before[i][j] = -1;
    //     }
    // }

    for(int i=1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0)
                graph[i][j] = MAX;
        }
    }
    floyd();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j] <101 ) graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}