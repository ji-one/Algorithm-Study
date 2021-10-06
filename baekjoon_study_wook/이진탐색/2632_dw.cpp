// 2632 피자판매

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pizzaSize;
int m, n;
int a[1001];
int b[1001];

void allfind(vector<int> & v, int size, int f){
    int i=0;
    while(i<size) {
        int cnt = 0;
        int sum = 0;
        int idx = i;
        while(cnt<size) {
            cnt++;
            if(f == 1) {
                sum += a[idx++];
            } else {
                sum += b[idx++];
            }
            v.push_back(sum);
            if(idx == size) {
                idx = 0;
            }
        }

        if(i!=0) {
            v.pop_back();
        }
        i++;
    }
}
int main() {
    cin >> pizzaSize;
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    vector<int> asum;
    vector<int> bsum;

    allfind(asum, m, 1);
    allfind(bsum, n, 2);
    asum.push_back(0);  // b 피자만으로 가능

    sort(asum.begin(), asum.end());
    sort(bsum.begin(), bsum.end());
    
    
    int rst = 0;
    for(int i=0; i<asum.size(); i++) {
        int needsize = pizzaSize - asum[i];
        if(needsize == 0) { // a 피자만으로 가능
            rst++;
            continue;
        }
        int cnt = upper_bound(bsum.begin(), bsum.end(), needsize) - lower_bound(bsum.begin(), bsum.end(), needsize);
        if(cnt>0) {
            rst += cnt;
        }
    }
    cout << rst;
    return 0;
}