#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    unordered_map<string, int> m;
    vector<pair<int, string>> v;
    int t = 1;
    for (int i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        if (m[cities[i]] != 0) // cache hit
        {
            answer += 1;
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j].second == cities[i])
                {
                    v[j].first = t;
                    break;
                }
            }
            ++t;
        }
        else // cache miss
        {
            if (cacheSize != 0)
            {
                if (v.size() == cacheSize) // cache full
                {
                    sort(v.begin(), v.end());
                    string tmp = v[0].second;
                    m[tmp] = 0;
                    m[cities[i]] = 1;
                    v[0].first = t;
                    v[0].second = cities[i];
                    t++;
                }
                else // cold miss
                {
                    m[cities[i]] = 1;
                    v.push_back({t, cities[i]});
                    t++;
                }
            }
            answer += 5;
        }
    }

    return answer;
}