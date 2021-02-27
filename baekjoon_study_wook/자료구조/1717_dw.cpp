// 집합의 표현
// 솔루션 봄

#include <iostream>

using namespace std;

int n,m;
int num[1000001];

// 부모노드를 찾는 함수
int find(int node){
    if(num[node]== node) return node;
    else return num[node] = find(num[node]);
}

// 부모노드를 찾아서 연결시킨다.
void uni(int a, int b){
    int pa = find(a);  // a의 부모노드를 찾는다
    int pb = find(b);  // b의 부모노드를 찾는다
    num[pb] = pa;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<=n; i++){
        num[i] = i; 
    }
    for(int i=0; i<m; i++){
        int c, a, b;
        scanf("%d %d %d", &c, &a, &b);
        if(c == 0){  // 합집합
            uni(a,b);
        }
        else{ // 두 원소가 같은 집합에 포함되어있는지 확인
            if(find(a) == find(b)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}