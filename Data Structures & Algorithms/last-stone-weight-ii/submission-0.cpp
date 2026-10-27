class Solution {
    public:
    int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int s : stones) sum += s;
    int half = sum / 2;
    vector<char> dp(half + 1, 0);
    dp[0] = 1;
    for (int s : stones) for (int t = half; t >= s; t--) if (dp[t - s]) dp[t] = 1;
    for (int t = half; t >= 0; t--) if (dp[t]) return sum - 2 * t;
    return sum;
    }
    };