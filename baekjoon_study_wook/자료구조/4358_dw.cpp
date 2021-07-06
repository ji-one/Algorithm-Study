// 4385 생태학

#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s;
    map<string, double> m;
    int cnt = 0;
    while(getline(cin, s)) {
        m[s]++;
        cnt++;
    }

    map<string, double>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        
        cout << fixed;
        cout.precision(4);
        cout << it->first << ' ' << (it->second/cnt*100) << '\n';
    }

    return 0;
}