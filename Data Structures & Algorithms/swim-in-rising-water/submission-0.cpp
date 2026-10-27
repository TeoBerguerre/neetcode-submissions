class Solution {
    public:
    int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<char>> seen(n, vector<char>(n, 0));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({grid[0][0], 0, 0}); seen[0][0] = 1;
    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
    auto [t, r, c] = pq.top(); pq.pop();
    if (r == n - 1 && c == n - 1) return t;
    for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr < 0 || nc < 0 || nr >= n || nc >= n || seen[nr][nc]) continue;
    seen[nr][nc] = 1;
    pq.push({max(t, grid[nr][nc]), nr, nc});
    }
    }
    return -1;
    }
    };