class Solution {
    public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
    int R = grid.size(), C = grid[0].size();
    queue<pair<int,int>> q;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) if (grid[r][c] == 0) q.push({r, c});
    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C || grid[nr][nc] != INT_MAX) continue;
    grid[nr][nc] = grid[r][c] + 1;
    q.push({nr, nc});
    }
    }
    }
    };