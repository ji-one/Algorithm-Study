//10819 차이를 최대로
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10];
int visited[10];
int answer;
void dfs(int cnt, int idx, int sum){
    if(cnt == n-1){
        answer = max(answer, sum);
        return ;
    }
    
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        dfs(cnt+1, i, sum + abs(arr[idx] - arr[i]));
        visited[i] = 0;
    }
    
    
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0;i <n; i++){
        visited[i] = 1;
        dfs(0,i,0);
        visited[i] = 0;
    }
    cout << answer;
    return 0;
}