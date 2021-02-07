// 2565 전깃줄
// 솔루션 봄
// 오른쪽 전봇대에 왼쪽 전봇대의 숫자를 매핑시킨 후 가장 긴 오름차순 수를 찾는다.
// -> 전체 - 교차하지 않는 전선 수 = 제거해야하는 전선 수
// dp[a] = b   a까지 인덱스에 증가하는 부분수열 개수

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
int line[501];
int dp[510];
int main(){
    cin >> n;
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end()); // b 전봇대에 a 전선을 순서대로 매핑하기 위해 정렬
    int m =v.size();

    for(int i=0; i<m; i++){
        line[i] = v[i].second;
    }

    int rst = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<i; j++){
            if(line[i] > line[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(dp[i] == 0)
            dp[i] = 1;
        rst = max(rst, dp[i]);
    }
    
    cout << n - rst;
    return 0;
}