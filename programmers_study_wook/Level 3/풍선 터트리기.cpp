/*
    솔루션 
    가장 작은 수 A, 두번째로 작은 수 B, 세번째로 작은 수 C
    1) A < C < B 순서로 놓여 있다면 C는 반드시 텨져야하는 풍선이다.
    2) C < A || B < C 순서로 C가 놓여있다면 반드시 살아 남을 수 있는 풍선이다.
    
    2) 상황에서 A B 범위를 재설정 해야한다.(나보다 더 작은 숫자가 존재하는 범위)
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int A, B, C;
    vector<pair<int,int>> v;
    for(int i=0; i<a.size(); i++){
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    A = min(v[0].second, v[1].second);
    B = max(v[0].second, v[1].second);
    
    // A < C < B 순서 확인
    for(int i=2; i<v.size(); i++){
        C = v[i].second;
        if(A < C && C < B) continue; // 반드시 터진다.
        if(C < A){
            A = v[i].second;
        }
        else if(B < C){
            B = v[i].second;
        }
        answer++;
    }
    
    
    return answer+2;
}