class Solution {
    public:
    int maxProfit(vector<int>& prices) {
    int lo = INT_MAX, best = 0;
    for (int p : prices) { lo = min(lo, p); best = max(best, p - lo); }
    return best;
    }
    };