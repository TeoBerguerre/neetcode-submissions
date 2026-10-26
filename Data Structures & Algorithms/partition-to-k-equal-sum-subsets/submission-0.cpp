class Solution {
    bool go(vector<int>& a, int i, vector<int>& buckets, int target) {
        if (i == (int)a.size()) return true;
        for (int b = 0; b < (int)buckets.size(); b++) {
            if (buckets[b] + a[i] > target) continue;
            bool seen = false;
            for (int t = 0; t < b; t++) if (buckets[t] == buckets[b]) { seen = true; break; }
            if (seen) continue;
            buckets[b] += a[i];
            if (go(a, i + 1, buckets, target)) return true;
            buckets[b] -= a[i];
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        sort(nums.rbegin(), nums.rend());
        vector<int> buckets(k, 0);
        return go(nums, 0, buckets, sum / k);
    }
};