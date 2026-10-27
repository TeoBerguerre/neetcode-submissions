class Solution {
    public:
    int maxArea(vector<int>& heights) {
    int l = 0, r = (int)heights.size() - 1, best = 0;
    while (l < r) {
    best = max(best, (r - l) * min(heights[l], heights[r]));
    if (heights[l] < heights[r]) l++; else r--;
    }
    return best;
    }
    };