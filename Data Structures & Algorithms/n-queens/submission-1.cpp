class Solution {
    public:
    vector<vector<string>> res;
    vector<char> col, d1, d2;
    void go(int r, int n, vector<string>& b) {
    if (r == n) { res.push_back(b); return; }
    for (int c = 0; c < n; c++) {
    if (col[c] || d1[r + c] || d2[r - c + n]) continue;
    col[c] = d1[r + c] = d2[r - c + n] = 1; b[r][c] = 'Q';
    go(r + 1, n, b);
    col[c] = d1[r + c] = d2[r - c + n] = 0; b[r][c] = '.';
    }
    }
    vector<vector<string>> solveNQueens(int n) {
    col.assign(n, 0); d1.assign(2 * n, 0); d2.assign(2 * n + 1, 0);
    vector<string> b(n, string(n, '.'));
    go(0, n, b);
    return res;
    }
    };