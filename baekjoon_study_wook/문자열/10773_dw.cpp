//Á¦·Î 10773 
#include <iostream>
#include <stack>

using namespace std;

int k;
stack<int> st;

int main(){
	cin >> k;

	for(int i=0; i<k; i++){
		int tmp;
		cin >> tmp;
		if(tmp == 0) st.pop();
		else		 st.push(tmp);
		
	}
	int sum = 0;
	while(!st.empty()){
		sum+=st.top();
		st.pop();
	}
	
	cout << sum << '\n';
	return 0;
}
