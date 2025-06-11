#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class BitTrie{
public:
    struct Node{
        Node* children[2] = {};
        int cnt = 0;
        Node() : children{nullptr, nullptr}, cnt(0) {}
    };

    Node *root;

    BitTrie() {
        root = new Node();
    }

    void insert(int x) {
        Node *cur = root;
        for(int j = 30; j >= 0; j--) {
            bool bit = (1 << j) & x;
            if(cur->children[bit] == nullptr) {
                cur->children[bit] = new Node();
            }
            cur = cur->children[bit];
            cur->cnt++;
        }
    }

    void remove(int x) {
        Node *cur = root;
        for(int j = 30; j >= 0; j--) {
            bool bit = (1 << j) & x;
            Node* tmp = cur->children[bit];
            tmp->cnt--;
            if(tmp->cnt == 0) {
                deleteSubtree(tmp);
                cur->children[bit] = nullptr;
                return;
            }
            cur = tmp;
        }
    }

    int query(int x) {
        int ans = 0;
        Node *cur = root;
        for(int j = 30; j >= 0; j--) {
            bool bit = (1 << j) & x;
            if(cur->children[!bit]) {
                ans |= (1 << j);
                cur = cur->children[!bit];
            } else {
                cur = cur->children[bit];
            }
        }
        return ans;
    }

    ~BitTrie() {
        deleteSubtree(root);
    }

private:
    void deleteSubtree(Node* p) {
        if(!p) return;
        deleteSubtree(p->children[0]);
        deleteSubtree(p->children[1]);
        delete p;
    }
};

int main(){
    BitTrie trie;
    trie.insert(2);
    trie.insert(3);
    trie.insert(4);
    trie.query(1); // 4^1 = 5
    trie.remove(4);  // 4 is removed
    trie.query(1); // 2^1 = 3 
}
