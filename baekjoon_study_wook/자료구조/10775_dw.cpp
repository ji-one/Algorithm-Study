// 10775 공항

#include <iostream>

using namespace std;

int g,p;
int air[100001];

int _find(int node) {
    if(air[node] == -1) return node;
    return air[node] = _find(air[node]);
}

int main() {
    cin >> g >> p;
    fill(air, air+g+1, -1);
    int ans=0;
    for(int i=0; i<p; i++) {
        int gate;
        cin >> gate;

        if(air[gate] == -1) {    // 비었으면
            air[gate] = gate - 1;
        } else {
            int emptyGate = _find(air[gate]);
            air[emptyGate] = emptyGate - 1;
            if(air[emptyGate] == -1) {
                break;
            }
            
        }
        // cout << "gate : " <<  air[gate] <<'\n';
        ans++;
        
    }
    // for(int i=1; i<=g; i++) {
    //     cout << air[i] << ' ';
    // }
    // cout << '\n';
    cout << ans;
    return 0;
}