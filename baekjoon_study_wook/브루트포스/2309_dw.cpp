// 2309 일곱 난쟁이
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[9];
vector<int> v;
vector<int> rst;
void dfs(int cnt, int x){
    if(cnt == 7){
        int sum = 0;
        for(int i=0 ;i<7; i++){
            sum += v[i];
        }
        if(sum == 100) {
            rst = v;
            return ;
        }
    }
    for(int i=x; i<9; i++){
        v.push_back(arr[i]);
        dfs(cnt+1, i+1);
        v.pop_back();
    }
}
int main(){
    for(int i=0; i<9; i++){
        cin >> arr[i];
    }
    dfs(0,0);

    sort(rst.begin(),rst.end());
    for(int i=0; i<rst.size();i++)
        cout << rst[i] << '\n';
    return 0;

}