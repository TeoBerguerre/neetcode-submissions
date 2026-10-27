class Solution {
    public:
    int maxSubarraySumCircular(vector<int>& nums) {
    int total = 0, curMax = 0, curMin = 0, best = nums[0], worst = nums[0];
    for (int x : nums) {
    curMax = max(x, curMax + x); best = max(best, curMax);
    curMin = min(x, curMin + x); worst = min(worst, curMin);
    total += x;
    }
    return best < 0 ? best : max(best, total - worst);
    }
    };