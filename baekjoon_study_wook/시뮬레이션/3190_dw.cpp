// 3190 뱀
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int n, k, l;
int map[101][101];
int dx[]= {1,0,-1,0};
int dy[]= {0,-1,0,1};
//        하 좌 상 우
bool isInside(int x, int y){
    return x>=1 && x<=n && y>=1 && y<=n;
}
deque<pair<int, int>> snake; // 뱀 위치
queue<pair<int, char>> info; // 방향 변환 정보

int main(){
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int r, c;
        cin >> r >> c;
        map[r][c] = 1; // 사과 위치
    }
    cin >> l;
    for(int i=0; i<l; i++){
        int x;
        char a;
        cin >> x>> a;
        info.push({x,a});
    }
    int cx = 1, cy = 1;
    snake.push_back({1,1}); // 처음 뱀 위치
    int d = 3; // 오른쪽 방향
    int t=0; // 시간
    while(1){
        t++;
        
        if(t == info.front().first+1){ // 방향 변환
            if(info.front().second == 'D'){
                d = (d+1)%4;
            }
            if(info.front().second == 'L'){
                d = (d+3)%4;
            }
            info.pop();
        }
        // 머리를 다음칸에 위치
        cx += dx[d];
        cy += dy[d];
        // cout << cx << ' ' << cy << '\n';
        bool exit = false;
        //  벽이나 자기자신과 부딪히면 끝
        if(!isInside(cx, cy))  break;
        for(int i=0; i<snake.size(); i++){
            if(cx == snake.front().first && cy == snake.front().second){
                exit = true;
                break;
            }
            snake.push_back(snake.front());
            snake.pop_front();
        }
        if(exit) break;

        snake.push_back({cx,cy});
        if(map[cx][cy] == 1){ // 사과가 있다면
            map[cx][cy] = 0;
        }
        else{
            snake.pop_front();
        }
    }
    cout << t;
    return 0;
}