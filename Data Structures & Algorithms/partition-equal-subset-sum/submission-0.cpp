class Solution {
    public:
    bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int x : nums) sum += x;
    if (sum % 2) return false;
    int target = sum / 2;
    vector<char> dp(target + 1, 0);
    dp[0] = 1;
    for (int x : nums)
    for (int t = target; t >= x; t--) if (dp[t - x]) dp[t] = 1;
    return dp[target];
    }
    };