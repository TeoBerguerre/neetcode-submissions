class Solution {
    public:
    int trap(vector<int>& height) {
    int l = 0, r = (int)height.size() - 1, lm = 0, rm = 0, w = 0;
    while (l < r) {
    if (height[l] < height[r]) { lm = max(lm, height[l]); w += lm - height[l]; l++; }
    else { rm = max(rm, height[r]); w += rm - height[r]; r--; }
    }
    return w;
    }
    };