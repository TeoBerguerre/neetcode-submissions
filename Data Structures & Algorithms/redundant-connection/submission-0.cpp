class Solution {
    public:
    vector<int> par;
    int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    par.resize(edges.size() + 1);
    for (size_t i = 0; i < par.size(); i++) par[i] = i;
    for (auto& e : edges) {
    int a = find(e[0]), b = find(e[1]);
    if (a == b) return e;
    par[a] = b;
    }
    return {};
    }
    };