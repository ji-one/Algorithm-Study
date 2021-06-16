// 2609 최대공약수와 최소공배수

#include <iostream>

using namespace std;

int lcd(int a, int b) {
    if(b==0) return a;
    return lcd(b, a%b);
}
int main() {
    int n,m;
    cin >> n >> m;
    int g = lcd(n,m);
    cout << g <<'\n' << n*m/g;
    return 0;
}