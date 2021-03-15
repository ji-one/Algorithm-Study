// 2529 부등호
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char arr[10];
int visit[10];
vector<int> v;
vector<string> a;

void dfs(int cnt){
    if(cnt == n+1){
        
        for(int i=0; i<n; i++){
            if(arr[i] == '<'){
                if(!(v[i] < v[i+1])) return ;
            }
            else{
                if(!(v[i] > v[i+1])) return ;
            }
        }

        string num = "";
        for(int i=0; i<v.size(); i++){
            num += (v[i] + '0');
        }
        a.push_back(num);
        return ;
    }
    for(int i=0; i<10; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
        visit[i] = 0;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dfs(0);
    sort(a.begin(), a.end());
    cout << a.back() <<'\n' << a.front();
    return 0;
}