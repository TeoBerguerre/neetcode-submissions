class Solution {
    public:
    vector<int> par;
    int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }
    bool canTraverseAllPairs(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return true;
    par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;
    unordered_map<int, int> owner;
    for (int i = 0; i < n; i++) {
    int x = nums[i];
    if (x == 1) return false;
    for (int p = 2; (long long)p * p <= x; p++) {
    if (x % p) continue;
    while (x % p == 0) x /= p;
    auto it = owner.find(p);
    if (it == owner.end()) owner[p] = i; else par[find(i)] = find(it->second);
    }
    if (x > 1) { auto it = owner.find(x); if (it == owner.end()) owner[x] = i; else par[find(i)] = find(it->second); }
    }
    int root = find(0);
    for (int i = 1; i < n; i++) if (find(i) != root) return false;
    return true;
    }
    };