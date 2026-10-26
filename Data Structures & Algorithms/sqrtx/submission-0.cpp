class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0, hi = x;
        while (lo < hi) {
            long long m = (lo + hi + 1) / 2;
            if (m * m <= x) lo = m; else hi = m - 1;
        }
        return (int)lo;
    }
};