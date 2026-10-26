class Solution {
    public:
    int maxProduct(vector<int>& nums) {
    int best = nums[0], hi = 1, lo = 1;
    for (int x : nums) {
    int a = hi * x, b = lo * x;
    hi = max({x, a, b}); lo = min({x, a, b});
    best = max(best, hi);
    }
    return best;
    }
    };