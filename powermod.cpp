// Calculates mod after raising one number to another power using binary exponentiation
#include <bits/stdc++.h>

using namespace std;

int power(int a, int b, int m){
	int ans = 1;
	a %= m;
	while(b > 0){
		if(b&1){
			ans = (ans * a) % m;
		}
		a = (a * a) % m;
		b >>= 1;
	}
	return ans;
}

int main(){
	io
	int a, b, m; cin >> a >> b >> m;
	cout << power(a, b, m) << endl;
}
