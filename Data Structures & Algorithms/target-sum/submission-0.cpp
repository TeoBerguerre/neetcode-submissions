class Solution {
    public:
    int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<int, int> dp{{0, 1}};
    for (int x : nums) {
    unordered_map<int, int> nx;
    for (auto& [s, c] : dp) { nx[s + x] += c; nx[s - x] += c; }
    dp = nx;
    }
    return dp[target];
    }
    };