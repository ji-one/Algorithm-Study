// 1946 신입 사원

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, n;
int main() {
    cin >> T;
    vector<pair<int, int>> v;

    while(T--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        int minGrade = v[0].second;
        int count = 1;

        for(int i=1; i<n; i++) {
            if(v[i].second < minGrade) {
                minGrade = v[i].second;
                count++;
            }
        }

        cout << count << '\n';
        v.clear();
    }
    return 0;
}