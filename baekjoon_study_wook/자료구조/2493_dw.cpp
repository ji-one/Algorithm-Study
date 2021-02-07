// 2493 탑 
// 솔루션 봄
#include<iostream>
#include<stack>

using namespace std;

int n;
int sign[500001];
int main(){
    cin >> n;
    stack<pair<int,int>> st;
    for(int i=1; i<=n;i++){
        int h;
        cin >> h;
        
        while(!st.empty()){
            
            if(st.top().first > h){ // 수신하는 탑 찾음
                sign[i] = st.top().second;
                break;
            }
            st.pop(); // 현재 탑보다 작기 때문에 필요없음
        }
        st.push({h,i});
    }
    for(int i=1; i<=n; i++){
        cout <<sign[i] << ' ';
    }
    return 0;
}