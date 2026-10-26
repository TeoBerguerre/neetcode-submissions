class Solution {
    public:
    int R, C;
    void dfs(vector<vector<int>>& h, vector<vector<char>>& vis, int r, int c, int prev) {
    if (r < 0 || c < 0 || r >= R || c >= C || vis[r][c] || h[r][c] < prev) return;
    vis[r][c] = 1;
    dfs(h, vis, r + 1, c, h[r][c]); dfs(h, vis, r - 1, c, h[r][c]);
    dfs(h, vis, r, c + 1, h[r][c]); dfs(h, vis, r, c - 1, h[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    R = heights.size(); C = heights[0].size();
    vector<vector<char>> pac(R, vector<char>(C, 0)), atl(R, vector<char>(C, 0));
    for (int r = 0; r < R; r++) { dfs(heights, pac, r, 0, INT_MIN); dfs(heights, atl, r, C - 1, INT_MIN); }
    for (int c = 0; c < C; c++) { dfs(heights, pac, 0, c, INT_MIN); dfs(heights, atl, R - 1, c, INT_MIN); }
    vector<vector<int>> res;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) if (pac[r][c] && atl[r][c]) res.push_back({r, c});
    return res;
    }
    };