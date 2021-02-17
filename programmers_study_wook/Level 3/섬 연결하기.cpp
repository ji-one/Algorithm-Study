/*
    Kruskal 알고리즘 - 사이클 유무확인 위해 union-find 알고리즘 사용
    솔루션봄
    
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum[101];

// 가중치 정렬
bool cmp(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

// 부모노드 찾기
int getParent(int x){
    if(sum[x] == x) return x;
    return sum[x] = getParent(sum[x]);
}

// 부모노드 합치기
void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b) sum[b] = a;
    else    sum[a] = b;
}

// 부모노드가 같은지 비교
bool find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b) return true;
    else    return false;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    // 가중치 기준으로 정렬
    sort(costs.begin(), costs.end(), cmp);
    // 부모노드로 초기화
    for(int i=0; i<n; i++){
        sum[i] = i;
    }
    for(int i=0; i<costs.size(); i++){
        // 두개의 부모노드가 같지 않다면
        // -> 사이클이 생성되지 않는다면
        if(!find(costs[i][0], costs[i][1])){
            //결과에 가중치 추가
            answer+=costs[i][2];
            //부모노드 병합
            unionParent(costs[i][0], costs[i][1]);
        }
    }
    return answer;
}