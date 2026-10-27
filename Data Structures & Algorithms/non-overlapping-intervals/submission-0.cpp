class Solution {
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
    int removed = 0, end = INT_MIN;
    for (auto& iv : intervals) {
    if (iv[0] >= end) end = iv[1];
    else removed++;
    }
    return removed;
    }
    };