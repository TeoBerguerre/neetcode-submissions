class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int a = 0; a < n; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < n; b++) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                int l = b + 1, r = n - 1;
                while (l < r) {
                    long long s = (long long)nums[a] + nums[b] + nums[l] + nums[r];
                    if (s < target) l++;
                    else if (s > target) r--;
                    else {
                        res.push_back({nums[a], nums[b], nums[l], nums[r]});
                        l++; r--;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                    }
                }
            }
        }
        return res;
    }
};