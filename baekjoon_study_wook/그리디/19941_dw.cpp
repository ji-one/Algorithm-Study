// 19941 햄버거 분배

#include <iostream>
#include <string>

using namespace std;

int n,k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    int eat = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 'P') {
            for(int j= i - k; j<= i + k; j++) {
                if(j < 0 || j >= n) continue;
                if(s[j] == 'H') {
                    s[j] = 'O';
                    eat++;
                    break;
                }
            }
        }
    }
    cout << eat;
    return 0;
}