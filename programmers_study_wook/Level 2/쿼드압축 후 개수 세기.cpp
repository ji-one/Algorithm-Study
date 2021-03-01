#include <string>
#include <vector>

using namespace std;
vector<int> answer(2,0);

bool check(const vector<vector<int>>& arr, int x, int y, int num){
    int a = arr[x][y];
    for(int i=x; i<num+x; i++){
        for(int j=y; j<num+y; j++){
            if(a != arr[i][j])
                return false;
        }
    }
    return true;
}
void solve(const vector<vector<int>>& arr, int x, int y, int num){
    // 한 영역이 1이나 0이면 끝낸다.
    if(check(arr, x, y, num)){
        if(arr[x][y])
            answer[1]++;
        else
            answer[0]++;
        return ;
    }
    
    // 4개의 영역으로 나눈다.
    solve(arr,x,y,num/2);
    solve(arr,x+num/2,y,num/2);
    solve(arr,x,y+num/2,num/2);
    solve(arr,x+num/2,y+num/2,num/2);
    
}
vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size();
    solve(arr,0,0,n);
    return answer;
}