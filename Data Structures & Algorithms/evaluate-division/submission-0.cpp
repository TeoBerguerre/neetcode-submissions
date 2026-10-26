class Solution {
    public:
    unordered_map<string, vector<pair<string, double>>> g;
    double dfs(const string& cur, const string& dst, unordered_set<string>& vis) {
    if (cur == dst) return 1.0;
    vis.insert(cur);
    for (auto& [nx, w] : g[cur]) {
    if (vis.count(nx)) continue;
    double r = dfs(nx, dst, vis);
    if (r > 0) return r * w;
    }
    return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (size_t i = 0; i < equations.size(); i++) {
    g[equations[i][0]].push_back({equations[i][1], values[i]});
    g[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
    }
    vector<double> res;
    for (auto& q : queries) {
    if (!g.count(q[0]) || !g.count(q[1])) { res.push_back(-1.0); continue; }
    unordered_set<string> vis;
    res.push_back(dfs(q[0], q[1], vis));
    }
    return res;
    }
    };