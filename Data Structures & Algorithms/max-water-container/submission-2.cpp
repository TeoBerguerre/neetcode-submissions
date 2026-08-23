class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int baseArea = (right - left);
            int minHeight = std::min(heights[left], heights[right]);
            maxArea = std::max(maxArea, baseArea * minHeight);
            if (heights[left] <= heights[right]) {
                    left++;
            }else {
                right--;
            }
        }
        return maxArea;
    }
};
