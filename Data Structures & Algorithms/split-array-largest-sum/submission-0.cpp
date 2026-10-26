class Solution {
    bool ok(vector<int>& nums, int k, long long cap) {
        int parts = 1; long long cur = 0;
        for (int x : nums) {
            if (cur + x > cap) { parts++; cur = 0; }
            cur += x;
        }
        return parts <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long long lo = *max_element(nums.begin(), nums.end());
        long long hi = accumulate(nums.begin(), nums.end(), 0LL);
        while (lo < hi) {
            long long m = (lo + hi) / 2;
            if (ok(nums, k, m)) hi = m; else lo = m + 1;
        }
        return (int)lo;
    }
};