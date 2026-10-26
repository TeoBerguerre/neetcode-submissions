class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size(), p = 0;
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) if (grid[r][c]) {
                p += 4;
                if (r > 0 && grid[r - 1][c]) p -= 2;
                if (c > 0 && grid[r][c - 1]) p -= 2;
            }
        return p;
    }
};