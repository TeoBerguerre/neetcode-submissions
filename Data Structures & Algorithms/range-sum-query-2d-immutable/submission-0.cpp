class NumMatrix {
    vector<vector<int>> p;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        p.assign(R + 1, vector<int>(C + 1, 0));
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                p[r + 1][c + 1] = matrix[r][c] + p[r][c + 1] + p[r + 1][c] - p[r][c];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return p[row2 + 1][col2 + 1] - p[row1][col2 + 1] - p[row2 + 1][col1] + p[row1][col1];
    }
};