class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, i = 0, hi = (int)nums.size() - 1;
        while (i <= hi) {
            if (nums[i] == 0) swap(nums[i++], nums[lo++]);
            else if (nums[i] == 2) swap(nums[i], nums[hi--]);
            else i++;
        }
    }
};