// 16198 에너지 모으기

#include <iostream>
#include <algorithm>
using namespace std;

int n, rst;
int w[11];
int visit[11];

void dfs(int sum, int cnt) {
    if(n-2 == cnt) {
        if(rst < sum) {
            rst = sum;
        }
        return ;
    }

    for(int i = 1; i<n-1; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            int left  = i-1;
            int right = i+1;
            while(visit[left]){
                left--;
            }
            while(visit[right]){
                right++;
            }
            
            dfs(sum + w[left]*w[right], cnt + 1);
            visit[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> w[i];
    }
    
    dfs(0, 0);
    cout << rst;
    return 0;
}