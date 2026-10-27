class Solution {
    public:
    vector<int> par;
    int find(int x) { while (par[x] != x) { par[x] = par[par[x]]; x = par[x]; } return x; }
    int mst(int n, vector<vector<int>>& e, int skip, int force) {
    par.assign(n, 0);
    for (int i = 0; i < n; i++) par[i] = i;
    int w = 0, used = 0;
    if (force >= 0) { par[find(e[force][0])] = find(e[force][1]); w += e[force][2]; used++; }
    for (int i = 0; i < (int)e.size(); i++) {
    if (i == skip) continue;
    int a = find(e[i][0]), b = find(e[i][1]);
    if (a == b) continue;
    par[a] = b; w += e[i][2]; used++;
    }
    return used == n - 1 ? w : INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    for (int i = 0; i < (int)edges.size(); i++) edges[i].push_back(i);
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
    int base = mst(n, edges, -1, -1);
    vector<int> crit, pseudo;
    for (int i = 0; i < (int)edges.size(); i++) {
    if (mst(n, edges, i, -1) > base) crit.push_back(edges[i][3]);
    else if (mst(n, edges, -1, i) == base) pseudo.push_back(edges[i][3]);
    }
    return {crit, pseudo};
    }
    };