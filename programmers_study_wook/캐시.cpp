// 2018 카카오
#include <string>
#include <vector>
using namespace std;

vector<pair<string,int>> cache;

string toUpper(string s){
    string temp ="";
    for(int i=0; i<s.size(); i++){
        if(s[i]>='a' && s[i]<='z')
            temp+=(s[i]-('a'-'A'));
        else{
            temp+=s[i];
        }
    }
    return temp;
}
int isHit(string s){
    for(int i=0; i<cache.size(); i++){
        if(cache[i].first == s)
            return i;
    }
    return -1;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for(int i=0; i<cities.size(); i++){
        string tmp = "";
        tmp = toUpper(cities[i]);
        int pos = isHit(tmp);
        if(pos != -1) {// 캐시에 있으면
            cache[pos].second=0;
            for(int j=0; j<cache.size(); j++){
                cache[j].second++;
            }
            answer++;
        }
        else{   // 캐시 없으면
            if(cache.size()<cacheSize){
                cache.push_back({tmp, 0});
                for(int j=0; j<cache.size(); j++){
                    cache[j].second++;
                }
                answer+=5;
            }
            else if(cache.size() == cacheSize){
                int LRU = 0;
                for(int i=1; i<cache.size(); i++){
                    if(cache[LRU].second <cache[i].second){
                        LRU = i;
                    }
                    
                }
                if(cacheSize != 0){
                    cache[LRU].first = tmp;
                    cache[LRU].second = 0;
                    for(int j=0; j<cache.size(); j++){
                        cache[j].second++;
                    }
                }
                
                answer+=5;
            }
        }
        
    }
    return answer;
}