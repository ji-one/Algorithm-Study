// 3015 오아시스 재결합
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    stack<pair<int,int>> st;  // (키, 연속된 같은사람 수)
    long long rst = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        long long tmp = 0;
        if(st.empty()){
            st.push({a, 1});
        }
        else{
            int cnt = 1;
            if(a >= st.top().first){
                while(!st.empty() && st.top().first <= a){
                    if(st.top().first == a){
                        cnt = st.top().second + 1;
                    }
                    tmp+=st.top().second;
                    st.pop();
                }
                if(!st.empty()) tmp++;
                
            }
            else if(a < st.top().first){
                tmp++;
            }
            st.push({a,cnt});
        }
        // cout << "A : " << tmp << '\n';
        rst += tmp;
    }
    cout << rst <<'\n';
    return 0;
}