class Solution {
    public:
    int splitArray(vector<int>& nums, int k) {
    long long l = *max_element(nums.begin(), nums.end()), r = 0;
    for (int x : nums) r += x;
    while (l < r) {
    long long m = (l + r) / 2, sum = 0;
    int parts = 1;
    for (int x : nums) { if (sum + x > m) { parts++; sum = 0; } sum += x; }
    if (parts <= k) r = m; else l = m + 1;
    }
    return l;
    }
    };