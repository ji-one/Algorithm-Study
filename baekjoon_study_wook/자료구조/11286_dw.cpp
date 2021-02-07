// 11286 절댓값 힙
#include <iostream>
#include <queue>

using namespace std;

int n;
int main(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.size() == 0){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top().second <<'\n';
                // if(pq.top().second == 0){
                //     cout << -pq.top().first << '\n';
                // }
                // else{
                //     cout << pq.top().first << '\n';
                // }
                pq.pop();
            }
        }
        else{
            pq.push({abs(x),x});
            // if(x>0){
            //     pq.push({x,1});
            // }
            // else{
            //     pq.push({-x,0});
            // }
        }
    }
    return 0;
}