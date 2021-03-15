// 16953 A -> B

#include <iostream>
#include <queue>
using namespace std;

int A, B;
long long rst;
bool bfs(){
    queue<pair<long long, long long>> q;
    q.push({A, 1});

    while(!q.empty()){
        long long x = q.front().first;
        long long t = q.front().second;
        q.pop();

        if(x == B){
            rst = t;
            return true;
        }

        long long nx = x*2;
        if(nx <= B){
            q.push({nx, t+1});
        }

        nx = x*10+1;
        if(nx <= B){
            q.push({nx, t+1});
        }
    }
    return false;
}
int main(){
    cin >> A >> B;
    if(bfs()) cout << rst;
    else      cout << -1;

    return 0;
}