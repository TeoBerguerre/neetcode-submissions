class Solution {
    public:
    int dfs(vector<vector<int>>& g, int r, int c) {
    if (r < 0 || c < 0 || r >= (int)g.size() || c >= (int)g[0].size() || g[r][c] != 1) return 0;
    g[r][c] = 0;
    return 1 + dfs(g, r + 1, c) + dfs(g, r - 1, c) + dfs(g, r, c + 1) + dfs(g, r, c - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int best = 0;
    for (int r = 0; r < (int)grid.size(); r++)
    for (int c = 0; c < (int)grid[0].size(); c++)
    best = max(best, dfs(grid, r, c));
    return best;
    }
    };