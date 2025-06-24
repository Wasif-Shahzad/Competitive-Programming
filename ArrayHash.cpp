struct ArrayHash {
    using ll = int64_t;
 
    // base (must be > max a[i]) and moduli (must be > base)
    static constexpr ll p1 = 1000000007;     // base for hash1
    static constexpr ll m1 = 1000000009;     // modulus for hash1
 
    static constexpr ll p2 = 1000000033;     // base for hash2
    static constexpr ll m2 = 1000000087;     // modulus for hash2
 
    // prefix hashes and powers
    std::vector<ll> pref1, pref2, pw1, pw2;
 
    // build in O(n)
    void build(const std::vector<int>& a) {
        int n = a.size();
        pref1.assign(n+1, 0);
        pref2.assign(n+1, 0);
        pw1 .assign(n+1, 0);
        pw2 .assign(n+1, 0);
 
        pw1[0] = pw2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw1[i] = (pw1[i-1] * p1) % m1;
            pw2[i] = (pw2[i-1] * p2) % m2;
        }
 
        for (int i = 0; i < n; i++) {
            // we add +1 so that zero-values don't collapse prefixes
            ll v = ll(a[i]) + 1;
            pref1[i+1] = (pref1[i] * p1 + v) % m1;
            pref2[i+1] = (pref2[i] * p2 + v) % m2;
        }
    }
 
    // get hash of a[i..j] in O(1)
    std::pair<ll,ll> getHash(int i, int j) const {
        ll len = j - i + 1;
 
        ll x1 = pref1[j+1]
              - (pref1[i] * pw1[len]) % m1;
        if (x1 < 0) x1 += m1;
 
        ll x2 = pref2[j+1]
              - (pref2[i] * pw2[len]) % m2;
        if (x2 < 0) x2 += m2;
 
        return {x1, x2};
    }
};
