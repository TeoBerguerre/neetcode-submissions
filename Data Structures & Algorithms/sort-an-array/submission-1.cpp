class Solution {
    public:
    void msort(vector<int>& a, vector<int>& tmp, int l, int r) {
    if (r - l < 2) return;
    int m = (l + r) / 2;
    msort(a, tmp, l, m); msort(a, tmp, m, r);
    int i = l, j = m, k = l;
    while (i < m || j < r) tmp[k++] = (j >= r || (i < m && a[i] <= a[j])) ? a[i++] : a[j++];
    for (int t = l; t < r; t++) a[t] = tmp[t];
    }
    vector<int> sortArray(vector<int>& nums) {
    vector<int> tmp(nums.size());
    msort(nums, tmp, 0, nums.size());
    return nums;
    }
    };