class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (size_t i = 0; i < nums.size(); i++)
            if (k == 0 || nums[i] != nums[k - 1]) nums[k++] = nums[i];
        return k;
    }
};