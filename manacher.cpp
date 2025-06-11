#include<bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
#define pb push_back  
#define mp make_pair
#define int long long

struct manacher{
	vector<int> p;

	void run_manacher(string t){
		int n = t.length();
		p.assign(n, 1);
		int l = 1, r = 1;
		for(int i = 0; i < n; i++){
			p[i] = max(0LL, min(r - i, p[r + l - i]));
			while(i - p[i] >= 0 && p[i] + i < n && t[i - p[i]] == t[i + p[i]]){
				p[i]++;
			}
			if(i + p[i] > r){
				l = i - p[i], r = p[i] + i;
			}
		}
	}
	// call for building the p array
	// manacher.build(str)
	void build(string s){
		string t;
		for(auto x: s){
			t += string("#") + x;
		}
		run_manacher(t +"#");
	}
	//tells the longest palindrome starting at position center in the original string
	//if its even we have to add a 1 to get the '#' in between
	int getLongestPalindrome(int center, bool odd){
		int position = 2*center + 1 + (!odd);
		return p[position] - 1;
	}
	// longest palindrome from the center of range should be greater than or equal to the size of the interval
	bool isPalindrome(int l, int r){
		if((r - l + 1) <= getLongestPalindrome((r+l) / 2, r % 2 == l % 2)){
			return 1;
		}
		return 0;
	}

}manacher;

signed main(){
	string str;
	cin >> str;
	manacher.build(str);
}
