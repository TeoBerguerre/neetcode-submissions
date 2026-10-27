class Solution {
    public:
    vector<int> topo(int k, vector<vector<int>>& conds) {
    vector<vector<int>> adj(k + 1);
    vector<int> indeg(k + 1, 0), order;
    for (auto& c : conds) { adj[c[0]].push_back(c[1]); indeg[c[1]]++; }
    queue<int> q;
    for (int i = 1; i <= k; i++) if (!indeg[i]) q.push(i);
    while (!q.empty()) { int u = q.front(); q.pop(); order.push_back(u); for (int v : adj[u]) if (--indeg[v] == 0) q.push(v); }
    if ((int)order.size() != k) return {};
    return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    auto rows = topo(k, rowConditions), cols = topo(k, colConditions);
    if (rows.empty() || cols.empty()) return {};
    vector<int> rpos(k + 1), cpos(k + 1);
    for (int i = 0; i < k; i++) { rpos[rows[i]] = i; cpos[cols[i]] = i; }
    vector<vector<int>> m(k, vector<int>(k, 0));
    for (int v = 1; v <= k; v++) m[rpos[v]][cpos[v]] = v;
    return m;
    }
    };