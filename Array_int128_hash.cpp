struct ArrayHash128 {
    using u128 = unsigned __int128;
    using u64  = uint64_t;

    // You must choose primes here:
    static constexpr u64 p1 = 1000000000000000003ULL; // base1 > max a[i]
    static constexpr u64 m1 = 1000000000000000009ULL; // mod1 > p1

    static constexpr u64 p2 = 1000000000000000033ULL; // base2 > max a[i]
    static constexpr u64 m2 = 1000000000000000087ULL; // mod2 > p2

    // prefix hashes and powers for both hash-pairs
    std::vector<u64> pref1, pw1;
    std::vector<u64> pref2, pw2;

    // Build in O(n)
    void build(const std::vector<u64>& a) {
        int n = int(a.size());
        pref1.assign(n+1, 0);
        pw1  .assign(n+1, 0);
        pref2.assign(n+1, 0);
        pw2  .assign(n+1, 0);

        pw1[0] = pw2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw1[i] = (u128(pw1[i-1]) * p1) % m1;
            pw2[i] = (u128(pw2[i-1]) * p2) % m2;
        }

        for (int i = 0; i < n; i++) {
            // shift values by +1 so zeroes don't collapse
            u64 v = a[i] + 1;
            pref1[i+1] = (u128(pref1[i]) * p1 + v) % m1;
            pref2[i+1] = (u128(pref2[i]) * p2 + v) % m2;
        }
    }

    // O(1) substring-hash [i..j], returns {h1,h2}
    std::pair<u64,u64> getHash(int i, int j) const {
        int len = j - i + 1;

        u64 x1 = pref1[j+1] + m1 - u128(pref1[i]) * pw1[len] % m1;
        if (x1 >= m1) x1 -= m1;

        u64 x2 = pref2[j+1] + m2 - u128(pref2[i]) * pw2[len] % m2;
        if (x2 >= m2) x2 -= m2;

        return {x1, x2};
    }
};
