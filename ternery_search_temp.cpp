#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
// using namespace __gnu_pbds;

#define int long long
#define pb push_back
typedef long long ll;
typedef std::pair<ll, ll> pii;
typedef long double ld;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key :- count of elements smaller
// find_by_order :- returns kth largest element from 0. 1st largest element in {1, 2} is 2
#define all(x) x.begin(), x.end()

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i] << " ";
    }
    return os;
}

template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	for (auto it = v.begin(); it != v.end(); ++it)
		fin >> *it;
	return fin;
}

const ld eps = 1e-6;
const int mod = 1e9+7;

int modpower(int a, int b){
	int ans = 1;
	a %= mod;
	while(b > 0){
		if(b&1){
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int power(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase = 1;
    cin >> testcase;
    while (testcase--) {
        // in mod problems, make sure to check mod value
        auto ternery_search = [&] (int l, int u) -> int{
            int orig = l;
            int r = n - 1;
            while(r > l + 6){
                int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
                int f1 = f(orig, m1, u), f2 = f(orig, m2, u);
                if(f1 < f2) l = m1;
                else r = m2;
            }
            int tmp = f(orig, r, u), ans = r;
            // check the last 6 values manually
            for(int i = r; i >= l; i--){
                if(f(orig, i, u) >= tmp){
                    tmp = f(orig, i, u); ans = i;
                }
            }
            return ans;
        };
    }
}
