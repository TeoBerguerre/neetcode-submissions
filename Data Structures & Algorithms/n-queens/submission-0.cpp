class Solution {
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> cols, d1, d2;
    void go(int r, int n) {
        if (r == n) { res.push_back(board); return; }
        for (int c = 0; c < n; c++) {
            if (cols[c] || d1[r + c] || d2[r - c + n - 1]) continue;
            cols[c] = d1[r + c] = d2[r - c + n - 1] = true; board[r][c] = 'Q';
            go(r + 1, n);
            cols[c] = d1[r + c] = d2[r - c + n - 1] = false; board[r][c] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear(); board.assign(n, string(n, '.'));
        cols.assign(n, false); d1.assign(2 * n, false); d2.assign(2 * n, false);
        go(0, n);
        return res;
    }
};