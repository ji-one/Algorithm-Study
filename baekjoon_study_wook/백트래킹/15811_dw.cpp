// 15811 복면산?!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a, b, sum;
int alpha[26];
vector<char> al;
bool num[10];
string answer = "NO";

bool check() {
    int x=0, y=0, z=0;
    for(int i=0; i<a.size(); i++) {
        x = x*10 + alpha[a[i]-'A']; 
    }
    for(int i=0; i<b.size(); i++) {
        y = y*10 + alpha[b[i]-'A']; 
    }
    for(int i=0; i<sum.size(); i++) {
        z = z*10 + alpha[sum[i]-'A']; 
    }
    if(x+y == z) {
        return true;
    }
    return false;
}
void dfs(int cnt) {
    if(cnt == al.size()) {
        if(check()) {
            answer = "YES";
        }
        return ;
    }

    for(int i=0; i<10; i++) {
        if(num[i] == true) continue;
        num[i] = true;
        alpha[al[cnt]-'A'] = i;
        dfs(cnt+1);
        alpha[al[cnt]-'A'] = -1;
        num[i] = false;
    }
    
}
int main() {
    cin >> a >> b >> sum;
    for(int i=0; i<a.size(); i++) {
        alpha[a[i]-'A']++;
    }    
    for(int i=0; i<b.size(); i++) {
        alpha[b[i]-'A']++;
    }    
    for(int i=0; i<sum.size(); i++) {
        alpha[sum[i]-'A']++;
    }   
    for(int i=0; i<26; i++) {
        if(alpha[i]>0)
            al.push_back(i + 'A');
    }
    fill(alpha, alpha+26, -1);
    dfs(0);
    cout << answer;

    return 0;
}