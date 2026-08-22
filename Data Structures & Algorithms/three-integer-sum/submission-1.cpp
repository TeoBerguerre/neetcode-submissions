class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> _results;

        const int size = nums.size();
        _results.reserve(size / 3);
        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int baseElement = nums[i];
            int j = i + 1;
            int k = size - 1;
            while (j < k) {
                const int result = baseElement + nums[j] + nums[k];
                if (result == 0) {
                    _results.push_back({baseElement, nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                } else if (result < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return _results;
    }
};
