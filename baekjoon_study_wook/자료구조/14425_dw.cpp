// 14425 문자열 집합
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int n,m;
unordered_set<string> us;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    int ans=0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        us.insert(s);
    }
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        if(us.find(s) != us.end())
            ans++;
    }

    cout << ans;
    return 0;
}