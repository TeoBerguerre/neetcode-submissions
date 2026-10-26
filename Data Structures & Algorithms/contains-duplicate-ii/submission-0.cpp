class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> win;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > k) win.erase(nums[i - k - 1]);
            if (!win.insert(nums[i]).second) return true;
        }
        return false;
    }
};