class Solution {
    public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    int R = heights.size(), C = heights[0].size();
    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    dist[0][0] = 0; pq.push({0, 0, 0});
    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
    auto [d, r, c] = pq.top(); pq.pop();
    if (d > dist[r][c]) continue;
    if (r == R - 1 && c == C - 1) return d;
    for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
    int nd = max(d, abs(heights[nr][nc] - heights[r][c]));
    if (nd < dist[nr][nc]) { dist[nr][nc] = nd; pq.push({nd, nr, nc}); }
    }
    }
    return 0;
    }
    };