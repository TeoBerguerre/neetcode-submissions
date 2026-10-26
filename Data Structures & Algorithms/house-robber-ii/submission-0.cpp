class Solution {
    public:
    int robRange(vector<int>& nums, int lo, int hi) {
    int a = 0, b = 0;
    for (int i = lo; i < hi; i++) { int c = max(b, a + nums[i]); a = b; b = c; }
    return b;
    }
    int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robRange(nums, 0, n - 1), robRange(nums, 1, n));
    }
    };