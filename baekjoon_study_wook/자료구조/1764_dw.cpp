//1764 듣보잡
#include<iostream>
#include<map>
#include<string>

using namespace std;

int n,m;
map<string, int> name;

int main(){
    cin >> n >> m;
    int cnt = 0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        name[s]++;
    }
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        name[s]++;
        if(name[s] == 2) cnt++;
    }
    cout << cnt << '\n';

    map<string,int>::iterator it;
    for(it = name.begin(); it!=name.end(); ++it){
        if(it->second == 2){
            cout << it->first << '\n';
        }
    }
    return 0;
}