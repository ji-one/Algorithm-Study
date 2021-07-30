// 1327 소트 게임

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>


using namespace std;

int n,k, answer = -1;
string a;
unordered_map<int, int> visit;    // visit check

int str2int(string s) {
    int num = 0;
    for(int i=0; i<s.size(); i++) {
        num = num*10 + (s[i] - '0');
    }
    return num;
}

bool asc(string s) {
    for(int i=1; i<s.size(); i++) {
        if(s[i] < s[i-1]) {
            return false;
        } 
    }
    return true;
}

string reverse(string s) {
    string rs = "";
    for(int i=s.size()-1; i>=0; i--) {
        rs += s[i];
    }
    return rs;
}

void bfs() {
    queue<pair<string, int>> q;
    q.push({a, 0});
    visit[str2int(a)] = 1;

    while(!q.empty()) {
        string cx = q.front().first;
        int curCnt = q.front().second;
        q.pop();

        if(asc(cx)) {
            answer = curCnt;
            return ;
        }

        for(int i=0; i<=n-k; i++) {
            string nx = "";
            nx += cx.substr(0,i);
            nx += reverse(cx.substr(i,k));
            nx += cx.substr(i+k);
            int num = str2int(nx);

            if(visit[num]) continue;
            q.push({nx, curCnt+1});
            visit[num] = 1;
        }
    }

    return ;
}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        char c;
        cin >> c;
        a += c;
    }
    bfs();
    cout << answer << '\n';
    return 0;
}
