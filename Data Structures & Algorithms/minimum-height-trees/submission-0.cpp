class Solution {
    public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); deg[e[0]]++; deg[e[1]]++; }
    vector<int> leaves;
    for (int i = 0; i < n; i++) if (deg[i] == 1) leaves.push_back(i);
    int remaining = n;
    while (remaining > 2) {
    remaining -= leaves.size();
    vector<int> next;
    for (int u : leaves) for (int v : adj[u]) if (--deg[v] == 1) next.push_back(v);
    leaves = next;
    }
    return leaves;
    }
    };