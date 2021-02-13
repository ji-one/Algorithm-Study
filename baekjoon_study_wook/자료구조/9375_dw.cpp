// 9375 패션왕 신해빈

#include <iostream>
#include <map>
#include <string>
using namespace std;

int tc, n;
map<string, int> m;
int main(){
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n; i++){
            string name, s;
            cin >> name >> s;
            m[s]++;
        }
        int rst = 1;
        for(auto it = m.begin(); it!=m.end(); it++){
            rst *= ((it->second) +1);
        }
        cout << rst-1 << '\n';
        m.clear();
    }
    return 0;
}