// 1963 소수 경로

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int testCase, answer;
int primeNum[10000];
int visit[10000];

int str2int(string s) {
    int n = 0;
    for(int i=0; i<s.size(); i++) {
        n = n*10 + (s[i]-'0'); 
    }
    return n;
}

bool bfs(string a, string b) {
    queue<pair<string, int> > q;    // 현재 소수, 회수
    q.push({a,0});
    visit[str2int(a)] = 1;

    while(!q.empty()) {
        string cx = q.front().first;
        int curCnt = q.front().second;
        q.pop();

        if(cx == b) {
            answer = curCnt;
            return true;
        }
        for(int i=0; i<4; i++) {
            string nx = cx;
            for(int j=0; j<=9; j++) {
                nx[i] = (j + '0');
                int num = str2int(nx);
                if(visit[num]) continue;
                if(num < 1000 || num >= 10000) continue;
                if(primeNum[num]) {
                    q.push({nx, curCnt + 1});
                    visit[num] = 1;
                }
            }
        }
        
    }

    return false;
}
int main() {
    cin >> testCase;

    for(int i=2; i<=10000; i++) {
        primeNum[i] = i;
    }
    for(int i=2; i<=10000; i++) {
        if(primeNum[i] == 0) continue;
        for(int j=i+i; j<=10000; j+=i) {
            primeNum[j] = 0;
        }
    }
    
    while(testCase--) {
        string a, b;
        cin >> a >> b;
        if(bfs(a,b)) {
            cout << answer << '\n';
        } else {
            cout << "Ipossible" << '\n';
        }
        fill(visit, visit+10000, 0);
    }
    return 0;
}