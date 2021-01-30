#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
bool visited[100][100];
int r, c;
bool isInside(int x, int y){
    return x >= 0 && x < c && y >= 0 && y < r;
}
int bfs(int x, int y, vector<vector<int>> picture){
    
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        ++cnt;
        
        for(int i=0;i<4;i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(isInside(nx,ny) && !visited[ny][nx] && picture[cy][cx] == picture[ny][nx]){
                visited[ny][nx] = true;
                q.push({nx,ny});
            }
        }
    
    }
    
    return cnt;
    
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int size_of_area = 0;
    r = m, c = n;
    fill(&visited[0][0], &visited[99][100], false);
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){ 
            if(!visited[i][j] && picture[i][j] != 0)
            {
                visited[i][j] = true;
                size_of_area = bfs(j,i,picture);
                ++number_of_area;
                max_size_of_one_area = max(size_of_area ,max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}