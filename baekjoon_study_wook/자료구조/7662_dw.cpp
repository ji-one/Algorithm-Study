// 7662 이중 우선순위 큐

#include <iostream>
#include <set>
using namespace std;

int t,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    multiset<int> ms;
    cin >> t;
    while(t--){
        cin >> k;
        for(int i=0; i<k; i++){
            char c;
            int n;
            cin >> c >> n;
            if(c == 'I'){
                ms.insert(n);
            }
            if(c == 'D' && !ms.empty()){
                if(n == 1){
                    ms.erase(--ms.end());
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()) cout << "EMPTY\n";
        else            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';

        ms.clear();
    }
    

    return 0;
}