class Solution {
    public:
    int go(int r, int n, int cols, int d1, int d2) {
    if (r == n) return 1;
    int cnt = 0;
    for (int c = 0; c < n; c++) {
    if ((cols >> c & 1) || (d1 >> (r + c) & 1) || (d2 >> (r - c + n) & 1)) continue;
    cnt += go(r + 1, n, cols | 1 << c, d1 | 1 << (r + c), d2 | 1 << (r - c + n));
    }
    return cnt;
    }
    int totalNQueens(int n) {
    return go(0, n, 0, 0, 0);
    }
    };