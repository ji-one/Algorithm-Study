// 11279 최대 힙
#include <iostream>
#include <queue>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}