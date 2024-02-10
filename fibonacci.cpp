#include <bits/stdc++.h>

using namespace std;

#define prodmod(a, b, m) ((a % m) * (b % m)) % m

const int M = 1000000007;

struct matrix{
	long long mat[2][2];
	matrix friend operator*(const matrix &a, const matrix &b){
		matrix c;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				c.mat[i][j] = 0;
				for(int k = 0; k < 2; k++){
					c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
					c.mat[i][j] %= M;
				}
			}
		}
		return c;
	}
};

matrix matpow(matrix a, long long n){
	matrix ans = {{{1, 0}, {0, 1}}};
	while(n){
		int res = 1;
		if(n&1){
			ans = ans * a;
		}
		a = a*a;
		n >>= 1;
	}
	return ans;
}

long long fib(long long n){
	matrix base = {{
		{1, 1},
		{1, 0}
	}};
	return matpow(base, n).mat[0][1] % M;
}

int main(){
	long long n;
	cin >> n;
	cout << fib(n) << endl;
}
