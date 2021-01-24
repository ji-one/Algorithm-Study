// 4796 д╥гн 
#include <iostream>

using namespace std;

int l,p,v;
int main(){
	
	
	int idx =0;
	while(1){
		idx++;
		int ans = 0;
		cin >> l >> p >> v;
		if(l == 0 && p == 0 && v == 0) break;
		while(v>0){
			if(l <= v){
			ans+=l;
			v=v-p;
			}
			else{
				ans+=v;
				v=0;
			}
		}
		cout <<"Case " << idx <<": " << ans << '\n';
	}
	return 0;
}
