class Solution {
    Node* build(vector<vector<int>>& g, int r, int c, int n) {
        bool same = true;
        for (int i = r; i < r + n && same; i++)
            for (int j = c; j < c + n; j++)
                if (g[i][j] != g[r][c]) { same = false; break; }
        if (same) return new Node(g[r][c] == 1, true);
        int h = n / 2;
        return new Node(true, false, build(g, r, c, h), build(g, r, c + h, h), build(g, r + h, c, h), build(g, r + h, c + h, h));
    }
public:
    Node* construct(vector<vector<int>>& grid) { return build(grid, 0, 0, grid.size()); }
};