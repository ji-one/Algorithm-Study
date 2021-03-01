#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int x = s/n;
    int r = s%n;
    if(x==0) return {-1};
    for(int i=0; i<n; i++){
        answer.push_back(x);
    }
    for(int i=0, idx=n-1; i<r; i++,idx--){
        answer[idx]++;
    }
    return answer;
}