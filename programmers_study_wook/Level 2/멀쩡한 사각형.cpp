/*
솔루션 봄
1) 최대 공약수가 1일 때 가로 + 세로 - 1 만큼 사각형이 나줘진다.( -1 은 처음 사각형이 겹치기때문)
2) 최대 공약수가 1보다 크면 1)과 같은 상황이 최대공약수만큼 반복된다.
   그림을 그려보면 선 위에 있는 블록이 최대공약수만큼 존재한다.
   따라서 나눠지는 사각형 수는 w + h - g.  (g : 최대공약수)
*/
using namespace std;

int gcd(int w, int h){
    if(h == 0) return w;
    return gcd(h,w%h);
}
long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    int g = gcd(w,h);
    answer -= (w+h-g);
    return answer;
}