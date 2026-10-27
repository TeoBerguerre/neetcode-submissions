class Solution {
    public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<int> best(n, INT_MAX);
    vector<char> in(n, 0);
    best[0] = 0;
    int total = 0;
    for (int it = 0; it < n; it++) {
    int u = -1;
    for (int i = 0; i < n; i++) if (!in[i] && (u == -1 || best[i] < best[u])) u = i;
    in[u] = 1; total += best[u];
    for (int v = 0; v < n; v++) if (!in[v]) best[v] = min(best[v], abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]));
    }
    return total;
    }
    };