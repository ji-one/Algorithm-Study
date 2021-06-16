// 14890 경사로

#include <iostream>

using namespace std;

int n,l, rst;
int map1[101][101][2];
int map2[101][101][2];
bool isInside(int x) {
    return x>=0 && x<n;
}

int main() {
    cin >> n >> l;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map1[i][j][0]; 
            map2[i][j][0] = map1[i][j][0];
        }
    }

    for(int i=0; i<n; i++) {
        int cp = map1[i][0][0];
        bool f = true;
        for(int j=1; j<n; j++) {
            int np = map1[i][j][0];
            // cout << i << ' ' << j << '\n';
            if(cp == np) {
                cp = np;
            } else if(cp - np == 1) {
                int cnt = 1;
                while(1) {
                    
                    if(map1[i][j][1] == 1) {
                        f = false;
                        break;
                    }
                    map1[i][j][1] = 1;
                    if(cnt == l) {
                        break;
                    }
                    j++;
                    if(!isInside(j)) {
                        f = false;
                        break;
                    }
                    if(map1[i][j][0] != np) {
                        f = false;
                        break;
                    }
                    cnt++;
                    
                }
                cp = np;
            } else if(np - cp == 1) {
                int cnt = 1;
                j--;
                while(1) {
                    if(map1[i][j][1] == 1) {
                        f = false;
                        break;
                    }
                    map1[i][j][1] = 1;
                    if(cnt == l) {
                        j = j+l;
                        break;
                    }
                    j--;
                    if(!isInside(j)) {
                        f = false;
                        break;
                    }
                    if(map1[i][j][0] != cp) {
                        f = false;
                        break;
                    }
                    cnt++;
                    
                }
                cp = np;
            } else {
                f = false;
                break;
            }
            if(!f) {
                break;
            }
        }
        if(f) {
            rst++;
        }
    }

    for(int j=0; j<n; j++) {
        int cp = map2[0][j][0];
        bool f = true;
        for(int i=1; i<n; i++) {
            int np = map2[i][j][0];
            // cout << i << ' ' << j << '\n';
            if(cp == np) {
                cp = np;
            } else if(cp - np == 1) {
                int cnt = 1;
                while(1) {
                    
                    if(map2[i][j][1] == 1) {
                        f = false;
                        break;
                    }
                    map2[i][j][1] = 1;
                    if(cnt == l) {
                        break;
                    }
                    i++;
                    if(!isInside(i)) {
                        f = false;
                        break;
                    }
                    if(map2[i][j][0] != np) {
                        f = false;
                        break;
                    }
                    cnt++;
                    
                }
                cp = np;
            } else if(np - cp == 1) {
                int cnt = 1;
                i--;
                while(1) {
                    if(map2[i][j][1] == 1) {
                        f = false;
                        break;
                    }
                    map2[i][j][1] = 1;
                    if(cnt == l) {
                        i = i+l;
                        break;
                    }
                    i--;
                    if(!isInside(i)) {
                        f = false;
                        break;
                    }
                    if(map2[i][j][0] != cp) {
                        f = false;
                        break;
                    }
                    cnt++;
                    
                }
                cp = np;
            } else {
                f = false;
                break;
            }
            if(!f) {
                break;
            }
        }
        if(f) {
            rst++;
            // cout << j << '\n';
        }
    }
    cout << rst;
    return 0;
}