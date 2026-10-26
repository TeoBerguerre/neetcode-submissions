class Solution {
    public:
    int orangesRotting(vector<vector<int>>& grid) {
    int R = grid.size(), C = grid[0].size(), fresh = 0, t = 0;
    queue<pair<int,int>> q;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
    if (grid[r][c] == 2) q.push({r, c});
    else if (grid[r][c] == 1) fresh++;
    }
    int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
    while (!q.empty() && fresh > 0) {
    int sz = q.size();
    while (sz--) {
    auto [r, c] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
    int nr = r + dr[k], nc = c + dc[k];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C || grid[nr][nc] != 1) continue;
    grid[nr][nc] = 2; fresh--; q.push({nr, nc});
    }
    }
    t++;
    }
    return fresh == 0 ? t : -1;
    }
    };