class Solution {
    public:
    void setZeroes(vector<vector<int>>& matrix) {
    int R = matrix.size(), C = matrix[0].size();
    vector<char> rows(R, 0), cols(C, 0);
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) if (matrix[r][c] == 0) rows[r] = cols[c] = 1;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) if (rows[r] || cols[c]) matrix[r][c] = 0;
    }
    };