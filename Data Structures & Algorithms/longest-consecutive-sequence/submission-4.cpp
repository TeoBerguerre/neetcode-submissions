class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int result = 1;
        std::sort(nums.begin(), nums.end());

        int maxSubSeq = 1;
        // 2, 3, 4, 4, 5, 10, 20, 21
        // 0, 1, 1, 2, 3, 4, 5, 6
        for (int i = 0; i < nums.size() - 1; i++) {
            int nextElementValue = nums[i + 1];
            int currentElementValue = nums[i];

            if (currentElementValue == nextElementValue) {
                continue;
            }
            if (currentElementValue + 1 == nextElementValue) {
                maxSubSeq += 1;
            } else {
                if (maxSubSeq > result) {
                    result = maxSubSeq;
                }
                maxSubSeq = 1;
            }
            if (maxSubSeq > result) {
                result = maxSubSeq;
            }
        }

        return result;
    }
};
