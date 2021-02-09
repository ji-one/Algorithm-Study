// 2776 암기왕
#include<iostream>
#include<unordered_set>

using namespace std;

int t, n, m;
unordered_set<int> us;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            int tmp;
            scanf("%d",&tmp);
            us.insert(tmp);
        }
        cin >> m;
        for(int i=0; i<m; i++){
            int tmp;
            scanf("%d",&tmp);
            auto it = us.find(tmp);
            if(it != us.end()) printf("1\n");
            else            printf("0\n");
        }
        us.clear();
    }
    return 0;
}