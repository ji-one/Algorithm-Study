// solution
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long fac(int a){
    if(a == 1) return 1;
    return a*fac(a-1);
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long x, s;
    
    
    for(int i=1;i<=n; i++){
        v.push_back(i);
    }
    
    while(1){
        if(n==0) break;
        x = fac(n)/n;
        s = (k-1)/x;    // 앞자리 나누는 기준
        answer.push_back(v[s]);
        v.erase(v.begin()+s);
        n--;
        k %= x;         // 다음 (n-1)번째 에서 몇 번째 인지
        if(k == 0) k = x;
    }
    
    
    return answer;
}