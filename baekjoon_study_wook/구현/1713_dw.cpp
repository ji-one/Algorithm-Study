// 1713 후보 추천하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int student[101];   // 학생의 추천 수
vector<pair<int, int>> frame;

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int recomm;
        cin >> recomm;
        if(student[recomm] > 0 ) {
            student[recomm]++;
        } else if(frame.size() < n) {
            frame.push_back({recomm, 0});
            student[recomm]++;
        } else {
            int minIndex = 0;
            int minRecom = student[frame[minIndex].first];
            int old = frame[minIndex].second;
            for(int j=1; j<n; j++) {
                if(minRecom > student[frame[j].first]) {
                    minIndex = j;
                    minRecom = student[frame[j].first];
                    old = frame[j].second;
                } else if(minRecom == student[frame[j].first]) {
                    if(old < frame[j].second) {
                        minIndex = j;
                        minRecom = student[frame[j].first];
                        old = frame[j].second;
                    }
                }
            }
            
            student[frame[minIndex].first] = 0;
            frame[minIndex].first = recomm;
            frame[minIndex].second = 0;
            student[recomm]++;
        }

        for(int j=0; j<frame.size(); j++) {
            frame[j].second++;
        }

        
    }

    sort(frame.begin(), frame.end());
    for(int i=0; i<frame.size(); i++) {
        cout << frame[i].first << ' ';

    }
    return 0;
}