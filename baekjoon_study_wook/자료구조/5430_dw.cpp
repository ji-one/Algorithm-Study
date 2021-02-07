// 5430 AC -- 솔루션봄
/*
앞이나 뒤원소를 추가 제거 할때는 deque 을 사용하는게 빠르다
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int t;

int main(){
    cin >> t;
    deque<int> dq;
    while(t--){
        string p;
        cin >> p;

        int n;
        cin >> n;
        
        dq.clear();
        string arr;
        cin >> arr;
        string tmp = "";
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>='0' && arr[i]<='9'){
                tmp+=arr[i];
            }
            else if(arr[i] == ',' || arr[i] == ']'){
                if(tmp.size()!=0)
                    dq.push_back(stoi(tmp));
                tmp = "";
            }
        }
        bool reverses = false;
        bool terminate= false;
        for(int i=0; i<p.size(); i++){
            if(p[i] == 'R'){
                reverses = !reverses;
            }
            else if(p[i] == 'D'){
                if(dq.size() == 0){
                    cout << "error" <<'\n';
                    terminate = true;
                    break;
                }
                if(reverses){
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }
        if(terminate) continue;
        cout << '[';
        if(!reverses){
            for(int i=0;i<dq.size(); i++){
                if(i !=dq.size() -1)
                    cout << dq[i] << ',';
                else{
                    cout << dq[i] ;
                }
            }
        }
        else{
            for(int i=dq.size()-1;i>=0; i--){
                if(i !=0)
                    cout << dq[i] << ',';
                else{
                    cout << dq[i] ;
                }
            }
        }
        
        cout << "]\n";

    }
    return 0;
}
