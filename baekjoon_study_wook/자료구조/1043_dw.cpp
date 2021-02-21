// 1043 거짓말
/*
    솔루션 봄
    Union-Find 알고리즘
    '진실을 알 수 있는 사람' // '진실을 알 수 없는 사람'
    같은 파티에 오는 사람들끼리는 모두 Parent가 동일하게 한다.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> party[51];
vector<int> knows;
int n , m, l;
int parent[51];

int getParent(int node){
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

void union_(int a, int b){
    a = getParent(a);
    b = getParent(b);
    parent[b] = a;
}

bool isSame(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b) return true;
    else     return false;
}
int main(){
    cin >> n >> m;
    cin >> l;
    int ans = m;    // 파티 수 - (진실말해야하는 수)

    // 진실을 아는사람
    for(int i=0; i<l; i++){
        int a;
        cin >> a;
        knows.push_back(a);
    }

    // 각 파티마다 오는 사람 저장
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }

    // 부모노드를 자기자신으로 초기화
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }

    // 파티를 같이 가는 사람끼리 집합
    for(int i=0; i<m; i++){
        for(int j=1; j<party[i].size(); j++){
            union_(party[i][0], party[i][j]);
        }    
    }

    for(int i=0; i<m; i++){
        bool go_party = true;
        for(int j=0; j<party[i].size(); j++){
            if(!go_party) break;
            // 아는 사람의 부모노드 체크
            for(int k=0; k<knows.size(); k++){
                if(isSame(party[i][j], knows[k])){
                    ans--;
                    go_party = false;
                    break;
                }
            }
        }
    }
    
    cout << ans;
    

    return 0;
}