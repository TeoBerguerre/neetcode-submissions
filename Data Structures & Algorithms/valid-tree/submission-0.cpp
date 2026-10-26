class Solution {
    public:
    vector<int> par;
    int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }
    bool validTree(int n, vector<vector<int>>& edges) {
    if ((int)edges.size() != n - 1) return false;
    par.resize(n);
    for (int i = 0; i < n; i++) par[i] = i;
    for (auto& e : edges) {
    int a = find(e[0]), b = find(e[1]);
    if (a == b) return false;
    par[a] = b;
    }
    return true;
    }
    };