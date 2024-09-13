#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int MOD = 1e9+7, N = 2e5+5;
int facts[N];

int power(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int inverse(int a){
    return power(a, MOD - 2) % MOD;
}

int ncr(int n, int r) {
    if(r > n || r < 0) return 0;
    int ans = facts[n];
    ans = (ans * inverse(facts[r])) % MOD;
    ans = (ans * inverse(facts[n - r])) % MOD;
    return ans;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    facts[0] = 1;
    for(int i = 1; i < N; i++){
        facts[i] = (i * facts[i - 1]) % MOD;
    }
    int t;
    cin >> t;
    while(t--){
        
    }
}
