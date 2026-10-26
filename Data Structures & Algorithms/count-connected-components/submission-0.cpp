class Solution {
    public:
    vector<int> par;
    int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }
    int countComponents(int n, vector<vector<int>>& edges) {
    par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;
    int comps = n;
    for (auto& e : edges) {
    int a = find(e[0]), b = find(e[1]);
    if (a != b) { par[a] = b; comps--; }
    }
    return comps;
    }
    };