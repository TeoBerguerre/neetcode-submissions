class Solution {
    public:
    long long minEnd(int n, int x) {
    long long res = x, m = n - 1;
    for (long long bit = 1; m > 0; bit <<= 1) {
    if (!(res & bit)) { if (m & 1) res |= bit; m >>= 1; }
    }
    return res;
    }
    };