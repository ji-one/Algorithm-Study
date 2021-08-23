// 2550 전구

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n;
int swi[11111];
int idx[11111];
int bul[11111];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        swi[i] = val;
        idx[val] = i;
    }

    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        bul[i] = idx[val];
    }

    vector<int> lis(n, MAX);
    vector<pair<int, int> > trace;

    lis[0] = bul[0];
    trace.push_back({0, bul[0]});
    for(int i=1; i<n; i++) {
        int pos = lower_bound(lis.begin(), lis.end(), bul[i]) - lis.begin();
        lis[pos] = bul[i];
        trace.push_back({pos, bul[i]});
    }

    int plis = -1;
    int len = lis.size();
    for(int i=0; i<len; i++) {
        if(lis[i] != MAX) {
            plis++;
        }
    }

    vector<int> anslis;
    len = trace.size();
    for(int i=len-1; i>=0; i--) {
        if(plis == trace[i].first) {
            anslis.push_back(trace[i].second);
            plis--;
        }
    }

    len = anslis.size();
    vector<int> ans;
    for(int i=0; i < len; i++) {
        ans.push_back(swi[anslis[i]]);
    }

    sort(ans.begin(), ans.end());

    len = ans.size();
    cout << len <<'\n';
    for(int i=0; i<len; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
/*
2 4 1 5 3
3 1 5 2 4

2 4 3 5 1
*/