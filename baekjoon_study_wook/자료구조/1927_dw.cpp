// 1927 최소 힙
#include <iostream>
#include <queue>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
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