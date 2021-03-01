#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    // i -> B  j -> A
    // B는 항상 증가, A는 B보다 작으면 증가.
    for(int i=0, j=0; i<n; i++){
        if(A[j] < B[i]){
            j++;
            answer++;
        }
        
    }
    return answer;
}