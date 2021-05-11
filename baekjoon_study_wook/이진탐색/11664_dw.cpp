//11664 선분과 점
/*
    점들의 길이 이용
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
struct point{
    int x;
    int y;
    int z;
};

double dis(point& U, point& V){
    
    return sqrt((V.x-U.x)*(V.x-U.x) +
                (V.y-U.y)*(V.y-U.y) +
                (V.z-U.z)*(V.z-U.z));
}

double cal(double X, double Y, double W){
    double a = sqrt((X*X) - (W*W));
    double b = sqrt((Y*Y) - (W*W));
    return a+b;
}
int main(){
    point A;
    point B;
    point C;
    cin >> A.x >> A.y >> A.z
        >> B.x >> B.y >> B.z
        >> C.x >> C.y >> C.z;
    double ab = dis(A,B);
    double ac = dis(A,C);
    double bc = dis(B,C);

    double left = 0;
    double right = min(ac,bc);
    double rst = 0;
    while(right - left > 0.0000000001){
        double mid = (left + right)/2.0; // 거리
        // 거리가 작을 수록 ab에 가깝다
        if(cal(ac, bc, mid) >= ab){
            rst = mid;
            left = mid;
        }
        else{
            right = mid;
        }
    }
    printf("%.10lf", rst);
    // cout << rst;
    return 0;
}
