// 1302 베스트셀러

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string book;
        cin >> book;
        m[book]++;
    }

    map<string,int>::iterator it;
    int cnt = 0;
    string title = "";
    for(it = m.begin(); it!=m.end(); it++){
        if(cnt < it->second) {
            title = it->first;
            cnt = it->second;
        }
    }
    cout << title;
    return 0;
}