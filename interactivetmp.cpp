#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define v vector

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;
#define LOCAL

int second_max(int lo, int hi){
	assert(lo < hi);
	vector<int> b(hi - lo + 1);
	iota(b.begin(), b.end(), lo - 1);
	ranges::sort(b, [&](int i, int j){ return a[i] > a[j]; });
	return b[1] + 1;
}

int query(int lo, int hi){
	cout << "? " << lo << " " << hi << endl;
#ifdef LOCAL
	assert(lo < hi);
	int i = second_max(lo, hi);
	cout << "Reply: " << i << endl;
	return i;
#else
	int x;
	cin >> x;
	return x;
#endif
}
void answer(int pos){
	cout << "! " << pos << endl;
#ifdef LOCAL
	int ans = second_max(1, n);
	cout << "Answer is " << ans << endl;
	assert(pos == ans);
#else

#endif
}

void Wasif() {
    // Code here
	// binary search!!!
	//my array
	// 4 3 2 1 5
#ifdef LOCAL
	n = RNG() % 10 + 2;
	a.resize(n);
	iota(a.begin(), a.end(), 1);
	ranges::shuffle(a, RNG);
	cout << "Current Test\n";
	cout << n << "\n";
	ranges::copy(a, ostream_iterator<int>(cout, " "));
	cout << endl << endl;
#else
	int n;
	cin >> n;
#endif
	int lo = 1, hi = n;
	while(hi > lo + 1){
		int m = query(lo, hi);
		int md = (lo + hi) / 2;
		if(m > md){
		    int mm = query(md+1, hi);
		    if(mm == m) lo = md;
		    else hi = md;
		}
		else{
		    int mm = query(lo, md);
		    if(mm == m) hi = md;
		    else lo = md;
		}
	}
	//cout << lo << " " << hi << endl;
	if(hi == lo){
		answer(lo);
		return;
	}
	int m = query(lo, hi);
	if(m == lo) answer(hi);
	else answer(lo);
}

signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 10;
    //cin >> t;
    while (t--) {
        Wasif();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
