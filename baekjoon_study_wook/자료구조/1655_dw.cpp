// 1655 가운데를 말해요
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq1; // 오름차순
    priority_queue<int> pq2;          // 기준보다 작은 수들

    for(int i=0 ;i<n; i++){
        int a;
        cin >> a;
        if(pq2.empty()){ // 처음엔 무조건 넣어줌
            pq2.push(a);
        }
        else{
            if(pq2.size() - pq1.size() == 0){
                if(pq2.top() > a){
                    pq2.push(a);
                }
                else{
                    if(pq1.top() > a){
                        pq2.push(a);
                    }
                    else{
                        pq2.push(pq1.top());
                        pq1.pop();
                        pq1.push(a);
                    }
                }
            }
            else if(pq2.size() - pq1.size() == 1){
                if(pq2.top() > a){
                    pq1.push(pq2.top());
                    pq2.pop();
                    pq2.push(a);
                }
                else{
                    pq1.push(a);
                }
            }
        }
        
        cout <<  pq2.top() << '\n';
    }
    return 0;
}