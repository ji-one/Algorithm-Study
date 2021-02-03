// 솔루션 봄
// 시간 초과 -> 그래프로 생각
#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m; // m[a]=b : a 방이 비어있지 않다면 b방으로 이동

long long find(long long num){
    if(m[num] == 0) return num;
    return m[num] = find(m[num]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i=0; i<room_number.size(); i++){
        long long num = room_number[i];
        if(m[num] == 0){
            answer.push_back(num);
            m[num] = find(num+1);
        }
        else{
            long long next = find(m[num]);
            answer.push_back(next);
            m[next] = find(next+1);
        }
        
    }
    return answer;
}