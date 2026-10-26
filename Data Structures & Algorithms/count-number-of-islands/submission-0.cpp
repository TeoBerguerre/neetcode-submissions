class Solution {
    public:
    void dfs(vector<vector<char>>& g, int r, int c) {
    if (r < 0 || c < 0 || r >= (int)g.size() || c >= (int)g[0].size() || g[r][c] != '1') return;
    g[r][c] = '0';
    dfs(g, r + 1, c); dfs(g, r - 1, c); dfs(g, r, c + 1); dfs(g, r, c - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
    int n = 0;
    for (int r = 0; r < (int)grid.size(); r++)
    for (int c = 0; c < (int)grid[0].size(); c++)
    if (grid[r][c] == '1') { n++; dfs(grid, r, c); }
    return n;
    }
    };