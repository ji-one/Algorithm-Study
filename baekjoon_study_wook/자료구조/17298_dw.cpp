// 17298 오큰수

#include <iostream>
#include <stack>

using namespace std;

int n;
int arr[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    stack<pair<int, int> > st;
    int num = 0;
    for(int i=0; i<n; i++){
        cin >> num;
        if(st.empty()){
            st.push({i,num});
        }
        else{
            if(st.top().second < num) {
                while(!st.empty()){
                    if(st.top().second >= num) {
                        break;
                    }
                    arr[st.top().first] = num;
                    st.pop();
                }
            }
            st.push({i,num});
            
        }
    }
    while(!st.empty()){
        arr[st.top().first] = -1;
        st.pop();
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';

    }
    return 0;
}